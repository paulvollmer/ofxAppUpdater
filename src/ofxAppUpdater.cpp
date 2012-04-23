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
 * @modified    2012.04.22
 * @version     1.0.1d
 */



#include "ofxAppUpdater.h"

#include "ofxXmlSettings.h"

// This we need for cocoa dialog
#ifdef TARGET_OSX
#include <Carbon/Carbon.h>
#endif



namespace wng {
	
	/**
	 * A Constructor, usually called to initialize and start the class.
	 */
	ofxAppUpdater::ofxAppUpdater(){
		
		// Set the internetConnection variable to false. 
		// If you want to manually, set the internetConnection variable,
		// change it at openFrameworks setup.
		internetConnection = false;
		
		// We use the mode variable to design different ofxAppUpdater mode states.
		// See at example draw.
		mode = DEFAULT;
		
		// Default string for latestVersion variable.
		latestVersion = "not available";
		
		// Default string for temporaryDownloadFilename variable.
		temporaryDownloadFilename = "tempDownload_wng.zip";
		
		#ifdef OFXAPPUPDATER_LOG
			ofLog(OF_LOG_VERBOSE, "Constructor Ready!");
		#endif
		
	}


	
	
	
	/**
	 * initialize
	 *
	 * @param currentVersion
	 *        The current Application Version.
	 *        Like this: "1.0.0"
	 * @param appcastSrc
	 *        The url of the appcast.xml file.
	 * @param internetConnection
	 *        Boolean to trigger the internetConnection Variable.
	 */
	void ofxAppUpdater::init(string currentVersion, string appcastSrc, bool internetConnection){
		
		this->currentVersion = currentVersion;
		this->appcastSrc = appcastSrc;
		this->internetConnection = internetConnection;
		
		#ifdef OFXAPPUPDATER_LOG
			// TODO add to message variable = ... for advanced use.
			ofLog(OF_LOG_VERBOSE, "[ofxAppUpdater] init() --------------------------------------------------------");
			ofLog(OF_LOG_VERBOSE, "Current-Version: " + this->currentVersion);
			ofLog(OF_LOG_VERBOSE, "Appcast.xml: " + this->appcastSrc);
			ofLog(OF_LOG_VERBOSE, "Internet-Connection: " + ofToString(this->internetConnection));
			ofLog(OF_LOG_VERBOSE, "-------------------------------------------------------------------------------\n");
		#endif
		
		message = "Initialized";
		mode = DEFAULT;
		
	}
	
	void ofxAppUpdater::init(string currentVersion, string appcastSrc){
		init(currentVersion, appcastSrc, true);
	}
	
	
	
	
	
	/**
	 * autoUpdate
	 */
	void ofxAppUpdater::autoUpdate(){
		
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
				
	}
	
	
	
	
	
	/**
	 * checking
	 */
	void ofxAppUpdater::checkVersion(){
		
		if(internetConnection == true && mode == DEFAULT){
			
			#ifdef OFXAPPUPDATER_LOG
				ofLog(OF_LOG_VERBOSE, "[ofxAppUpdater] checkVersion() ------------------------------------------------");
			#endif
		
			
			// At the moment we create a file at he same directory like the app.
			// after parsing the xml, we remove file.
			string tempFile = ofFilePath::getCurrentWorkingDirectory()+"tempVersionInfo.xml";
			loadFile(appcastSrc, tempFile);
			ofSleepMillis(200);
			
			parseAppcast(tempFile);
			ofSleepMillis(200);
		
			ofFile tempXmlFile;
			tempXmlFile.removeFile(tempFile, true);
		
			// Check the Version numbers if it's false, you can download a new version.
			if(currentVersion == latestVersion){
				// change mode.
				mode = LATEST_RELEASE;
				message = "You're running the latest Application Release!";
			
				#ifdef OFXAPPUPDATER_LOG
					ofLog(OF_LOG_VERBOSE, "Message: "+message);
					ofLog(OF_LOG_VERBOSE, "-------------------------------------------------------------------------------\n");
				#endif
			} else if(latestVersion == "0xDEADC0DE"){
				// change mode.
				mode = LATEST_RELEASE;
				message = "ERROR! Something went wrong with our Appcast content.";
				
				#ifdef OFXAPPUPDATER_LOG
					ofLog(OF_LOG_VERBOSE, "Message: "+message);
					ofLog(OF_LOG_VERBOSE, "-------------------------------------------------------------------------------\n");
				#endif
			} else {
				// change mode.
				mode = NEW_RELEASE;
				message = "A new Version is Available!";
			
				#ifdef OFXAPPUPDATER_LOG
					ofLog(OF_LOG_VERBOSE, "Message: "+message);
					ofLog(OF_LOG_VERBOSE, "-------------------------------------------------------------------------------\n");
				#endif
			}
		}
		
	}
	
	
	
	
	/**
	 *
	 */
	void ofxAppUpdater::download(string src){
		
		//ofLog(OF_LOG_VERBOSE, "downloading");
		
		if(internetConnection == true && mode == NEW_RELEASE){
			
			loadFile(downloadUrl, src);
			
			ofSleepMillis(200);
			
			message = "Download Ready!";
			
			mode = DOWNLOAD;
		}
		
	}
	
