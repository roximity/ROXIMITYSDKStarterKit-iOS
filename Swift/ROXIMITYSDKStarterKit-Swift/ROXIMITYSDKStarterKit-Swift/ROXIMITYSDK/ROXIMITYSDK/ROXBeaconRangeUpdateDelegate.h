//
//  ROXBeaconRangeUpdateDelegate.h
//  ROXIMITYlib
//
//  Created by dp on 10/1/14.
//  Copyright (c) 2014 ROXIMITY. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ROXBeaconRangeUpdateDelegate <NSObject>

typedef enum{
    kROXBeaconRangeUpdatesFastest,
    kROXBeaconRangeUpdatesBalanced,
    kROXBeaconRangeUpdatesPowerSaving
} ROXBeaconRangeUpdateInterval;

@required
- (void) didUpdateBeaconRanges:(NSArray *)rangedBeacons;

@end
