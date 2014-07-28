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

#pragma mark - Engine Options

extern NSString * const kROXEngineOptionsReservedRegions;
extern NSString * const kROXEngineOptionsMuteBluetoothOffAlert;
extern NSString * const kROXEngineOptionsMuteRequestAlerts;
extern NSString * const kROXEngineOptionsStartLocationDeactivated;

#pragma mark - Notification Observer Constants

extern NSString * const kROXDeviceStateNotification;
extern NSString * const kROXRoximityLocalNotification;
extern NSString * const kROXRoximityPushNotification;
extern NSString * const kROXRoximityActionNotification;
extern NSString * const kROXRoximityTriggerNotification;
extern NSString * const kROXBeaconRangeUpdated;
extern NSString * const kROXMessageFired;
extern NSString * const kROXWebhookPosted;
extern NSString * const kROXGeofenceAdded;
extern NSString * const kROXAliasSetSuccess;
extern NSString * const kROXAliasSetFailure;

#pragma mark - Notification Keys

extern NSString * const kROXNotifBeaconId;
extern NSString * const kROXNotifBeaconName;
extern NSString * const kROXNotifBeaconTags;
extern NSString * const kROXNotifBeaconProximityValue;
extern NSString * const kROXNotifBeaconProximityString;

extern NSString * const kROXNotifGeoRegionId;
extern NSString * const kROXNotifGeoRegionLat;
extern NSString * const kROXNotifGeoRegionLon;
extern NSString * const kROXNotifGeoRegionRadius;
extern NSString * const kROXNotifGeoRegionName;
extern NSString * const kROXNotifGeoRegionTags;

#pragma mark - Legacy

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
