//
//  ROXIMITYEngine.h
//  ROXIMITYlib
//
//  Created by Danny Pier on 2/12/13.
//  Copyright (c) 2013 ROXIMITY. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "ROXBeaconRangeUpdateDelegate.h"
#import "ROXDeviceHookDelegate.h"

@protocol ROXIMITYEngineDelegate <NSObject>

@optional
-(void) bluetoothRoximityUsable:(BOOL)usable state:(CBCentralManagerState)state;
-(void) locationRoximityUsable:(BOOL)usable status:(CLAuthorizationStatus)authStatus;
-(void) notificationsRoximityPermitted:(BOOL)permitted;
-(void) aliasSetResult:(BOOL)success alias:(NSString *)alias error:(NSError *)error;
-(void) aliasRemoveResult:(BOOL)success error:(NSError *)error;

@end


/**
 * @brief The ROXIMITYEngine class serves to integrate the ROXIMITY SDK into your application.
 * @details The ROXIMITYEngine contains application delegate items that communicate the state of the application; active, inactive, forground, background, and terminated. The class also contains user alias setting and removing methods, toggles to activate/deactivate location usage and system level notifications notifications, and convenience methods to retrieve data known by the ROXIMITY SDK.
 */
@interface ROXIMITYEngine : NSObject

#pragma mark - Application State

/**
 * @warning This method is deprecated, please use startWithLaunchOptions:engineOptions:andApplicationId
 * @see startWithLaunchOptions:engineOptions:andApplicationId
 */
+(void) startWithLaunchOptions:(NSDictionary *) launchOptions andEngineOptions:(NSDictionary *)engineOptions __attribute__((deprecated("use startWithLaunchOptions:engineOptions:applicationId:andEngineDelegate instead")));

/**
 * @brief Application delegate item that communicates the application's launch and turns on ROXIMITY API functionality .
 * @details The startWithLaunchOption method is passed to the ROXIMITYEngine at the start of the application in the didFinishLaunchingWithOptions application delegate hook.
 * @param launchOptions dictionary of launch options to start the ROXIMITY Engine with
 * @param applicationId the application id string corresponding to your application found in the ROXIMITY Web Dashboard
 */
+(void) startWithLaunchOptions:(NSDictionary *)launchOptions engineOptions:(NSDictionary *)engineOptions andApplicationId:(NSString *)applicationId  __attribute__((deprecated("use startWithLaunchOptions:engineOptions:applicationId:andEngineDelegate instead")));

/**
 * @brief Application delegate item that communicates the application's launch and turns on ROXIMITY API functionality .
 * @details The startWithLaunchOption method is passed to the ROXIMITYEngine at the start of the application in the didFinishLaunchingWithOptions application delegate hook.
 * @param launchOptions dictionary of launch options to start the ROXIMITY Engine with
 * @param applicationId the application id string corresponding to your application found in the ROXIMITY Web Dashboard
 * @param engineDelegate the ROXIMITY Engine delegate that responds to receive state change alerts
 */
+(void) startWithLaunchOptions:(NSDictionary *)launchOptions engineOptions:(NSDictionary *)engineOptions applicationId:(NSString *)applicationId andEngineDelegate:(id<ROXIMITYEngineDelegate>)engineDelegate;

/**
 * @brief Application delegate item that communicates that the application is active.
 * @details The active method is passed to the ROXIMITYEngine whenever the application becomes active. A ROXIMITYEngine active call should be placed in the applicationDidBecomeActive delegate hook.
 *
 */
+(void) active;
/**
 * @brief Application delegate item that communicates that the application is resigning from active.
 * @details The resignActive method is passed to the ROXIMITYEngine when the application moves from an active to inactive state. A ROXIMITYEngine resignActive call should be placed in the applicationWillResignActive delegate hook.
 */
