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
 * @modified    2012.04.04
 * @version     0.1.0
 */



#include "ofxAppUpdater.h"
#include "ofxXmlSettings.h"



namespace wng {
	
	/**
	 * A Constructor, usually called to initialize and start the class.
	 */
	ofxAppUpdater::ofxAppUpdater(){
		
		/* Set the internetConnection variable to true 
		 * This we need for an automatic update. If you want to manually,
		 * set the internetConnection variable at setup to false */
		internetConnection = true;
		
		
		#ifdef DEBUG
			printf("[ofxAppUpdater] Constructor Ready! \n");
		#endif
		
	}


	
	
	
	/**
	 * Load a CSV File.
	 *
	 * @param userVer
	 *        User Version.
	 * @param connection
	 *        internet Connection boolean.
	 * @param file
	 *        Our update information xml filename.
	 * @param url
	 *        The url of the server/folder to load the file.
	 */
	void ofxAppUpdater::init(float userVer, bool connection, string file, string url){
		
		/* Get the Unixtime */
		int ut = ofGetUnixTime();
		
		/* Set version variables. */
		userVersion = userVer;
		internetConnection = connection;
		
		#ifdef DEBUG
			printf("[ofxAppUpdater] init() Unixtime: %d \n", ut);
			printf("                    Internet Connection: %s \n", (internetConnection)?"true":"false");
			printf("                    User Version: %f \n", userVersion);
			cout <<"                    Filename: " << file << endl;
			cout <<"                    Url: " << url << endl;
		#endif
		
		
		/* if the internetConnection is true, we can check an xml file
		 * to get the latest version. */
		if (internetConnection == true){
			
			/* A path and name for the file we load from server. 
			 * I think we can handle this as an intern variable.*/
			string tempFilename = "tempVersion.xml";
			
			/* Copy our version xml file to data folder. */
			ofSaveURLTo(url+file, tempFilename);
			
			
			/* create a new ofxXmlSettings object for reading the saved file. */			
			ofxXmlSettings xml;
			
			/* we load our xml file
			 * Examlple from openFrameworks xmlSettingsExample */
			if(xml.loadFile(tempFilename)){
				#ifdef DEBUG 
					cout << "                    XML: File <" << file << "> loaded!" << endl;
				#endif
				
				float tempVersion = xml.getValue("VERSIONING:VERSION", 0.0, 0);
				string tempModified = xml.getValue("VERSIONING:MODIFIED", "1970.01.01", 0);
				string tempAuthor = xml.getValue("VERSIONING:AUTHOR", "wng.cc", 0);
				#ifdef DEBUG 
					cout << "                         VERSIONING:VERSION  = " << tempVersion << endl;
					cout << "                         VERSIONING:MODIFIED = " << tempModified << endl;
					cout << "                         VERSIONING:AUTHOR   = " << tempAuthor << endl;
				#endif
				
				/* Check the Version numbers if it's true. */
				if(checkVersion(userVersion, tempVersion)){
					
					/* Start downloading zip package. */
					
				}
				
			} else {
				#ifdef DEBUG
					cout << "              File not found" << endl;
				#endif
			}

		}
		
	}
	
	/**
	 * See decription below.
	 */
	void ofxAppUpdater::init(float userVer, string file, string url){
		init(userVer, true, file, url);
	}
	
	
	
	/**
	 * checkversion
	 *
	 * @param userVer
	 *        Float of the User-Version
	 * @param latestVer
	 *        Float of the Latest-Version
	 * @return bool
	 *         true if the Version is the latest.
	 */
	bool ofxAppUpdater::checkVersion(float userVer, float latestVer){
	
		if (userVer == latestVer) {
			#ifdef DEBUG
				printf("[ofxUpdater] checkVersion() User-Version: %f Latest-Version: %f \n", userVer, latestVer);
				printf("                            State: You're running the newest Application Release. \n");
			#endif
			return true;
		} else {
			#ifdef DEBUG
				printf("[ofxUpdater] checkVersion() User-Version: %f Latest-Version: %f \n", userVer, latestVer);
				printf("                            State: A new Version is Available. \n");
			#endif
			return false;
		}
		
	}
	
	
}
