//
//  ROXViewController.m
//  StarterKit
//
//  Created by Cole Richards on 4/2/14.
//  Copyright (c) 2014 ROXIMITY. All rights reserved.
//

#import "ROXViewController.h"
#import "ROXIMITYlib.h"

@interface ROXViewController ()

@end

@implementation ROXViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    //This notification listener calls the receivedStatusNotification method every time beacon status is updated.
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(receivedStatusNotification:)
                                                 name:ROX_NOTIF_BEACON_RANGE_UPDATE
                                               object:nil];

}

-(void)receivedStatusNotification:(NSNotification *)notification{
    NSDictionary *userInfo = notification.userInfo;
    NSLog(@"This is the basic information from your beacons: \n %@", userInfo);
    
    //To access the information about beacons inside the notification dictionary use the following beacon constants.
    for (NSString *beaconKey in userInfo){
        NSDictionary *beaconDict = [userInfo objectForKey:beaconKey];
        NSLog(@"Beacon Name: %@", [beaconDict objectForKey:ROX_BEACON_RANGE_KEY_BEACON_NAME]);
        NSLog(@"Beacon Tags: %@", [beaconDict objectForKey:ROX_BEACON_RANGE_KEY_BEACON_TAGS]);
        NSLog(@"Beacon Proximity String: %@", [beaconDict objectForKey:ROX_BEACON_RANGE_KEY_PROXIMITY_STRING]);
        NSLog(@"Beacon Proximity Value: %@", [beaconDict objectForKey:ROX_BEACON_RANGE_KEY_PROXIMITY_VALUE]);
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
