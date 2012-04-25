/**
 * ofxAppUpdater.cpp is developed by Paul Vollmer
 * http://www.wng.cc
 * 
 * 
 * Copyright (c) 2012 Paul Vollmer
 *
 * ofxAppUpdater.cpp is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * ofxAppUpdater.cpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General
 * Public License along with ofxAppUpdater.cpp; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 * 
 * @author      Paul Vollmer
 * @modified    2012.04.25
 * @version     1.0.1d2
 */



#include "ofxAutoUpdate.h"


namespace wng {
	
	/**
	 * A Constructor, usually called to initialize and start the class.
	 */
	ofxAutoUpdate::ofxAutoUpdate(){}
	
	
	
	
	/**
	 * sendRequest
	 *
	 *
	 * @see example_autoUpdate
	 */
	void ofxAutoUpdate::init(string currentVersion, string appcastSrc){
		
		ofRegisterURLNotification(this);
		ofLoadURLAsync(appcastSrc, "load");
		// ???
		// An other solution:
		// for this we use the applescript system events?
		
		updater.init(currentVersion, appcastSrc);
		
	}
	
	
	
	void ofxAutoUpdate::update(){
		
	}
	
	
	
	/*
	void ofxAutoUpdate::downloadRequest(string currentVersion, string appcastSrc){
		/*init(currentVersion, appcastSrc, true);
		
		checkVersion();
		
		if(mode == NEW_RELEASE){
			// We create an integer for our notification display dialog.
			// this variables can be checked later.
			string tempDesc = "Latest Version: "+latestVersion+"\nCurrent Version: "+currentVersion;
			int tempDialog = userNotificationDisplay(message, tempDesc, "Download Now", "Cancel", "Check changes");
			
			switch (tempDialog) {
				case 0:
					cout << "Default response\n";
					
					// At the moment we create a file at the desktop.
					// I think we can handle this variable as an intern variable.
					//download(ofFilePath::getPathForDirectory("~/Downloads/")+temporaryDownloadFilename);
					
					download();
					
					ofSleepMillis(200);
					
					break;
				case 1:
					cout << "Alternate response\n";
					break;
				case 2:
					cout << "Other response\n";
					break;
				case 3:
					cout << "Cancel response\n";
					break;
				default:
					break;
			}
		}
		relaunch();
		
	}*/
	
	
	
	
	void ofxAutoUpdate::urlResponse(ofHttpResponse & response){
		
		// based on http://forum.openframeworks.cc/index.php/topic,8398.0.html
		if(response.status==200 ){  
			//cout << response.request.name << endl;  
			//cout << response.data.getText() << endl;
			
			updater.xml.loadFromBuffer(response.data);
			
			int tempCheck = updater.checkVersion(updater.xml);
			
			switch (updater.mode) {
				case LATEST_RELEASE:
					cout << "LATEST_RELEASE" << endl;
					break;
				case NEW_RELEASE:
					cout << "NEW_RELEASE" << endl;
					break;
				default:
					cout << "default" << endl;
					break;
			}
			
		}else{  
			cout << response.status << " " << response.error << endl;  
		}
		
		// Unregister URLNotification to close event.
		//ofUnregisterURLNotification(this);
		
	}
	
	
}