	void ofxAppUpdater::download(){
		download(ofFilePath::getPathForDirectory("~/Downloads/")+temporaryDownloadFilename);
	}
	
	
	
	/**
	 * 
	 */
	void ofxAppUpdater::relaunch(){
		
		if(internetConnection == true && mode == DOWNLOAD){
			
			string tempFile = ofFilePath::getPathForDirectory("~/Downloads/")+temporaryDownloadFilename;
			unzip(tempFile);
			
			message = "Please replace the downloaded App \nwith your local version.\nYou can find the downloaded zip file at the \"downloads\" directory";
			ofSystemAlertDialog(message);
			
			// Open download folder in finder
			#ifdef TARGET_OS_MAC
				//string tempApplescript_AppWindow =
				//"osascript -e 'tell app \"Finder\" \n activate \n set this_window to make new Finder window \n set x to (path to application folder as text) & \"downloads\" as alias \n set the target of this_window to the x \n set the current view of this_window to icon view \n end tell'";
				//system(tempApplescript_AppWindow.c_str());
				/*string tempApplescript =
				"osascript -e 'tell app \"Finder\" \n activate \n set this_window to make new Finder window \n set x to (path to home folder as text) & \"downloads\" as alias \n set the target of this_window to the x \n set the current view of this_window to icon view \n end tell'";
				system(tempApplescript.c_str());*/
			#endif
			
			
			// !!! Work in Progress !!!
			// File Dialog to move app away from downoad folder.
			/*ofFileDialogResult dialog_result = ofSystemLoadDialog("Loadimage", false);
			if(dialog_result.bSuccess){
				cout<<"name:"<<dialog_result.getName()<<endl;
				cout<<"filepath:"<<dialog_result.getPath()<<endl;
			}*/
			
			
			// Delete downloaded zip file.
			ofFile tempXmlFile;
			tempXmlFile.removeFile(tempFile, true);
			
			// TODO
			// Move downloaded file to current working directory.
			
			mode = RELAUNCH;
			
			message = "Quit Application";
			ofExit(1);
		}
	}
	
	
	
	
	
	/**
	 * 
	 * 
	 * @param header
	 *        Header test
	 * @param message
	 *        Messsage test
	 * @param buttonDefault
	 *        Default text in button (like "ok")
	 * @param buttonAlternate
	 *        Alternate button title (like "cancel")
	 * @param buttonOther
	 *        Other button title
	 */
	int ofxAppUpdater::userNotificationDisplay(string header, string message, string buttonDefault, string buttonAlternate, string buttonOther){
		
		// we use a temp variable for the return value.
		int temp = 0;
		
		#ifdef TARGET_OS_MAC
		// Convert the strings to CFStringRef
		CFStringRef header_ref   = CFStringCreateWithCString( NULL, header.c_str(), strlen(header.c_str()) );
		CFStringRef message_ref  = CFStringCreateWithCString( NULL, message.c_str(), strlen(message.c_str()) );
		CFStringRef buttonDefault_ref  = CFStringCreateWithCString( NULL, buttonDefault.c_str(), strlen(buttonDefault.c_str()) );
		CFStringRef buttonAlternate_ref  = CFStringCreateWithCString( NULL, buttonAlternate.c_str(), strlen(buttonAlternate.c_str()) );
		CFStringRef buttonOther_ref  = CFStringCreateWithCString( NULL, buttonOther.c_str(), strlen(buttonOther.c_str()) );
		
		// Result code from the message box
		CFOptionFlags result;
		
		//Launch the message box
		CFUserNotificationDisplayAlert(0,                                 // no timeout
									   kCFUserNotificationNoteAlertLevel, // change it depending message_type flags 
		                                                                  // ( MB_ICONASTERISK.... etc.)
									   NULL,                              // icon url, use default, you can change it 
		                                                                  // depending message_type flags
									   NULL,                              // not used
									   NULL,                              // localization of strings
									   header_ref, message_ref,
									   buttonDefault_ref, buttonAlternate_ref, buttonOther_ref,
									   &result                            // response flags
									   );
		
		//Clean up the strings
		CFRelease(header_ref);
		CFRelease(message_ref);
		
		// Set our temp variable.
		switch(result){
			case kCFUserNotificationDefaultResponse:
				temp = 0;
				break;
			case kCFUserNotificationAlternateResponse:
				temp = 1;
				break;
			case kCFUserNotificationOtherResponse:
				temp = 2;
				break;
			default:
				temp = 3;
				break;
		}
		
		#endif
		
		return temp;
		
	}
	
	
	
	
	
	
	
	
	
