/**
 *  ofxAppcast.cpp
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