+(void) resignActive;
/**
 * @brief Application delegate item that communicates that the application has moved to the background.
 * @details The background method is passed to the ROXIMITYEngine when the application moves to the background. A ROXIMITYEngine background call should be placed in the applicationDidEnterBackground delegate hook.
 */
+(void) background;
/**
 * @brief Application delegate item that communicates that the application has moved to the foreground and turns on ROXIMITY API foreground functionality.
 * @details The foreground method is passed to the ROXIMITYEngine when the application comes into the foreground. A ROXIMITYEngine foreground call should be placed in the applicationWillEnterForeground delegate hook.
 *
 */
+(void) foreground;
/**
 * @brief Application delegate item that communicates that the application is terminating.
 * @details The terminate method is passed to the ROXIMITYEngine when the application is about to terminate. A ROXIMITYEngine terminate call should be placed in the applicationWillTerminate delegate hook.
 *
 */
+(void) terminate;

#pragma mark Alias Methods

/**
 * @brief Sets the user alias for a device
 * @description This method allows you to associate a device with a user alias such as an email address or user id.  This is typically called after login
 * @see removeAlias
 */
+(void) setAlias:(NSString*) alias;

/**
 * @brief Removes the user alias for a device
 * @descrption This removes any previously set user alias.  This is typically called after a user logout
 */
+(void) removeAlias;

/**
 * @brief Returns the currently set user alias
 * @description If a user alias was successfully set, it will be returned here
 * @return alias The currently set user alias string
 */
+(NSString *) getAlias;

#pragma mark - Delegates

/**
 * @brief The delegate that returns updates about the ROXIMITY SDK's state
 * @description When important ROXIMITY Engine events take place, this delegate will be invoked
 */
+(void) setROXIMITYEngineDelegate:(id<ROXIMITYEngineDelegate>)roximityEngineDelegate;

/**
 * @brief The delegate that returns updates about beacons currently in range
 * @description When beacons are discovered in range, the ROXIMITY SDK will invoke the delegate set here with NSDictionary descriptions of those beacons
 * @params interval The update interval with which to return beacon range updates.  Options are fastest, balanced, and power saving with balanced as the default
 */
+(void) setBeaconRangeDelegate:(id<ROXBeaconRangeUpdateDelegate>)beaconRangeUpdateDelegate withUpdateInterval:(ROXBeaconRangeUpdateInterval)interval;

/**
 * @brief The delegate that returns updates about beacons currently in range
 * @description When beacons are discovered in range, the ROXIMITY SDK will invoke the delegate set here with NSDictionary descriptions of those beacons
 * @params interval The update interval with which to return beacon range updates.  Options are fastest, balanced, and power saving with balanced as the default
 */
+(void) setDeviceHookDelegate:(id<ROXDeviceHookDelegate>)deviceHookDelegate;


#pragma mark - Notification Handlers

/**
 * @brief Informs ROXIMITY of the push token
 * @description Required not only for delivering push notifications through roximity, but also for enabling the ROXIMITY SDK to be fully up to date with the ROXIMITY Dashboard through silent fetch notifications
 * @params deviceToken the device token return through iOS to your application
 */
+(void) didRegisterForRemoteNotifications:(NSData*) deviceToken;

/**
 * @brief Informs ROXIMITY of current notification settings
 * @description Allows ROXIMITY to determine whether or not a user is reachable through notifications which will be reflected in dashboard analytics
 * @params notificationSettings settings returned through iOS to your application
 */
+(void) didRegisterUserNotifications:(UIUserNotificationSettings *)notificationSettings;

/**
 * @brief Notifies ROXIMITY that notifications have failed to be registered
 * @params error the error return through iOS to your application
 */
+(void) didFailToRegisterForRemoteNotifications:(NSError*) error;

/**
 * @brief Notifies ROXIMITY of a push notification
 * @description ROXIMITY will immediately check to see if this push notification is sent from ROXIMITY and will ignore all other push notifications
 * @params application the current application
 * @params userInfo the dictionary accompanying the push notification
 * @params completionHandler the handler of the fetch notification
 */