	string ofxAppUpdater::getAppName(){
		string appPath = ofFilePath::getCurrentExePath();
		vector <string> te;
		te = ofSplitString(appPath, "/");
		//cout << ofToString(ofSplitString(appPath, "/")) << endl;
		//cout << "### " << te[te.size()-1] << endl;
		
		return ofToString(te[te.size()-1]);
	}	
	
	
	
	
	/**
	 * loadFile
	 * 
	 * @param serverSrc
	 *        url of the file
	 * @param tempFilepath
	 *        A path and name for the file we load from server.
	 */
	void ofxAppUpdater::loadFile(string serverSrc, string tempFilepath){
		
		// Xml file download
		//
		// Soluion 1:
		// use openFrameworks to download our xml file.
		
		//cout << ofGetTimestampString() << " DOWNLOAD XML FILE START." << endl;
		// Copy our version xml file to data folder.
		//ofSaveURLAsync(serverUrl+versionInfoXml, tempFilename);
		//cout << ofGetTimestampString() << " DOWNLOAD XML FILE READY." << endl;	
		
		// Solution 2:
		// we use applescript to download our xml file.
		//
		// Here is the original applescript
		// 
		// tell application "URL Access Scripting"
		// download "http://www.wrong-entertainment.com/code/wngUpdater/versioninfo.xml" to file "/testfile.txt" replacing yes
		// end tell
		#ifdef TARGET_OS_MAC
			string tempApplescript = "osascript -e 'tell app \"URL Access Scripting\" \n download \""+serverSrc+"\" to file \""+tempFilepath+"\" replacing yes \n end tell'";
			system(tempApplescript.c_str());
		#endif
		
	}
	
	
	/**
	 * parseAppcast
	 * At the monent we use hard coded xml tags.
	 *
	 * @param filepath
	 *        The path to our Appcast RSS feed.
	 */
	void ofxAppUpdater::parseAppcast(string filepath){
		
		// We load our xml file.
		// This is based on the openFrameworks xmlSettingsExample.
		if(xml.loadFile(filepath)){
			
			// we get the version and download vars by ofxAppcast class.
			latestVersion = appcast.getAppcastVersion(xml, 0);
			downloadUrl = appcast.getEnclosureUrl(xml, 0);
			
			#ifdef OFXAPPUPDATER_LOG
				ofLog(OF_LOG_VERBOSE, "[ofxAppUpdater] parseAppcast()");
				ofLog(OF_LOG_VERBOSE, "Filepath <" + filepath + "> loaded!");
				ofLog(OF_LOG_VERBOSE, "Latest Version: " + latestVersion);
				ofLog(OF_LOG_VERBOSE, "Download URL: " + downloadUrl);
			#endif
		} else {
			#ifdef OFXAPPUPDATER_LOG
				ofLog(OF_LOG_VERBOSE, "[ofxAppUpdater] parseAppcast()");
				ofLog(OF_LOG_VERBOSE, "File <" + filepath + "> not found!");
			#endif
		}
		
	}
	
	
	/**
	 * unzip
	 */
	void ofxAppUpdater::unzip(string src){
		
		#ifdef OFXAPPUPDATER_LOG
			ofLog(OF_LOG_VERBOSE, "[ofxAppUpdater] unzip( " +src+ " )");
		#endif
		
		// unzip file
		#ifdef TARGET_OSX
			// ok gotta be a better way then this,
			// this is what I found...
			string commandStr = "open "+src;
			system(commandStr.c_str());
		#endif

		ofSleepMillis(200);
		
	}
	
	
}
