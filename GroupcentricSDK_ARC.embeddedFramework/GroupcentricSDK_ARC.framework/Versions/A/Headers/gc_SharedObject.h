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
//  gc_Message.h
//  Groupcentric SDK
//
//  object used when sharing content from your app to a group


#import <Foundation/Foundation.h>


@interface gc_SharedObject : NSObject {
    
}

@property (nonatomic, assign) int           type;
@property (nonatomic, strong) NSString *    imageURL;
@property (nonatomic, strong) NSString *    varTitle;
@property (nonatomic, strong) NSString *    varSubtitle;
@property (nonatomic, strong) NSString *    varDateString;
@property (nonatomic, strong) NSString *    varDetails;
@property (nonatomic, strong) NSString *    varMarkup;
@property (nonatomic, strong) NSString *    varURL;

-(id)initWithContent:(int)type_ withTitle:(NSString *)title_ withSubtitle:(NSString *)subtitle_ withImageURL:(NSString *)imageurl_ withURL:(NSString *)url_ withDate:(NSString *)date_ withDetails:(NSString *)details_ withMarkup:(NSString *)markup_;

@end
