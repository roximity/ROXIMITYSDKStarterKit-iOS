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
extern NSString * const kROXEngineOptionsMuteLocationPermissionAlert;
extern NSString * const kROXEngineOptionsMuteNotificationPermissionAlert;
extern NSString * const kROXEngineOptionsStartLocationDeactivated;
extern NSString * const kROXEngineOptionsDebugLogging;
extern NSString * const kROXEngineOptionsVerboseLogging;
extern NSString * const kROXEngineOptionsUserTargetingLimited;

#pragma mark - Notification Observer Constants

extern NSString * const kROXStateNotification;
extern NSString * const kROXRoximityLocalNotification;
extern NSString * const kROXRoximityPushNotification;
extern NSString * const kROXRoximityActionNotification;
extern NSString * const kROXRoximityTriggerNotification;
extern NSString * const kROXBeaconRangeUpdated;
extern NSString * const kROXMessageFired;
extern NSString * const kROXWebhookPosted;

#pragma mark - Notification Keys

extern NSString * const kROXKeyGeoRegionId;
extern NSString * const kROXKeyGeoRegionLat;
extern NSString * const kROXKeyGeoRegionLon;
extern NSString * const kROXKeyGeoRegionRadius;
extern NSString * const kROXKeyGeoRegionName;
extern NSString * const kROXKeyGeoRegionTags;

extern NSString * const kROXKeyBeaconId;
extern NSString * const kROXKeyBeaconName;
extern NSString * const kROXKeyBeaconTags;
extern NSString * const kROXKeyBeaconProximityValue;
extern NSString * const kROXKeyBeaconProximityString;


#pragma mark - Legacy

// Will be removed in 1.4 release
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


@end
