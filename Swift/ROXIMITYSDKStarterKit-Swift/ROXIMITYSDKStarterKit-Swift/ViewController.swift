//
//  ViewController.swift
//  swiftPlayground
//
//  Created by Cole Richards on 7/14/14.
//  Copyright (c) 2014 ROXIMITY. All rights reserved.
//

import UIKit
import CoreLocation

class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    @IBOutlet var rangedBeaconsTable: UITableView?
    var rangedBeacons:NSMutableArray = []
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Do any additional setup after loading the view, typically from a nib.
        
    }
    
    override func viewDidAppear(animated: Bool) {
        //Add a notification observer for
        NSNotificationCenter.defaultCenter().addObserver(self, selector: Selector("beaconRangeUpdated:"), name: kROXBeaconRangeUpdated, object:nil)
    }
    
    func beaconRangeUpdated(notification:NSNotification!){
        //resets the cache of ranged beacons
        self.rangedBeacons.removeAllObjects()
        
        let userInfo:NSDictionary = notification.userInfo!
        //If we haven't ranged any beacons we'll bail on this method
        if (userInfo.allKeys.count == 0){
            return
        }
        
        for (beaconKey, beaconInfo) in userInfo{
            print(beaconInfo); //checkout the info for each beacon!
            self.rangedBeacons.addObject(beaconInfo);
        }
        self.rangedBeaconsTable?.reloadData();
    }
    
    
    //table delegate methods
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.rangedBeacons.count;
    }
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        
        let cell = UITableViewCell(style: UITableViewCellStyle.Subtitle, reuseIdentifier:"beaconCell")
        let cellDict:NSDictionary = self.rangedBeacons.objectAtIndex(indexPath.row) as! NSDictionary;
        
        cell.textLabel?.text = cellDict.objectForKey("beacon_name") as! String;
        cell.detailTextLabel?.text = cellDict.objectForKey("proximity_string") as! String;
        
        return cell
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
}

