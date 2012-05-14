/**
 *  ofxAppUpdater.h
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

#pragma once

#include <ofMain.h>
#include "ofxAppcast.h"

#define OFXAPPUPDATER_LOG





namespace wng {
	
	
	// The different mode-states.
	// This we use to set the mode variable after running a mode correctly. 
	// Also we will use the enum for if/else, switch case stuff.
	enum OFXAPPUPDATER_MODE {
			DEFAULT = 0,
			CHECK = 1,
			LATEST_RELEASE = 2,
			NEW_RELEASE = 3,
			DOWNLOAD = 4,
			DOWNLOADING = 41,
			RELAUNCH = 5,
			FINISHED = 6
	};
	
	
	
	class ofxAppUpdater {
		
	public:
		/**
		 * Constructor
		 */
		ofxAppUpdater();
		
		
		/**
		 * Methods
		 */
		void init(string currentVersion, string appcastPath);
		
		int checkVersion(ofxXmlSettings xml);
		void download(string downloadUrl, string src);
		
		
		// TODO check if this is deadcode?
		void loadFile(string serverSrc, string tempFilepath);
		
		
		
		void unzip(string src);
		void relaunch();
		
		int userNotificationDisplay(string header, string message, const string buttonOk, const string buttonCancle, const string buttonAlternate);
		string getAppName();
		
		
		/**
		 * Variables
		 */
		
		// The update modes.
		//
		// This we use to get the current state of the update process.
		// If a process like checking() or downloading() runs correctly,
		// the mode state will be set to the next mode value (OFXAPPUPDATER_MODE enum).
		int mode;
		// Message container for the different modes.
		string message;
		
		
		// The current application version.
		//
		// This variables contains the version of this application and is
		// hard coded at this release.
		// We need it for checking if a new release exist. 
		string currentVersion;
		
		// The Appcast RSS file
		//
		// lastVersion, appcast filepath and ofxAppcast class will be needed by
		// This variables will be filled with the tags from our Appcast RSS file.
		// The variables will be set get.. method by ofxAppcast methods.
		string latestVersion;
		string appcastPath;
		ofxAppcast appcast;
		
		
		
	private:
		// Todo remove this variable.
		string temporaryDownloadFilename;
		
	};

};
