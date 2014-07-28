//
//  ROXIMITYEngine.h
//  ROXIMITYlib
//
//  Created by Danny Pier on 2/12/13.
//  Copyright (c) 2013 ROXIMITY. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
/**
 * @brief The ROXIMITYEngine class serves to integrate the ROXIMITY SDK into your application.
 * @details The ROXIMITYEngine contains application delegate items that communicate the state of the application; active, inactive, forground, background, and terminated. The class also allows for user device and phone number verification, alias setting and removing methods, and convenience methods to retrieve a user's CLLocation.
 * @sa 
 * - @ref integration - Using the ROXIMITYEngine class to integrate the ROXIMITY SDK.
 * - @ref phoneNumberVerification - Using the ROXIMITYEngine class for phone number verification.
 * - @ref aliases - Using the ROXIMITYEngine class to set and remove user alias.
 * - @ref convenienceMethods - Using the ROXIMITYEngine convenience method to get users' CLLocation.
 */
@interface ROXIMITYEngine : NSObject

/**
 * @brief Application delegate item that communicates the application's launch and turns on ROXIMITY API functionality .
 * @details The startWithLaunchOption method is passed to the ROXIMITYEngine at the start of the application in the didFinishLaunchingWithOptions application delegate hook.
 * @param NSDictionary item launchOptions
 */
+(void) startWithLaunchOptions:(NSDictionary *) launchOptions andEngineOptions:(NSDictionary *)engineOptions;
/**
 * @brief Application delegate item that communicates that the application is active and turns on the application's ROXIMITY Beacon sensors.
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

// Alias Items
+(void) setAlias:(NSString*) alias;
+(void) removeAlias;
+(void) deregister;

// Registration Items
+(BOOL) isRegistered;
+(BOOL) isVerified;
+(NSString *) getAlias;
+(void) sendVerificationSMS:(UIViewController *) controller;

// Push Notification Registration Items
+(void) didRegisterForRemoteNotifications:(NSData*) deviceToken;
+(void) didFailToRegisterForRemoteNotifications:(NSError*) error;
+(void) didReceiveRemoteNotification:(UIApplication *)application userInfo:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;
+(void) didReceiveRemoteNotification:(UIApplication *)application userInfo:(NSDictionary *)userInfo;
+(void) didReceiveLocalNotification:(UIApplication *) application notification:(UILocalNotification *)notification;

// Location Items
+(CLLocation *) getMostRecentLocation;
+(void) updateLocationNow;
+(void) deactivateLocation;
+(void) reactivateLocation;
+(BOOL) isLocationDeactivated;

//+(BOOL) engineCheckPassed;

@end
