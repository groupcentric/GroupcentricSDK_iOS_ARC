/*
 Copyright 2010-2013 Shizzlr Inc. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 2. Redistributions in binaryform must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided withthe distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE SHIZZLR INC``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL URBAN AIRSHIP INC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
//
//  ViewController.h
//  Groupcentric SDK
//


#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import "gc_GroupListTableViewCell.h"
#import "gc_ASIFormDataRequest.h"
#import <GroupcentricLib/Groupcentric.h>
#import "gc_GroupDetailsVC.h"
#import "gc_NewGroupVC.h"
#import "gc_NotificationsVC.h"
#import "gc_ProfileVC.h"
#import "gc_WebBrowserVC.h"
#import "gc_SignupOrLoginVC.h"
#import "gc_TTTTimeIntervalFormatter.h"
#import "gc_EGORefreshTableHeaderView.h"

@protocol GroupsViewControllerDelegate <NSObject>
-(void) parentUpdateGroupNotificationsCount;
@end




@interface GC_ViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UINavigationControllerDelegate, EGORefreshTableHeaderDelegate, gc_ASIHTTPRequestDelegate, GroupDetailsDelegate> {
    
    IBOutlet UIButton *PrivacyTosButton;
    // signup ----------------------
    IBOutlet UIButton *GetStartedButton;
    IBOutlet UIView *getStartedView;
    IBOutlet UIImageView *bgView;
    
    // The main table view
    IBOutlet UITableView *theTableView;
        
    BOOL _signedIn;
        
    // Array of GCGroup objects
    NSMutableArray *myGroups;
    
    // Array of arrays containing at least 1 LoadImageRequest object
    // Can contain up to 4 LoadImageRequest objects in each subarray
    NSMutableArray *myGroupImages;
    
    // Array of GCNotification objects
    NSMutableArray *notifications;
    
    // Date formatter that uses the form "2 minutes ago", "1 day ago", etc.
    gc_TTTTimeIntervalFormatter *dateFormatter;
    
    // Set up the pull to refresh header
    gc_EGORefreshTableHeaderView *_refreshHeaderView;
    BOOL _reloading;
    
    BOOL shouldNotReload;
    BOOL initialLoading;
    BOOL startingNewGroup;
    int unreadCount;
}


@property (assign) id <GroupsViewControllerDelegate> delegate;

@property (nonatomic, retain) UIView *getStartedView;

// Get the list of groups
- (void)getGroups;
// Get the user's new notificaitons
- (void)getNotifications;

-(NSMutableArray*)getNotificationsFromParent;

// Get Started Signing in
- (IBAction)getStarted:(id)sender;

// open privacytos
- (IBAction)viewPrivacyTos:(id)sender;

// Start a new group
- (IBAction)newGroup:(id)sender;

// Toggle to the chat button
- (IBAction)chatAction:(id)sender;



// Open the notifications view controller
- (void)openNotifications;

// Check for unread notifications and set the right bar button item
- (void)checkUnreadNotifications;


@end
