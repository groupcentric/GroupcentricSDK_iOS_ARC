Feature
====================

v1.0  12/7/2012

This is the Groupcentric SDK with ARC enabled for iOS.
This is the simplest way to add private sharing and group chat into your app.

<ul>
<li>Minimum: iOS 5.0</li>
<li>ARC compliant</li>
<li>Includes some 3rd party libs that are not ARC but have been flagged with -fno-objc-arc  so they are specifically compiled with ARC disabled</li>
<li>Allow users to share any of your content privately into their friend groups and chat with them about it within your app</li>
</ul>

====================

Usage
====================

Documentation and support can be found at http://groupcentric.com

====================

Building
====================

1) Build the project.

2) In finder locate the Debug-iphoneos folder for your build. (ex: /Users/kbessette/Library/Developer/Xcode/DerivedData/GroupcentricSDK_ARC-xxxxx/Build/Products/)

3) Add a folder called GroupcentricSDK.embeddedFramework

4) Copy GroupcentricSDK.framework from Debug-iphoneos to the new folder GroupcentricSDK.embeddedFramework

5) Add the SDK resources folder downloaded with the source from Github to the GroupcentricSDK.embeddedFramework folder

6) Follow the steps in docs at http://groupcentric.com to add the framework to your project.

====================

License
====================

Copyright 2012 Shizzlr Inc.
 

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

====================

Our works
====================

<a href="http://groupcentric.com" target="_blank">Some apps using this SDK</a>

<img src="http://groupcentric.com/img/support/gc_appicon_72.png" alt="Groupcentric" /> &nbsp; 

<img src="http://groupcentric.com/img/support/gs_appicon_72.png" alt="Groupsquare" /> &nbsp; 