+(BOOL) didReceiveRemoteNotification:(UIApplication *)application userInfo:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;

/**
 * @brief Notifies ROXIMITY of a push notification
 * @description ROXIMITY will immediately check to see if this push notification is sent from ROXIMITY and will ignore all other push notifications. Used to determine conversion analytics and update beacon content from ROXIMITY dashboard if necessary.
 * @params application the current application
 * @params userInfo the dictionary accompanying the push notification
 */
+(BOOL) didReceiveRemoteNotification:(UIApplication *)application userInfo:(NSDictionary *)userInfo;

/**
 * @brief Notifies ROXIMITY of a local notification notification
 * @description ROXIMITY will immediately check to see if this local notification originated from ROXIMITY and will ignore all other notifications.  Used to determine conversion analytics.
 * @params application the current application
 * @params userInfo the dictionary accompanying the push notification
 */
+(BOOL) didReceiveLocalNotification:(UIApplication *) application notification:(UILocalNotification *)notification;

#pragma mark - State toggles

/**
 * @brief Deactivates all location based interactions
 * @description Calling this method disables all ROXIMITY interactions with device location, including beacon interactions
 */
+(void) deactivateLocation;

/**
 * @brief Activates location
 * @description Returns the ROXIMITY SDKto its normal functioning state for location if it has previously been disabled
 */
+(void) activateLocation;

/**
 * @brief Returns whether or not the ROXIMITY SDK is currently using location
 * @returns locationActivated YES or NO
 */
+(BOOL) isLocationActivated;

/**
 * @brief Disables local notifications shown by the ROXIMITY SDK
 */
+(void) disableLocalNotifications;

/**
 * @brief Enables local notifications in the ROXIMITY SDK
 */
+(void) enableLocalNotifications;

/**
 * @brief Returns whether or not local notifications are currently enabled
 * @returns locationsEnabled YES or NO
 */
+(BOOL) isLocalNotificationEnabled;

#pragma mark - Metadata

/**
 * @brief Adds a key-value metadata pair to ROXIMITY SDK logs which can later be associated with visit analytics in the ROXIMITY Dashboard
 */
+(void) addVisitMetadata:(NSString *)tag withValue:(NSObject *)value;

/**
 * @brief Adds a dictionary of key-value metadata pairs to ROXIMITY SDK logs which can later be associated with visit analytics in the ROXIMITY Dashboard
 */
+(void) addVisitMetadataDictionary:(NSDictionary *)visitMetadataDictionary;

/**
 * @brief Adds a key-value metadata pair to ROXIMITY SDK logs which can be used for user targeting in the ROXIMITY Dashboard
 */
+(void) addRegistrationMetadata:(NSString *)tag withValue:(NSObject *)value;

/**
 * @brief Adds a dictionary of key-value metadata pair to ROXIMITY SDK logs which can which can be used for user targeting in the ROXIMITY Dashboard
 */
+(void) addRegistrationMetadataDictionary:(NSDictionary *)registrationMetadataDictionary;

#pragma mark - Convenience Methods

/**
 * @brief Returns most recent location known by ROXIMITY
 * @description For convenience, returns the most recent location known to the ROXIMITY SDK.  This may not match current device location.
 * @returns most recent CLLocation as seen by the ROXIMITY SDK
 */
+(CLLocation *) getMostRecentLocation;

/**
 * @brief Provides a list of the n number of last seen beacons
 * @returns a NSArray of beacon dictionaries of size n or less, if fewer have been seen
 */
+(NSArray *) retrieveLastNBeacons:(int)numberOfBeacons;

/**
 * @brief Provides a list of the beacons seen in the last n seconds
 * @returns a NSArray of beacon dictionaries seen in the last n seconds
 */
+(NSArray *) retrieveBeaconsSeenInLastNSeconds:(int) seconds;

+(void) reset;

@end
