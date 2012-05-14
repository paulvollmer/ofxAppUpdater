/**
 *  ofxAppcast.h
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

#include "ofxXmlSettings.h"





namespace wng {
	
	
	class ofxAppcast {
		
	public:
		ofxAppcast();
		
		int getNumItems(ofxXmlSettings xml);
		
		/**
		 * The get.. methods can be used to parse appcast files.
		 * All the get methods need a xml object to parse from.
		 * More information about appcast can be found at
		 * https://github.com/WrongEntertainment/ofxAppUpdater/wiki
		 */
		string getChannelTitle(ofxXmlSettings xml);
		string getChannelLink(ofxXmlSettings xml);
		string getChannelDescription(ofxXmlSettings xml);
		string getChannelLanguage(ofxXmlSettings xml);
		string getChannelPubDate(ofxXmlSettings xml);
		string getTitle(ofxXmlSettings xml, int which);
		string getDescription(ofxXmlSettings xml, int which);
		string getPubDate(ofxXmlSettings xml, int which);
		string getEnclosureUrl(ofxXmlSettings xml, int which);
		string getEnclosureType(ofxXmlSettings xml, int which);
		string getAppcastVersion(ofxXmlSettings xml, int which);
		string getAppcastAuthor(ofxXmlSettings xml, int which);
		string getAppcastAuthorUrl(ofxXmlSettings xml, int which);
		string getAppcastAuthorEmail(ofxXmlSettings xml, int which);
		string getAppcastShortDescription(ofxXmlSettings xml, int which);
		string getAppcastLicense(ofxXmlSettings xml, int which);
		string getAppcastLicenseUrl(ofxXmlSettings xml, int which);
		string getAppcastHash(ofxXmlSettings xml, int which);
		string getAppcastHashAlgo(ofxXmlSettings xml, int which);
		string getAppcastRating(ofxXmlSettings xml, int which);
		string getAppcastRatingVotes(ofxXmlSettings xml, int which);
		string getAppcastDownloadCount(ofxXmlSettings xml, int which);
		string getAppcastKeywords(ofxXmlSettings xml, int which);
		string getAppcastDocsLink(ofxXmlSettings xml, int which);
		string getAppcastSourcesLink(ofxXmlSettings xml, int which);
		string getAppcastPreviewLink(ofxXmlSettings xml, int which);
		
	};
	
};
