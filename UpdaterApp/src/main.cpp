/**
 * UpdaterApp is developed by Paul Vollmer
 * http://www.wng.cc
 * 
 * 
 * Copyright (c) 2012 Paul Vollmer
 *
 * UpdaterApp is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * UpdaterApp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General
 * Public License along with UpdaterApp; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 * 
 * @author      Paul Vollmer
 * @modified    2012.04.23
 * @version     0.0.1a
 */



#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

// Using NSMenu outside the NIB
// Found at openFrameworks forum. http://forum.openframeworks.cc/index.php/topic,78.0.html (Reply #6)
// IMPORTANT:
// right-click on that file (in my case main.cpp), select "Get Info",
// then in the "General" tab set your "File Type" to sourcecode.cpp.objcpp
#include "Cocoa/Cocoa.h"

//========================================================================
int main( ){

    ofAppGlutWindow window;
	ofSetupOpenGL(&window, 800,400, OF_WINDOW);			// <-------- setup the GL context

	
	// Modified menubar
	if (NSApp){  
        NSMenu      *menu;  
        NSMenuItem  *menuItem;   
		
        [NSApp setMainMenu:[[NSMenu alloc] init]];  
		
		
		// Appname menu
		menu = [[NSMenu alloc] initWithTitle:@""];  
		[menu addItemWithTitle:@"About UpdateManager" action:@selector(orderFrontStandardAboutPanel:) keyEquivalent:@""];
		
		[menu addItem:[NSMenuItem separatorItem]];
		
		[menu addItemWithTitle:@"Hide UpdateManager" action:@selector(hide:) keyEquivalent:@"h"];
		
		menuItem = (NSMenuItem *)[menu addItemWithTitle:@"Hide Others" action:@selector(hideOtherApplications:) keyEquivalent:@"h"];
		[menuItem setKeyEquivalentModifierMask:(NSAlternateKeyMask|NSCommandKeyMask)];
		
		[menu addItemWithTitle:@"Show All" action:@selector(unhideAllApplications:) keyEquivalent:@""];
		
		[menu addItem:[NSMenuItem separatorItem]];
		
		[menu addItemWithTitle:@"Quit UpdateManager" action:@selector(terminate:) keyEquivalent:@"q"]; 
		
		// Put menu into the menubar
		menuItem = [[NSMenuItem alloc] initWithTitle:@"Apple" action:nil keyEquivalent:@""];  
		[menuItem setSubmenu:menu];  
		[[NSApp mainMenu] addItem:menuItem];
		// Tell the application object that this is now the application menu
		//[NSApp setMainMenu:menu];
    } 
	
	
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new testApp());

}
