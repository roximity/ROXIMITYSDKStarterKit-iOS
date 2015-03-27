//
//  AppDelegate.m
//  StarterKit
//
//  Created by Cole Richards on 4/2/14.
//  Copyright (c) 2014 ROXIMITY. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.
    
    //Starting the ROXIMITY Engine!
    [ROXIMITYEngine startWithLaunchOptions:launchOptions engineOptions:nil applicationId:@"YOUR_APPLICATION_ID_HERE" andEngineDelegate:self];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
    
    [ROXIMITYEngine resignActive]; // Place in applicationWillResignActive
    
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    [ROXIMITYEngine background];   // Place in applicationDidEnterBackground
    
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    [ROXIMITYEngine foreground];   // Place in applicationWillEnterForeground
    
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    [ROXIMITYEngine active];       // Place in applicationDidBecomeActive
    
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    [ROXIMITYEngine terminate];    // Place in applicationWillTerminate
}


//Adding the following methods for remote notification handling
-(void) application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError*)error
{
    [ROXIMITYEngine didFailToRegisterForRemoteNotifications:error];
}

-(void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
    [ROXIMITYEngine didRegisterForRemoteNotifications:deviceToken];
}

-(void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler{
    [ROXIMITYEngine didReceiveRemoteNotification:application userInfo:userInfo fetchCompletionHandler:completionHandler];
}

-(void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo{
    [ROXIMITYEngine didReceiveRemoteNotification:application userInfo:userInfo];
}

-(void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification{
    [ROXIMITYEngine didReceiveLocalNotification:application notification:(UILocalNotification *)notification];
}

@end