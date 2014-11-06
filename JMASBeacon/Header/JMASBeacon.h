//
//  JMASBeacon.h
//
//  Created by Akira Hayakawa on 2014/04/02.
//  Copyright (c) 2014年 JMA Systems Corp., All rights reserved.
//

#import <Foundation/Foundation.h>

@import CoreLocation;
@import CoreBluetooth;

#import "JMASBeaconRegion.h"

typedef NS_ENUM(NSUInteger, JMASBeaconMonitoringStatus) {
    kJMASBeaconMonitoringStatusDisabled,
    kJMASBeaconMonitoringStatusStopped,
    kJMASBeaconMonitoringStatusMonitoring
};

#define kJMASBeaconRegionMax     20

#pragma mark Notification's Name
#define kJMASdidUpdatePeripheralState   @"didUpdatePeripheralState"
#define kJMASdidUpdateAuthorizationStatus   @"didUpdateAuthorizationStatus"
#define kJMASdidUpdateMonitoringStatus  @"didUpdateMonitoringStatus"
#define kJMASdidUpdateRegionEnterOrExit @"didUpdateRegionEnterOrExit"
#define kJMASdidRangeBeacons    @"didRangeBeacons"
#define kJMASNoneBeacons    @"noneBeacons"
#define kJMASchangeBeacon   @"changeBeacon"
#define kJMASAllBeaconsFar  @"allBeaconsFar"

#pragma mark - dictionary of keys
#define kPeripheralState @"peripheralState"
#define kAuthorizationStatus @"authorizationStatus"
#define kMonitoringStatus @"monitoringStatus"
#define kJMASBeaconRegion   @"jmasBeaconRegion"
#define kJMASNearestBeacon  @"beacon"

@interface JMASBeacon : NSObject<CBPeripheralManagerDelegate, CLLocationManagerDelegate>
@property (nonatomic) NSMutableArray *regions;
@property (nonatomic, assign) BOOL delegateMode;
@property (nonatomic, weak) id delegate;


@property (nonatomic, assign) BOOL needsBackgroundRanging;
@property (nonatomic, assign) BOOL needsBackgroundTask;

@property (nonatomic) dispatch_queue_t queue;
@property (nonatomic, copy) NSMutableArray * eventArray;

@property (nonatomic) CLLocation* currentLocation;
@property (nonatomic) BOOL availableLocation;

@property (nonatomic) BOOL verboseMode;


+ (JMASBeacon *)sharedManager;
- (BOOL)isMonitoringCapable;
- (void)requestUpdateForStatus;
- (void)startMonitoring;
- (void)stopMonitoring;
- (JMASBeaconRegion *)registerRegion:(NSString *)UUIDString identifier:(NSString *)identifier;
- (JMASBeaconRegion *)registerRegion:(NSString *)UUIDString major:(CLBeaconMajorValue)major identifier:(NSString *)identifier;
- (JMASBeaconRegion *)registerRegion:(NSString *)UUIDString major:(CLBeaconMajorValue)major minor:(CLBeaconMinorValue)minor identifier:(NSString *)identifier;
- (void)unregisterAllRegion;
-(BOOL)startLocationService;
-(void)stopLocationService;


#pragma mark - iBeaconSend
-(BOOL)startBeaconSend:(NSString*)UUIDString major:(CLBeaconMajorValue)major minor:(CLBeaconMinorValue)minor identifier:(NSString*)identifier;

-(BOOL)startBeaconSend:(NSString*)UUIDString major:(CLBeaconMajorValue)major minor:(CLBeaconMinorValue)minor identifier:(NSString*)identifier AndMesuredPower:(NSNumber*)power;
-(void)stopBeaconSend;
-(BOOL)beaconSending;

@end


@protocol JMASBeaconDelegate <NSObject>
@optional

-(void)didUpdateRegionEnterOrExit:(JMASBeaconRegion*)region;
-(void)didUpdateMonitoringStatus:(JMASBeaconMonitoringStatus)monitoringStatus;
-(void)didUpdatePeripheralState:(CBPeripheralManagerState)peripheralState;
-(void)didUpdateAuthorizationStatus:(CLAuthorizationStatus)authrizationStatus;
-(void)didRangeBeacons:(JMASBeaconRegion*)region;
-(void)changeBeacon:(CLBeacon*)beacon;
-(void)allBeaconsFar;
-(void)noneBeacons;
-(void)jmasBeaconLocationManager:(CLLocationManager*)locationMangaer monitoringDidFailForRegion:(CLRegion *)region withError:(NSError *)error;
-(void)jmasBeaconLocationManager:(CLLocationManager *)locationMangaer rangingBeaconsDidFailForRegion:(CLBeaconRegion *)region withError:(NSError *)error;
-(void)jmasBeaconLocationManager:(CLLocationManager *)manager didFailWithError:(NSError *)error;


@end
