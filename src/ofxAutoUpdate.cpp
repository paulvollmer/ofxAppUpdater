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
 * @version     1.0.1e
 */



#include "ofxAutoUpdate.h"


namespace wng {
	
	/**
	 * A Constructor, usually called to initialize and start the class.
	 */
	ofxAutoUpdate::ofxAutoUpdate(){}
	
	
	
	
	/**
	 * init
	 *
	 * @param
	 */
	void ofxAutoUpdate::init(string currentVersion, string appcastSrc){
		
		ofRegisterURLNotification(this);
		ofLoadURLAsync(appcastSrc, "load");
		updater.init(currentVersion, appcastSrc);
		// S
		updater.mode = CHECK;
	}
	
	
	
	/**
	 * update
	 */
	void ofxAutoUpdate::update(){
		//cout << updater.mode << endl;
		//cout << updater.message << endl;
		
		
		// DEFAULT
		/*if(updater.mode == 0) {
			cout << "Update DEFAULT\n";
		}
		
		
		// CHECK
		else if(updater.mode == 1){
			cout << "Update CHECK\n";
		}
		
		
		// LATEST_RELEASE
		else if(updater.mode == 2){
			cout << "Update LATEST_RELEASE\n";
		}
		
		
		// NEW_RELEASE
		else*/ if(updater.mode == NEW_RELEASE){
			// We create an integer for our notification display dialog.
			// this variables can be checked later.
			//string tempDesc = "Latest Version: "+updater.latestVersion+"\nCurrent Version: "+updater.currentVersion;
			int tempDialog = updater.userNotificationDisplay(updater.message,
															 "Latest Version: "+updater.latestVersion+"\nCurrent Version: "+updater.currentVersion,
															 "Download Now", "Cancel", "Check changes");
			
			switch (tempDialog) {
				case 0:
					cout << "Default response\n";
					updater.mode = DOWNLOAD;
					break;
				case 1:
					cout << "Alternate response\n";
					updater.mode = FINISHED;
					break;
				case 2:
					cout << "Other response\n";
					ofLaunchBrowser(updater.appcastPath);
					updater.mode = FINISHED;
					break;
				case 3:
					cout << "Cancel response\n";
					updater.mode = FINISHED;
					break;
				default:
					break;
			}
			
		}
		
		
		// DOWNLOAD
		else if(updater.mode == DOWNLOAD){
			//cout << "DOWNLOAD\n";
			
			// At the moment we create a file at the desktop.
			// I think we can handle this variable as an intern variable.
			//updater.download(ofFilePath::getPathForDirectory("~/Downloads/WNGtemp.zip"));
			/*updater.download(updater.appcast.getEnclosureUrl(xml, 0),
							 ofFilePath::getPathForDirectory("~/Downloads/WNGtemp.zip"));
			*/
			updater.download("http://www.wrong-entertainment.com/code/ofxAppUpdater/test_80mb.zip",
							 ofFilePath::getPathForDirectory("~/Downloads/WNGtemp.zip"));
			
			updater.mode = RELAUNCH;
			
		}
		
		
		// DOWNLOADING
		/*else if(updater.mode == DOWNLOADING){
			cout << ofGetFrameNum() << " DOWNLOADING\n";
		}*/
		
		
		// RELAUNCH
		else if(updater.mode == RELAUNCH){
			cout << "RELAUNCH\n";
			
			// TODO----------------------------------------------------------------
		}
		
		
	}
	
	
	
	/**
	 * urlResponse
	 * based on http://forum.openframeworks.cc/index.php/topic,8398.0.html
	 *
	 * An other solution: for this we use the
	 * applescript system events?
	 */
	void ofxAutoUpdate::urlResponse(ofHttpResponse & response){
		
		// Switch different urlResponse for different updater modes.
		switch (updater.mode) {
				
			case DEFAULT:
				cout << "CHECK\n";
				break;
				
			case CHECK:
				if(response.status == 200){  
					//cout << response.request.name << endl;  
					//cout << response.data.getText() << endl;
					xml.loadFromBuffer(response.data);
					updater.checkVersion(xml);
				} else {  
					cout << response.status << " " << response.error << endl;
					updater.mode = FINISHED;
				}
				
				// Unregister URLNotification to close event.
				ofUnregisterURLNotification(this);
				break;
			

			/*	
			case NEW_RELEASE:
				cout << "RESPONSE_NEW\n";
				break;*/

				
			default:
				break;
		}
		
	}
	
	
}
