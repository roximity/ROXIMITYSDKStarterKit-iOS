//
//  AppDelegate.swift
//  swiftPlayground
//
//  Created by Cole Richards on 7/14/14.
//  Copyright (c) 2014 ROXIMITY. All rights reserved.
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    
    var window: UIWindow?
    
    
    func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
        // Override point for customization after application launch.
        
        ROXIMITYEngine.startWithLaunchOptions(launchOptions, engineOptions: nil, applicationId: "YOUR APPLICATION ID HERE", andEngineDelegate: nil);
        
        
        //ATTENTION: This is new! For beacon notifications to be fired correctly the following settings must be registered with the application.
        let types:UIUserNotificationType = [UIUserNotificationType.Alert, UIUserNotificationType.Badge, UIUserNotificationType.Sound];
        let appSettings:UIUserNotificationSettings = UIUserNotificationSettings(forTypes:types, categories:nil);
        UIApplication.sharedApplication().registerUserNotificationSettings(appSettings);
        
        return true;
    }
    
    func applicationWillResignActive(application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
        ROXIMITYEngine.resignActive();
    }
    
    func applicationDidEnterBackground(application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
        ROXIMITYEngine.background();
    }
    
    func applicationWillEnterForeground(application: UIApplication) {
        // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
        ROXIMITYEngine.foreground();
    }
    
    func applicationDidBecomeActive(application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
        ROXIMITYEngine.active();
    }
    
    func applicationWillTerminate(application: UIApplication) {
        //         Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
        ROXIMITYEngine.terminate();
    }

    func application(application: UIApplication, didReceiveLocalNotification notification: UILocalNotification) {
        ROXIMITYEngine.didReceiveLocalNotification(application, notification: notification);
    }
    
}

