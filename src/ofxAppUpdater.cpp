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



#include "ofxAppUpdater.h"

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
		//internetConnection = false;
		
		// We use the mode variable to design different ofxAppUpdater mode states.
		// See at example draw.
		mode = DEFAULT;
		
		// Default string for latestVersion variable.
		latestVersion = "0xDEADC0DE";
		
		// TODO: remove this var.
		// Default string for temporaryDownloadFilename variable.
		temporaryDownloadFilename = "tempDownload_wng.zip";
		
	}


	
	/**
	 * initialize
	 *
	 * @param currentVersion
	 *        The current Application Version.
	 *        Like this: "1.0.0"
	 * @param appcastPath
	 *        The url of the appcast.xml file.
	 * @param internetConnection
	 *        Boolean to trigger the internetConnection Variable.
	 */
	void ofxAppUpdater::init(string currentVersion, string appcastPath){
		
		this->currentVersion = currentVersion;
		this->appcastPath = appcastPath;
		
		/*#ifdef OFXAPPUPDATER_LOG
			// TODO add to message variable = ... for advanced use.
			ofLog(OF_LOG_VERBOSE, "[ofxAppUpdater] init() --------------------------------------------------------");
			ofLog(OF_LOG_VERBOSE, "Current-Version: " + this->currentVersion);
			ofLog(OF_LOG_VERBOSE, "Appcast.xml: " + this->appcastSrc);
			ofLog(OF_LOG_VERBOSE, "Internet-Connection: " + ofToString(this->internetConnection));
			ofLog(OF_LOG_VERBOSE, "-------------------------------------------------------------------------------\n");
		#endif*/
		
		message = "Initialized";
		mode = DEFAULT;
		
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
	
	
	/**
	 * getAppName
	 */
	string ofxAppUpdater::getAppName(){
		string appPath = ofFilePath::getCurrentExePath();
		vector <string> te;
		te = ofSplitString(appPath, "/");
		//cout << ofToString(ofSplitString(appPath, "/")) << endl;
		//cout << "### " << te[te.size()-1] << endl;
		
		return ofToString(te[te.size()-1]);
	}
	
	
	
	/**
	 * checking
	 *
	 * @param return
	 *        LATEST_RELEASE
	 *        NEW_RELEASE
	 *        FINISHED
	 */
	int ofxAppUpdater::checkVersion(ofxXmlSettings xml){
		
		latestVersion = appcast.getAppcastVersion(xml, 0);
		
		// Check the Version numbers if it's false, you can download a new version.
		if(latestVersion == currentVersion){
			// change mode.
			mode = LATEST_RELEASE;
			message = "You're running the latest Application Release!";
			return LATEST_RELEASE;
			
			#ifdef OFXAPPUPDATER_LOG
				ofLog(OF_LOG_VERBOSE, "Message: "+message);
				ofLog(OF_LOG_VERBOSE, "-------------------------------------------------------------------------------\n");
			#endif
		} else {
			if(latestVersion == "0xDEADC0DE"){
				latestVersion  = "0xDEADC0DE";
				// change mode.
				mode = FINISHED;
				message = "ERROR! Something went wrong with your Appcast content.";
				return FINISHED;
				
				#ifdef OFXAPPUPDATER_LOG
					ofLog(OF_LOG_VERBOSE, "Message: "+message);
					ofLog(OF_LOG_VERBOSE, "-------------------------------------------------------------------------------\n");
				#endif
			} else {
				// change mode.
				mode = NEW_RELEASE;
				message = "A new Version is Available!";
				return NEW_RELEASE;
			
				#ifdef OFXAPPUPDATER_LOG
					ofLog(OF_LOG_VERBOSE, "Message: "+message);
					ofLog(OF_LOG_VERBOSE, "-------------------------------------------------------------------------------\n");
				#endif
			}
		}
		
	}
	
	/*
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
				latestVersion  = " ";
				// change mode.
				mode = FINISHED;
				message = "ERROR! Something went wrong with your Appcast content.";
				
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
	*/
	
	
	
	
	
	
	
	
	
	
	/**
	 *
	 */
	void ofxAppUpdater::download(string downloadUrl, string src){
		
		message = "Start Download";
		loadFile(downloadUrl, src);
		message = "downloading...";
		ofSleepMillis(200);
		message = "Download Ready!";
		mode = FINISHED;
		
	}
	
	/*void ofxAppUpdater::download(){
		
		//download(ofFilePath::getPathForDirectory("~/Downloads/")+temporaryDownloadFilename);
		download(ofFilePath::getCurrentWorkingDirectory()+temporaryDownloadFilename);
	}*/
	
	
	
	/**
	 * 
	 */
	void ofxAppUpdater::relaunch(){
		
		//if(internetConnection == true && mode == DOWNLOAD){
			
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
		//}
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
	 * @param return
	 *        
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
		
		mode = DOWNLOADING;
	}
	
	
	
}
