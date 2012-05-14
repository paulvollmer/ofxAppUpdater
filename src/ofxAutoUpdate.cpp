/**
 *  ofxAutoUpdater.cpp
 *
 *  
 *  The MIT License
 *
 *  Copyright (c) 2012 Paul Vollmer, http://www.wng.cc
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 *
 *  
 *  @testet_oF          0.07
 *  @testet_plattform   MacOs 10.6
 *                      ??? Win
 *                      ??? Linux
 *  @dependencies       ofxXmlSettings
 *  @modified           2012.05.14
 *  @version            0.1.1e
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
		// Set the mode to enum CHECK
		updater.mode = CHECK;
		
		#ifdef OFXAUTOUPDATE_LOG
			ofLog() << "[ofxAutoUpdate] Current Version: " << currentVersion;
			ofLog() << "[ofxAutoUpdate] Appcast src: " << appcastSrc;
		#endif
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
															 "Download Now", "Later", "Check Changes");
			
			switch (tempDialog) {
				case 0:
					#ifdef OFXAUTOUPDATE_LOG
						ofLog() << "[ofxAutoUpdate] Default Response (Download Now)";
					#endif
					updater.mode = DOWNLOAD;
					break;
				case 1:
					#ifdef OFXAUTOUPDATE_LOG
						ofLog() << "[ofxAutoUpdate] Alternate Response (Later)";
					#endif
					updater.mode = FINISHED;
					break;
				case 2:
					#ifdef OFXAUTOUPDATE_LOG
						ofLog() << "[ofxAutoUpdate] Other Response (Check Changes)";
					#endif
					ofLaunchBrowser(updater.appcastPath);
					updater.mode = FINISHED;
					break;
				case 3:
					#ifdef OFXAUTOUPDATE_LOG
						ofLog() << "[ofxAutoUpdate] Cancel Response";
					#endif
					updater.mode = FINISHED;
					break;
				default:
					break;
			}
			
		}
		
		
		// DOWNLOAD
		else if(updater.mode == DOWNLOAD){
			//cout << "DOWNLOAD\n";
			
			// At the moment we create a file at the downloads directory.
			// I think we can handle this variable as an intern variable.
			updater.download(updater.appcast.getEnclosureUrl(xml, 0),
							 ofFilePath::getPathForDirectory("~/Downloads/WNGtemp.zip"));
			
			/*updater.download("http://www.wrong-entertainment.com/code/ofxAppUpdater/test_80mb.zip",
							 ofFilePath::getPathForDirectory("~/Downloads/WNGtemp.zip"));
			*/
			
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
	 * An other solution: for this we can use the
	 * applescript system events?
	 */
	void ofxAutoUpdate::urlResponse(ofHttpResponse & response){
		
		// Switch different urlResponse for different updater modes.
		switch (updater.mode) {
				
			/*case DEFAULT:
				cout << "CHECK\n";
				break;*/
				
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
		}
		
	}
	
	
}
