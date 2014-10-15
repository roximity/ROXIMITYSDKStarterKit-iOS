//
//  ViewController.m
//  StarterKit
//
//  Created by Cole Richards on 4/2/14.
//  Copyright (c) 2014 ROXIMITY. All rights reserved.
//

#import "ViewController.h"
#import "ROXIMITYlib.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    
    //Establish this viewcontroller as the delegate for beacon range update callbacks
    [ROXIMITYEngine setBeaconRangeDelegate:self withUpdateInterval:kROXBeaconRangeUpdatesFastest];
    
    //Establish this viewcontroller as the delegate or ROXIMITY engine callbacks
    [ROXIMITYEngine setROXIMITYEngineDelegate:self];
    
    //Example of setting a user alias in ROXIMITY SDK
    [ROXIMITYEngine setAlias:@"ROXStarterKit user"];
}

//ROXIMITY Beacon Delegate Methods
- (void) didUpdateBeaconRanges:(NSArray *)rangedBeacons{
    if ([rangedBeacons count] == 0){
        return;
    }else{
        NSLog(@"ROXIMITY found the following beacons: \n%@", rangedBeacons);
    }
}


//ROXIMITY Engine Delegate methods
-(void) bluetoothStateChange:(BOOL)bluetoothOn{
    NSLog(@"Bluetooth capabilities are %@", bluetoothOn ? @"ON" : @"OFF");
}

-(void) aliasSetResult:(BOOL)success alias:(NSString *)alias error:(NSError *)error{
    if (success){
        NSLog(@"Alias has been set to: %@", [ROXIMITYEngine getAlias]);
    }else{
        NSLog(@"There was an error setting the alias: %@", error);
    }
}

-(void) aliasRemoveResult:(BOOL)success error:(NSError *)error{
    
    if (success){
        NSLog(@"Alias has been removed");
    }else{
        NSLog(@"There was an error removing the alias: %@", error);
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
