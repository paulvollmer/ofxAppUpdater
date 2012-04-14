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
 * @modified    2012.04.14
 * @version     1.0.1a
 */



#include "ofxAppUpdater.h"

#include "ofxXmlSettings.h"



namespace wng {
	
	/**
	 * A Constructor, usually called to initialize and start the class.
	 */
	ofxAppUpdater::ofxAppUpdater(){
		
		// Set the internetConnection variable to false. 
		// If you want to manually, set the internetConnection variable,
		// change it at openFrameworks setup.
		internetConnection = false;
		
		// We use the draw mode to design different ofxAppUpdater mode states.
		// See at example draw.
		mode = 0;
		
		/*
		#ifdef OFXAPPUPDATER_LOG
			ofSetLogLevel(OF_LOG_VERBOSE);
			ofLog(OF_LOG_VERBOSE, "Constructor Ready! ");
		#endif
		*/
	}


	
	
	
	/**
	 * initialize
	 *
	 * @param currentVersion
	 *        The current Application Version.
	 *        Like this: "1.0.0"
	 * @param serverUrl
	 *        The url of the server to load the files.
	 *        Like this: "http://www.wrong-entertainment.com/appupdate"
	 * @param versionInfoXml
	 *        The name of our version information xml file.
	 *        Like this: "versioninfo.xml"
	 * @param latestZip
	 *        The name of the zip file.
	 *        Like this: "latest.zip"
	 */
	void ofxAppUpdater::init(string currentVersion, string serverUrl, string versionInfoXml, string latestZip){
		
		this->currentVersion = currentVersion;
		this->serverUrl = serverUrl;
		this->versionInfoXml = versionInfoXml;
		this->latestZip = latestZip;
		
		#ifdef OFXAPPUPDATER_LOG
			ofSetLogLevel(OF_LOG_VERBOSE);
			ofLog(OF_LOG_VERBOSE, "[ofxAppUpdater] init() Current-Version: " + this->currentVersion + ", Server-Url: " + this->serverUrl + ", Version-Info-XML: " + this->versionInfoXml + ", Latest-ZIP: " + this->latestZip);
		#endif
		
	}
	
	
	
	
	
	/**
	 * checking
	 */
	void ofxAppUpdater::checking(){
		
		#ifdef OFXAPPUPDATER_LOG
			ofSetLogLevel(OF_LOG_VERBOSE);
			ofLog(OF_LOG_VERBOSE, "[ofxAppUpdater] check() Start");
		#endif
		
		// At the moment we create a file at he same directory like the app.
		// after parsing the xml, we remove file.
		string tempFile = ofFilePath::getCurrentWorkingDirectory()+"tempVersionInfo.xml";
		loadFile(serverUrl+versionInfoXml, tempFile);
		
		ofSleepMillis(200);
		
		parseXML(tempFile);
		
		ofSleepMillis(200);
		
		ofFile tempXmlFile;
		tempXmlFile.removeFile(tempFile, true);
		
		
		// Check the Version numbers if it's false, you can download a new version.
		if(checkVersion(currentVersion, latestVersion) == true){
			// go to draw mode 1
			mode = 1;
			
		} else {
			// go to draw mode 2
			mode = 2;
		}
		
		
	}
	
	
	
	
	/**
	 *
	 */
	void ofxAppUpdater::downloading(){
		
		//ofSetLogLevel(OF_LOG_VERBOSE);
		//ofLog(OF_LOG_VERBOSE, "downloading");
		
		if(mode == 2){
			
			// At the moment we create a file at he same directory like the app.
			//string tempFile = ofFilePath::getPathForDirectory("~/Desktop")+"tempDownloadfile.zip";
			string tempFile = ofFilePath::getPathForDirectory("~/Desktop")+latestZip;
			
			loadFile(serverUrl+latestZip, tempFile);
			
			ofSleepMillis(2000);
			
			mode = 3;
		}
		
	}
	
	
	
	/**
	 * 
	 */
	void ofxAppUpdater::restart(){
		
		if(mode == 3){
			//string t = ofFilePath::getPathForDirectory("~/Desktop/")+"tempDownloadfile.zip";
			string tempFile = ofFilePath::getPathForDirectory("~/Desktop/")+latestZip;
			#ifdef OFXAPPUPDATER_LOG
				cout << "unzip <" << tempFile << ">\n";
			#endif
			
			unzip(tempFile);
		
			mode = 4;
			
			ofExit(1);
		}
	}
	
	
	
	
	
