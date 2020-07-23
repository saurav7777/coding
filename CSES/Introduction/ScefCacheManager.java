package com.rjil.iot.scef.cache;

import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;
import java.util.concurrent.TimeUnit;

import org.apache.logging.log4j.Logger;

import com.rjil.iot.scef.bootstrap.RTJIOSCEFBootstrapServer;
import com.rjil.iot.scef.logging.LoggingManager;
import com.rjil.iot.scef.nidd.NIDDConfigPojo;
import com.rjil.rpc.cluster.ClusterDbException;
import com.rjil.rpc.cluster.RpcClusterManager;

import io.lettuce.core.RedisFuture;

/**
 * A singleton container class to store all the context as cache. provides
 * utility methods to operate upon the data.
 * 
 * @author Kumar1.Singh
 *
 */
public class ScefCacheManager {

	private static final Logger logger = LoggingManager.logger;
	private static final ScefCacheManager INSTANCE = new ScefCacheManager();

	// Monitoring Event context

	// Mapping to store monitoring event configuration data. Key will be
	// subscriptionId.
	private ConcurrentMap<String, MonitoringEventConfPojo> monteMap = new ConcurrentHashMap<String, MonitoringEventConfPojo>();

	// Mapping of SCEF reference ID to TLTRI for MONTE.
	private ConcurrentMap<Long, String> scefRefIdTltriMap = new ConcurrentHashMap<Long, String>();

	// NIDD context

	// Mapping to store NIDD configuration data corresponding to transactionId (of
	// T8).
	private ConcurrentMap<String, NIDDConfigPojo> niddMap = new ConcurrentHashMap<String, NIDDConfigPojo>();

	// Mapping of NIDDConfigPojo corresponding to User-Name(IMSI)+APN OR
	// User-Name(IMSI)+EBI
	// During NIDD configuration when NIDD authorization answer is received, key
	// will be User-Name(IMSI)+APN
	// Once CMR comes from MME, the key will be replaced with IMSI+EBI
	private ConcurrentMap<String, NIDDConfigPojo> epsContextIdTrxIdMap = new ConcurrentHashMap<String, NIDDConfigPojo>();

	// This map is used to store Diameter result codes to http codes.
	private ConcurrentMap<Integer, Integer> diameterhttpmap = new ConcurrentHashMap<>();

	public ConcurrentMap<Integer, Integer> getDiameterhttpmap() {
		return diameterhttpmap;
	}

	private ScefCacheManager() {

	}

	public static ScefCacheManager getInstance() {
		return INSTANCE;
	}

	public MonitoringEventConfPojo getMonteConfData(String subscriptionId) {

		return this.monteMap.get(subscriptionId);
	}

	public void removeMonteConfData(String subscriptionId, boolean cache, boolean database, boolean replicate) {

		// Future listener object for asynchronous commands
		if (database)
			RTJIOSCEFBootstrapServer.getInstance().getAsyncCommands().hdel("HashKey", subscriptionId); // Non-blocking

		// call. // //
		ScefCacheManager.getInstance().getMonteConfData(subscriptionId).setMaxNoOfReports(0);

		MonitoringEventConfPojo pojo = ScefCacheManager.getInstance().getMonteConfData(subscriptionId);

		if (replicate)

		{

			try {
				RpcClusterManager.rpcManager.writeData(pojo);
			} catch (ClusterDbException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

		}
		if (cache) {
			/*
			 * ScefCacheManager.getInstance().removeTltriForScefRefId(pojo.
			 * getScefReferenceId(), cache, database, replicate);
			 */
			this.monteMap.remove(subscriptionId);
		}

	}

	public void storeMonteConfData(String subscriptionId, MonitoringEventConfPojo pojo, boolean cache,
			boolean replicate, boolean database) {
		if (cache) {
			logger.info("Storing in Scef CACHE in MonteMap");
			this.monteMap.put(subscriptionId, pojo);
		}
		if (database) {
			logger.info("Storing SubsID Vs POJO in Database");
			setdatabase(subscriptionId, pojo);
		}
		if (replicate) {
			try {
				RpcClusterManager.rpcManager.writeData(pojo);
			} catch (ClusterDbException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		// this.monteMap.put(subscriptionId, pojo);
	}

	public void putScefRefIdVsTltri(long scefRefId, String tltri, boolean cache, boolean replicate, boolean database) {
		if (cache) {
			logger.info("Storing in Scef CACHE in ScefRefID Vs TLTRI Map");
			this.scefRefIdTltriMap.put(scefRefId, tltri);
		}
		if (database) {
			logger.info("Storing ScefRefID Vs TLTRI in Database");
			setTLTRIinDB(scefRefId, tltri);
		}

	}

	public String getTltriForScefRefId(long scefRefId) {
		return this.scefRefIdTltriMap.get(scefRefId);
	}

	public void removeTltriForScefRefId(long scefRefId, boolean cache, boolean database, boolean replicate) {
		// return this.scefRefIdTltriMap.remove(scefRefId);
		if (database)
			RTJIOSCEFBootstrapServer.getInstance().getAsyncCommands().hdel("scefrefidvsTLtri",
					String.valueOf(scefRefId));
		// Non-blocking
		// call.
		if (cache) // Program
			this.scefRefIdTltriMap.remove(scefRefId);
		// continues

	}

	public void storeNiddConfig(String trxId, NIDDConfigPojo pojo) {
		this.niddMap.put(trxId, pojo);
	}

	public NIDDConfigPojo getNiddConfigData(String trxId) {
		return this.niddMap.get(trxId);
	}

	public NIDDConfigPojo removeNiddConfigData(String trxId) {
		return this.niddMap.remove(trxId);
	}

	public void putNIDDConfigPojoForEpsContextId(String epsContextId, NIDDConfigPojo pojo) {
		this.epsContextIdTrxIdMap.put(epsContextId, pojo);
	}

	public NIDDConfigPojo removeNIDDConfigPojoForEpsContextId(String epsContextId) {
		return this.epsContextIdTrxIdMap.remove(epsContextId);
	}

	public NIDDConfigPojo getNIDDConfigPojo(String epsContextId) {
		return this.epsContextIdTrxIdMap.get(epsContextId);
	}

	public void setdatabase(String subscriptionId, MonitoringEventConfPojo pojo) {
		Boolean response = null;
		RedisFuture<Boolean> redisHashSetFuture;
		// Future listener object for asynchronous commands
		redisHashSetFuture = RTJIOSCEFBootstrapServer.getInstance().getAsyncCommands().hset("HashKey", subscriptionId,
				pojo); // Non-blocking call. Program continues
		// System.out.println("Any task to be done while waiting for the response of
		// async commands");
		try {
			response = redisHashSetFuture.get();// Blocking call. Blocks the calling thread
																	// indefinitely unless timeout is specified
			// System.out.println("Async String Set response:-> "+response);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public void setTLTRIinDB(long scefrefid, String tltri) {
		Boolean response = null;
		RedisFuture<Boolean> redisHashSetFuture;
		// Future listener object for asynchronous commands
		redisHashSetFuture = RTJIOSCEFBootstrapServer.getInstance().getAsyncCommands().hset("scefrefidvsTLtri",
				String.valueOf(scefrefid), tltri); // Non-blocking call. Program continues
		// System.out.println("Any task to be done while waiting for the response of
		// async commands");
		try {
			response = redisHashSetFuture.get();// Blocking call. Blocks the calling thread
																	// indefinitely unless timeout is specified
			// System.out.println("Async String Set response:-> "+response);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
