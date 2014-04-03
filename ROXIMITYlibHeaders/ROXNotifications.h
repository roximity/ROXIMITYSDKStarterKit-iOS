//
//  ROXIMITYNotifications.h
//  ROXIMITYlib
//
//  Created by Danny Pier on 9/18/13.
//  Copyright (c) 2013 ROXIMITY. All rights reserved.
//

/**
 @brief The ROXIMITYNotifications class
 */
#import <Foundation/Foundation.h>

@interface ROXNotifications : NSObject

extern NSString * const kROXEngineOptionsReservedRegions;

extern NSString * const kROXDeviceStateNotification;
extern NSString * const kROXRoximityLocalNotification;
extern NSString * const kROXRoximityRemoteNotification;
extern NSString * const kROXRoximityTriggerNotification;
extern NSString * const kROXRoximityTriggeredBeaconNotification;

extern NSString * const ROX_NOTIF_BEACON_RANGE_UPDATE;
extern NSString * const ROX_NOTIF_REGION_ENTERED;
extern NSString * const ROX_NOTIF_REGION_EXITED;
extern NSString * const ROX_NOTIF_BLUETOOTH_OFF;
extern NSString * const ROX_NOTIF_MESSAGE_FIRED;

extern NSString * const ROX_BEACON_RANGE_KEY_BEACON_ID;
extern NSString * const ROX_BEACON_RANGE_KEY_BEACON_NAME;
extern NSString * const ROX_BEACON_RANGE_KEY_BEACON_TAGS;
extern NSString * const ROX_BEACON_RANGE_KEY_PROXIMITY_VALUE;
extern NSString * const ROX_BEACON_RANGE_KEY_PROXIMITY_STRING;


@end
