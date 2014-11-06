//
//  JMASBeaconRegion.h
//
//  Created by Akira Hayakawa on 2014/04/02.
//  Copyright (c) 2014年 JMA Systems Corp., All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#define JMASBeaconRegionFailCountMax   3
@interface JMASBeaconRegion : CLBeaconRegion
@property (nonatomic) BOOL rangingEnabled;
@property (nonatomic) BOOL isMonitoring;
@property (nonatomic) BOOL hasEntered;
@property (nonatomic) BOOL isRanging;
@property (nonatomic) NSUInteger failCount;
@property (nonatomic) NSArray *beacons;
- (void)clearFlags;

@end