	/**
	 * checkVersion
	 *
	 * @param currentVer
	 *        Float of the Current-Version.
	 * @param latestVer
	 *        Float of the Latest-Version.
	 * @return bool
	 *         True if the Version is the latest.
	 */
	bool ofxAppUpdater::checkVersion(string currentVer, string latestVer){
		
		if(currentVer == latestVer){
			
			/*#ifdef OFXAPPUPDATER_LOG
			ofSetLogLevel(OF_LOG_VERBOSE);
			ofLog(OF_LOG_VERBOSE, "[ofxUpdater] checkVersion() Current-Version: " + ofToString(currentVer) + " Latest-Version: " + ofToString(latestVer));
			ofLog(OF_LOG_VERBOSE, "                            State: You're running the latest Application Release.");
			#endif*/
			return true;
			
		} else {
			
			/*#ifdef OFXAPPUPDATER_LOG
			ofSetLogLevel(OF_LOG_VERBOSE);
			ofLog(OF_LOG_VERBOSE, "[ofxUpdater] checkVersion() Current-Version: " + ofToString(currentVer) + " Latest-Version: " + ofToString(latestVer));
			ofLog(OF_LOG_VERBOSE, "                            State: A new Version is Available.");
			#endif*/
			return false;
			
		}
		
	}
	
	
	
	
	
	/**
	 * parseXML
	 */
	void ofxAppUpdater::parseXML(string filename){
		
		#ifdef OFXAPPUPDATER_LOG
			ofSetLogLevel(OF_LOG_VERBOSE);
			ofLog(OF_LOG_VERBOSE, "[ofxUpdater] parseXML() Start");
		#endif
		
		
		//  Create a new ofxXmlSettings object for reading the saved file.		
		ofxXmlSettings xml;
		
		// We load our xml file.
		// This is based on the openFrameworks xmlSettingsExample.
		if(xml.loadFile(filename)){
			latestVersion = xml.getValue("VERSIONING:VERSION",  "1.0.0", 0);
			modifiedDate  = xml.getValue("VERSIONING:MODIFIED", "1970.01.01", 0);
			author        = xml.getValue("VERSIONING:AUTHOR",   "wng.cc", 0);
			changes       = xml.getValue("VERSIONING:CHANGES",  "nothing", 0);
			#ifdef OFXAPPUPDATER_LOG
			ofLog(OF_LOG_VERBOSE, "parseXML() File <" + filename + "> loaded!");
			ofLog(OF_LOG_VERBOSE, "Latest Version: " + latestVersion);
			ofLog(OF_LOG_VERBOSE, "Modified: " + modifiedDate);
			ofLog(OF_LOG_VERBOSE, "Author: " + author);
			ofLog(OF_LOG_VERBOSE, "Changes: " + changes);
			#endif
		} else {
			#ifdef OFXAPPUPDATER_LOG
				ofLog(OF_LOG_VERBOSE, "parseXML() File <" + filename + "> not found");
			#endif
		}
		
	}
	
	
	
	
	
	/**
	 * loadFile
	 */
	void ofxAppUpdater::loadFile(string serverSrc, string tempFilepath){
		
		// A path and name for the file we load from server. 
		// I think we can handle this as an intern variable.
		//string tempFilename = "tempVersioninfo.xml";
		
		
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
		string tempApplescript = "osascript -e 'tell app \"URL Access Scripting\" \n download \""+serverSrc+"\" to file \""+tempFilepath+"\" replacing yes \n end tell'";
		system(tempApplescript.c_str());
		
	}
	
	
	/**
	 * unzip
	 */
	void ofxAppUpdater::unzip(string src){
		
		// unzip file
		#ifdef TARGET_OSX
			// ok gotta be a better way then this,
			// this is what I found...
			string commandStr = "open /Users/wrongMacBookpro/Desktop/"+latestZip;
			system(commandStr.c_str());
		#endif
		
		
		ofSleepMillis(4000);
		
		// Delete downloaded zip file.
		ofFile tempXmlFile;
		tempXmlFile.removeFile("/Users/wrongMacBookpro/Desktop/"+latestZip	, true);
		
		// Move downloaded file to current working directory.
		
		
	}
	
	
}
