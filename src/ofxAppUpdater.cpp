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
 * @modified    2012.04.12
 * @version     0.1.0b
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
		
		#ifdef OFXAPPUPDATER_LOG
			ofSetLogLevel(OF_LOG_VERBOSE);
			ofLog(OF_LOG_VERBOSE, "[ofxAppUpdater] " + ofGetTimestampString() + " Constructor Ready! ");
		#endif
		
	}


	
	
	
	/**
	 * initialize
	 *
	 * @param currentVersion
	 *        The current Application Version.
	 *        Like this: 1.0
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
	void ofxAppUpdater::init(float currentVersion, string serverUrl, string versionInfoXml, string latestZip){
		
		this->currentVersion = currentVersion;
		this->serverUrl = serverUrl;
		this->versionInfoXml = versionInfoXml;
		this->latestZip = latestZip;
		
		#ifdef OFXAPPUPDATER_LOG
			ofSetLogLevel(OF_LOG_VERBOSE);
			ofLog(OF_LOG_VERBOSE, "[ofxAppUpdater] init()");
			ofLog(OF_LOG_VERBOSE, "-> Current-Version:  " + ofToString(this->currentVersion));
			ofLog(OF_LOG_VERBOSE, "-> Server-Url:       " + this->serverUrl);
			ofLog(OF_LOG_VERBOSE, "-> Version-Info-XML: " + this->versionInfoXml);
			ofLog(OF_LOG_VERBOSE, "-> Latest-ZIP:       " + this->latestZip);
		#endif
		
	}
	
	
	
	
	
	/**
	 * checking
	 */
	void ofxAppUpdater::checking(){
		
		#ifdef OFXAPPUPDATER_LOG
			ofSetLogLevel(OF_LOG_VERBOSE);
			ofLog(OF_LOG_VERBOSE, "[ofxUpdater] check() Start");
		#endif
		
		
		loadFile(serverUrl+versionInfoXml, ofFilePath::getCurrentWorkingDirectory()+"tempVersionInfo.xml");
		parseXML(ofFilePath::getCurrentWorkingDirectory()+"tempVersionInfo.xml");
		ofFile tempXmlFile;
		tempXmlFile.removeFile("tempVersioninfo.xml", true);
		
		
		
		
		
		// Check the Version numbers if it's false, you can download a new version.
		if(checkVersion(currentVersion, latestVersion) == false){
			#ifdef OFXAPPUPDATER_LOG
				ofLog(OF_LOG_VERBOSE, ofGetTimestampString() + " Start downloading zip file.");
			#endif
			
			// Create a temporary zip filename. 
			// Setting the name of the downloaded zip file.
			string tempZipFilename = "tempDownload.zip";
			// Start downloading zip package.
			//ofSaveURLTo(url+"test.zip", tempZipFilename);
			
			loadFile(serverUrl+latestZip, ofFilePath::getCurrentWorkingDirectory()+"tempDownload.zip");
			
			#ifdef OFXAPPUPDATER_LOG
				ofLog(OF_LOG_VERBOSE, ofGetTimestampString() + " Start downloading zip file.");
			#endif
			// We have to unzip the downloaded file.
			//ofxUnZip("tempDownload.zip", "wng_test");
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
	bool ofxAppUpdater::checkVersion(float currentVer, float latestVer){
		
		if (currentVer == latestVer) {
			
			#ifdef OFXAPPUPDATER_LOG
			ofSetLogLevel(OF_LOG_VERBOSE);
			ofLog(OF_LOG_VERBOSE, "[ofxUpdater] checkVersion() Current-Version: " + ofToString(currentVer) + " Latest-Version: " + ofToString(latestVer));
			ofLog(OF_LOG_VERBOSE, "                            State: You're running the latest Application Release.");
			#endif
			return true;
			
		} else {
			
			#ifdef OFXAPPUPDATER_LOG
			ofSetLogLevel(OF_LOG_VERBOSE);
			ofLog(OF_LOG_VERBOSE, "[ofxUpdater] checkVersion() Current-Version: " + ofToString(currentVer) + " Latest-Version: " + ofToString(latestVer));
			ofLog(OF_LOG_VERBOSE, "                            State: A new Version is Available.");
			#endif
			return false;
			
		}
		
	}
	
	
	
	
	
	
	
	
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
			#ifdef OFXAPPUPDATER_LOG 
				ofLog(OF_LOG_VERBOSE, "XML: File <" + filename + "> loaded!");
			#endif
			
			latestVersion = xml.getValue("VERSIONING:VERSION",  0.0,          0);
			modifiedDate  = xml.getValue("VERSIONING:MODIFIED", "1970.01.01", 0);
			author        = xml.getValue("VERSIONING:AUTHOR",   "wng.cc",     0);
			changes       = xml.getValue("VERSIONING:CHANGES",  "nothing",    0);
			#ifdef OFXAPPUPDATER_LOG
				ofLog(OF_LOG_VERBOSE, "-> Latest Version = " + ofToString(latestVersion));
				ofLog(OF_LOG_VERBOSE, "-> Modified       = " + modifiedDate);
				ofLog(OF_LOG_VERBOSE, "-> Author         = " + author );
				ofLog(OF_LOG_VERBOSE, "-> Changes        = " + changes);
			#endif
		} else {
			#ifdef OFXAPPUPDATER_LOG
				ofLog(OF_LOG_VERBOSE, "XML: File <" + filename + "> not found");
			#endif
		}
		
	}
	
	
	
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
		
		//string tempUrl = "http://www.wrong-entertainment.com/code/wngUpdater/versioninfo.xml";
		//string tempFilepath = ofFilePath::getCurrentWorkingDirectory()+tempFilename;
		
		string tempApplescript = "osascript -e 'tell app \"URL Access Scripting\" \n download \""+serverSrc+"\" to file \""+tempFilepath+"\" replacing yes \n end tell'";
		system(tempApplescript.c_str());
		
	}
	
	
	
	
	
	
	
	
	
	
	/**
	 * init
	 *
	 * @param userVer
	 *        User Version.
	 * @param file
	 *        Our update information xml filename.
	 * @param url
	 *        The url of the server/folder to load the file.
	 * @param connection
	 *        internet Connection boolean.
	 */
	void ofxAppUpdater::test(float userVer, string file, string url, string zip, bool connection){
		
		// Get the Timestamp
		string timestamp = ofGetTimestampString();
		
		// Set version variables.
		//currentVersion = userVer;
		//internetConnection = connection;
		
		/*#ifdef OFXAPPUPDATER_LOG
			ofSetLogLevel(OF_LOG_VERBOSE);
			ofLog(OF_LOG_VERBOSE, "[ofxAppUpdater] " + ofGetTimestampString() + " init()");
			ofLog(OF_LOG_VERBOSE, "-> Internet Connection: " + internetConnection);
			ofLog(OF_LOG_VERBOSE, "-> User Version:        " + ofToString(userVersion));
			ofLog(OF_LOG_VERBOSE, "-> Filename:            " + file);
			ofLog(OF_LOG_VERBOSE, "-> Server-Url:          " + url);
		#endif*/
		
		
		// if the internetConnection is true, we can check an xml file
		// to get the latest version.
		if (internetConnection == true){
			
			// A path and name for the file we load from server. 
			// I think we can handle this as an intern variable.
			string tempFilename = "tempVersioninfo.xml";
			/*
			
			
			// Xml file download
			//
			// Soluion 1:
			// use openFrameworks to download our xml file.
			
			//cout << ofGetTimestampString() << " DOWNLOAD XML FILE START." << endl;
			// Copy our version xml file to data folder.
			ofSaveURLAsync(url+file, tempFilename);
			//cout << ofGetTimestampString() << " DOWNLOAD XML FILE READY." << endl;	
			
			
			// Solution 2:
			// we use applescript to download our xml file.
			//
			// Here is the original applescript
			// 
			// tell application "URL Access Scripting"
			// download "http://www.wrong-entertainment.com/code/wngUpdater/versioninfo.xml" to file "/testfile.txt" replacing yes
			// end tell
			string tempUrl = "http://www.wrong-entertainment.com/code/wngUpdater/versioninfo.xml";
			string tempFilepath = ofFilePath::getCurrentWorkingDirectory()+"/test_00001.xml";
			
			string tempApplescript = "osascript -e 'tell app \"URL Access Scripting\" \n download \""+tempUrl+"\" to file \""+tempFilepath+"\" replacing yes \n end tell'";
			
			system(tempApplescript.c_str());*/
			
			
			
			
			
			//  Create a new ofxXmlSettings object for reading the saved file.		
			/*ofxXmlSettings xml;
			
			// We load our xml file.
			// Examlple from openFrameworks xmlSettingsExample.
			if(xml.loadFile(tempFilename)){
				#ifdef OFXAPPUPDATER_LOG 
					ofSetLogLevel(OF_LOG_VERBOSE);
					ofLog(OF_LOG_VERBOSE, "XML: File <" + tempFilename + "> loaded!");
				#endif
				
				latestVersion = xml.getValue("VERSIONING:VERSION",  0.0,          0);
				modifiedDate  = xml.getValue("VERSIONING:MODIFIED", "1970.01.01", 0);
				author        = xml.getValue("VERSIONING:AUTHOR",   "wng.cc",     0);
				changes       = xml.getValue("VERSIONING:CHANGES",  "nothing",    0);
				
				#ifdef OFXAPPUPDATER_LOG
					ofLog(OF_LOG_VERBOSE, "-> Latest Version = " + ofToString(latestVersion));
					ofLog(OF_LOG_VERBOSE, "-> Modified       = " + modifiedDate);
					ofLog(OF_LOG_VERBOSE, "-> Author         = " + author );
					ofLog(OF_LOG_VERBOSE, "-> Changes        = " + changes);
				#endif*/
				
				
			
			
			
			
			
			
			
				// Check the Version numbers if it's false, you can download a new version.
				if(checkVersion(currentVersion, latestVersion) == false){
					
					#ifdef OFXAPPUPDATER_LOG
						ofLog(OF_LOG_VERBOSE, ofGetTimestampString() + " Start downloading zip file.");
					#endif
					
					// Create a temporary zip filename. 
					// Setting the name of the downloaded zip file.
					//string tempZipFilename = "tempDownload.zip";
					// Start downloading zip package.
					//ofSaveURLTo(url+"test.zip", tempZipFilename);
					
					#ifdef OFXAPPUPDATER_LOG
						ofLog(OF_LOG_VERBOSE, ofGetTimestampString() + " Start downloading zip file.");
					#endif
					
					// We have to unzip the downloaded file.
					//ofxUnZip("tempDownload.zip", "wng_test");
					
				}

				
			} else {
				#ifdef OFXAPPUPDATER_LOG
					ofSetLogLevel(OF_LOG_VERBOSE);
					ofLog(OF_LOG_VERBOSE, "XML: File <  > not found");
				#endif
			}

		//}
		
		
		/*ofFile tempXmlFile;
		//tempXmlFile.renameTo("test123.xml", true);
		tempXmlFile.removeFile("tempVersioninfo.xml", true);*/
		
		//internetConnection = false;
		
	}
	
	
	
	/**
	 * See decription below.
	 *
	void ofxAppUpdater::test(float userVer, string file, string url, string zip){
		test(userVer, file, url, zip, true);
	}*/
	
	
}
