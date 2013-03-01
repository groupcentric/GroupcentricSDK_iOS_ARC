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
//  WebBrowserVC.m
//  Groupcentric SDK
//


#import "GCWebBrowserVC.h"


@implementation GCWebBrowserVC

@synthesize theWeb;

- (id)initWithURLString:(NSString *)url {
    if ((self = [super init])) {
        urlString = url;//[url retain];
    }
    return self;
}

- (void)dealloc
{
   
}

- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    theWeb.delegate = self;
    // Do any additional setup after loading the view from its nib.
    
    NSURL *_url = [NSURL URLWithString:urlString];
    //URL Requst Object
    NSURLRequest *requestObj = [NSURLRequest requestWithURL:_url];
    //Load the request in the UIWebView.
    [theWeb loadRequest:requestObj];
    
    self.title = @"Loading...";
    
    // Left button
    UIButton *backButton = [[UIButton alloc] initWithFrame:CGRectMake(0, 0, 50, 31)];
    [backButton setBackgroundImage:[UIImage imageNamed:@"gc_blankbtn.png"] forState:UIControlStateNormal];
    [backButton setTitle:@"Back" forState:UIControlStateNormal];
    backButton.titleLabel.font = [UIFont boldSystemFontOfSize:13];
    backButton.titleLabel.shadowColor = [UIColor blackColor];
    backButton.titleLabel.shadowOffset = CGSizeMake(0, -1);
    [backButton addTarget:self action:@selector(goBack) forControlEvents:UIControlEventTouchUpInside];
    UIBarButtonItem *but = [[UIBarButtonItem alloc] initWithCustomView:backButton];
    self.navigationItem.leftBarButtonItem = but;
   
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    self.theWeb = nil;
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

#pragma mark - Web View

- (void)webViewDidStartLoad:(UIWebView *)webView {
    // Set activity indicator in the right of navigation bar
    UIActivityIndicatorView *activityIndicator = [[UIActivityIndicatorView alloc] initWithFrame:CGRectMake(0, 0, 20, 20)];
    [activityIndicator startAnimating];
    UIBarButtonItem *activityItem = [[UIBarButtonItem alloc] initWithCustomView:activityIndicator];
    
    self.navigationItem.rightBarButtonItem = activityItem;
  
}

- (void)webViewDidFinishLoad:(UIWebView *)webView {
    self.title = [theWeb stringByEvaluatingJavaScriptFromString:@"document.title"];
	self.navigationItem.rightBarButtonItem = nil;
}

- (void)webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error {
    self.navigationItem.rightBarButtonItem = nil;
    self.title = @"Error loading page";
    
    // Could also use alert view for user, or log the error
}

#pragma mark - Actions

- (void)goBack {
    [self.navigationController popViewControllerAnimated:YES];
}

- (IBAction)otherAction {
	UIActionSheet *manageActionSheet = [[UIActionSheet alloc]
										initWithTitle:nil
										delegate:self
										cancelButtonTitle:@"Cancel"
										destructiveButtonTitle:nil
										otherButtonTitles:	@"Open in Safari",
										nil];
	
    manageActionSheet.actionSheetStyle = UIActionSheetStyleBlackOpaque;
	[manageActionSheet showInView:self.view];
	
}

#pragma mark - Action Sheet Delegate

- (void)actionSheet:(UIActionSheet *)modalView clickedButtonAtIndex:(NSInteger)buttonIndex {
	switch (buttonIndex)
	{
		case 0:
		{
			[[UIApplication sharedApplication] openURL:theWeb.request.URL];
			break;
		}
		default:
		{
			break;
		}
	}
}

@end
