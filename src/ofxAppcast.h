/**
 * ofxAppcast.h is developed by Paul Vollmer
 * http://www.wng.cc
 * 
 * 
 * Copyright (c) 2012 Paul Vollmer
 *
 * ofxAppcast.h is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * ofxAppcast.h is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General
 * Public License along with ofxAppcast.h; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 * 
 * @author      Paul Vollmer
 * @modified    2012.04.24
 * @version     1.0.1d2
 */



#pragma once

#include <ofMain.h>
#include "ofxXmlSettings.h"





namespace wng {
	
	
	class ofxAppcast {
		
	public:
		ofxAppcast();
		
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
