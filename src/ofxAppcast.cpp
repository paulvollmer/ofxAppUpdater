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
		return ofToString(xml.getValue("rss:channel:title", OFXAPPCAST_DEFAULT_CONTENT, 0));
	}
	
	string ofxAppcast::getChannelLink(ofxXmlSettings xml){
		return ofToString(xml.getValue("rss:channel:link", OFXAPPCAST_DEFAULT_CONTENT, 0));
	}
	
	string ofxAppcast::getChannelDescription(ofxXmlSettings xml){
		return ofToString(xml.getValue("rss:channel:description", OFXAPPCAST_DEFAULT_CONTENT, 0));
	}
	
	string ofxAppcast::getChannelLanguage(ofxXmlSettings xml){
		return ofToString(xml.getValue("rss:channel:language", OFXAPPCAST_DEFAULT_CONTENT, 0));
	}
		
	string ofxAppcast::getChannelPubDate(ofxXmlSettings xml){
		return ofToString(xml.getValue("rss:channel:pubDate", OFXAPPCAST_DEFAULT_CONTENT, 0));
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
		return ofToString(xml.getValue("rss:channel:item:title", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	string ofxAppcast::getDescription(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:description", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	string ofxAppcast::getPubDate(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:pubDate", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	string ofxAppcast::getEnclosureUrl(ofxXmlSettings xml, int which){
		return ofToString(xml.getAttribute("rss:channel:item:enclosure", "url", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	string ofxAppcast::getEnclosureType(ofxXmlSettings xml, int which){
		return ofToString(xml.getAttribute("rss:channel:item:enclosure", "type", OFXAPPCAST_DEFAULT_CONTENT, which));
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
		return ofToString(xml.getValue("rss:channel:item:appcastVersion", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	string ofxAppcast::getAppcastAuthor(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastAuthor", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	string ofxAppcast::getAppcastAuthorUrl(ofxXmlSettings xml, int which){
		return ofToString(xml.getAttribute("rss:channel:item:appcastAuthor", "url", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	string ofxAppcast::getAppcastAuthorEmail(ofxXmlSettings xml, int which){
		return ofToString(xml.getAttribute("rss:channel:item:appcastAuthor", "email", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	string ofxAppcast::getAppcastShortDescription(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastShortDescription", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	string ofxAppcast::getAppcastLicense(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastLicense", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	string ofxAppcast::getAppcastLicenseUrl(ofxXmlSettings xml, int which){
		return ofToString(xml.getAttribute("rss:channel:item:appcastLicense", "url", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	string ofxAppcast::getAppcastHash(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastHash", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	string ofxAppcast::getAppcastHashAlgo(ofxXmlSettings xml, int which){
		return ofToString(xml.getAttribute("rss:channel:item:appcastHash", "algo", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	string ofxAppcast::getAppcastRating(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastRating", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	string ofxAppcast::getAppcastRatingVotes(ofxXmlSettings xml, int which){
		return ofToString(xml.getAttribute("rss:channel:item:appcastRating", "votes", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	string ofxAppcast::getAppcastDownloadCount(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastDownloadCount", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	string ofxAppcast::getAppcastKeywords(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastKeywords", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	string ofxAppcast::getAppcastDocsLink(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastDocsLink", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	string ofxAppcast::getAppcastSourcesLink(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastSourcesLink", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	string ofxAppcast::getAppcastPreviewLink(ofxXmlSettings xml, int which){
		return ofToString(xml.getValue("rss:channel:item:appcastPreviewLink", OFXAPPCAST_DEFAULT_CONTENT, which));
	}
	
	
}
