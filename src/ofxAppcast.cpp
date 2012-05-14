/**
 * ofxAppcast.cpp is developed by Paul Vollmer
 * http://www.wng.cc
 * 
 * 
 * Copyright (c) 2012 Paul Vollmer
 *
 * ofxAppcast.cpp is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * ofxAppcast.cpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General
 * Public License along with ofxAppcast.cpp; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 * 
 * @author      Paul Vollmer
 * @modified    2012.04.26
 * @version     1.0.1e2
 */



#include "ofxAppcast.h"


namespace wng {
	
	ofxAppcast::ofxAppcast(){}
	
	
	
	/**
	 * Get the total number of 'rss:channel:item' tags
	 *
	 * @param xml
	 *        An ofxXmlSettings object.
	 * @param return
	 *        Number of items as an integer.
	 */
	int ofxAppcast::getNumItems(ofxXmlSettings xml){
		return xml.getNumTags("rss:channel:item");
	}
	
	
	
	/**
	 * Get a tag from our first channel.
	 *
	 * @param xml
	 *        An ofxXmlSettings object.
	 * @param return
	 *        string.
	 */
	string ofxAppcast::getChannelTitle(ofxXmlSettings xml){
		return ofToString(xml.getValue("rss:channel:title", "not available", 0));
	}
	
	string ofxAppcast::getChannelLink(ofxXmlSettings xml){
		return ofToString(xml.getValue("rss:channel:link", "not available", 0));
	}
	
	string ofxAppcast::getChannelDescription(ofxXmlSettings xml){
		return ofToString(xml.getValue("rss:channel:description", "not available", 0));
	}
	
	string ofxAppcast::getChannelLanguage(ofxXmlSettings xml){
		return ofToString(xml.getValue("rss:channel:language", "not available", 0));
	}
		
	string ofxAppcast::getChannelPubDate(ofxXmlSettings xml){
		return ofToString(xml.getValue("rss:channel:pubDate", "not available", 0));
	}
	
	
	
	/**
	 * Get a tag from selected item.
	 *
	 * @param xml
	 *        An ofxXmlSettings object.
	 * @param return
	 *        string.
	 */
	string ofxAppcast::getTitle(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:title", "not available", which));
	}
	
	string ofxAppcast::getDescription(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:description", "not available", which));
	}
	
	string ofxAppcast::getPubDate(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:pubDate", "not available", which));
	}
	
	string ofxAppcast::getEnclosureUrl(ofxXmlSettings xml, int which){
		return ofToString(xml.getAttribute("rss:channel:item:enclosure", "url", "not available", which));
	}
	
	string ofxAppcast::getEnclosureType(ofxXmlSettings xml, int which){
		return ofToString(xml.getAttribute("rss:channel:item:enclosure", "type", "not available", which));
	}
	
	
	
	/**
	 * Get a Appcast tag from selected item.
	 *
	 * @param xml
	 *        An ofxXmlSettings object.
	 * @param return
	 *        string.
	 */
	string ofxAppcast::getAppcastVersion(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastVersion", "not available", which));
	}
	
	string ofxAppcast::getAppcastAuthor(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastAuthor", "not available", which));
	}
	
	string ofxAppcast::getAppcastAuthorUrl(ofxXmlSettings xml, int which){
		return ofToString(xml.getAttribute("rss:channel:item:appcastAuthor", "url", "not available", which));
	}
	
	string ofxAppcast::getAppcastAuthorEmail(ofxXmlSettings xml, int which){
		return ofToString(xml.getAttribute("rss:channel:item:appcastAuthor", "email", "not available", which));
	}
	
	string ofxAppcast::getAppcastShortDescription(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastShortDescription", "not available", which));
	}
	
	string ofxAppcast::getAppcastLicense(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastLicense", "not available", which));
	}
	
	string ofxAppcast::getAppcastLicenseUrl(ofxXmlSettings xml, int which){
		return ofToString(xml.getAttribute("rss:channel:item:appcastLicense", "url", "not available", which));
	}
	
	string ofxAppcast::getAppcastHash(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastHash", "not available", which));
	}
	
	string ofxAppcast::getAppcastHashAlgo(ofxXmlSettings xml, int which){
		return ofToString(xml.getAttribute("rss:channel:item:appcastHash", "algo", "not available", which));
	}
	
	string ofxAppcast::getAppcastRating(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastRating", "not available", which));
	}
	
	string ofxAppcast::getAppcastRatingVotes(ofxXmlSettings xml, int which){
		return ofToString(xml.getAttribute("rss:channel:item:appcastRating", "votes", "not available", which));
	}
	
	string ofxAppcast::getAppcastDownloadCount(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastDownloadCount", "not available", which));
	}
	
	string ofxAppcast::getAppcastKeywords(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastKeywords", "not available", which));
	}
	
	string ofxAppcast::getAppcastDocsLink(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastDocsLink", "not available", which));
	}
	
	string ofxAppcast::getAppcastSourcesLink(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastSourcesLink", "not available", which));
	}
	
	string ofxAppcast::getAppcastPreviewLink(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastPreviewLink", "not available", which));
	}
	
	
}
