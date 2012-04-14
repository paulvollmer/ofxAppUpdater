# ofxAppUpdater


## Readme  
General information about ofxAppUpdater.  
  
AT THE MOMENT THIS ADDON IS PURE BETA. WORK IN PROGRESS...  
  
ofxAppUpdater is an addons for [openFrameworks](http://www.openframeworks.cc/) to manage application updates.    


<pre>
	
DOWNLOAD PROCESS
	
    +-------------------+ // The Application is started.
+-->| Start Application | // At Application setup(), the ofxUpdater
|   +-------------------+ // will be initialized.
|            |
|            V
|   +---------------+ // load a xml file from server.
|   | load xml file | // At this file we have all information
|   +---------------+ // to check the Application version.
|            |
|            V
|   +---------------+ // Check the actualy version (for this we read the loaded xml file).
|   | check version | // If a new version is available,
|   +---------------+ // go to download alert.
|      |        |
|      V        V
|   +----+  +-------------+
|   | ok |  | old version |
|   +----+  +-------------+
|      |          |
|      |          V
|      |    +----------------+
|      |    | Download alert | ! TODO !
|      |    +----------------+
|      |       |       |
|      |       V       V
|      |    +----+  +-----+
|      |    | No |  | Yes | ! TODO !
|      |    +----+  +-----+
|      |      |        |
|      |      |        V
|      |      |     +----------------+
|      |      |     | Start Download |
|      |      |     +----------------+
|      |      |             |
|      |      |             V
|      |      |     +------------------+
|      |      |     | Run Shell Script |
|      |      |     +------------------+
|      |      |             |
|      V      V             |
|   +-----------------+     |
|   | Run Application |     |
|   +-----------------+     |
|                           |
+---------------------------+

</pre>

**VERSION-INFO XML FILE**

	<VERSIONING>
		<VERSION>1.1</VERSION>
		<MODIFIED>2012.04.04</MODIFIED>
		<AUTHOR>Paul Vollmer, wng.cc</AUTHOR>
		<CHANGES>A small description of the changes.</CHANGES>
	</VERSIONING>
	
	Description of the XML tags.
	----------------------------
	<VERSIONING>
		This is our main tag for the Version-Info File.
		We use this tag for xml parsing.
	<VERSION>
		This tag contains the latest Application version.
	<MODIFIED>
		This tag contains the last Modified-Date.
	<AUTHOR>
		This tag contains the name of the Author/Company.
	<CHANGES>
		This tag contains a string of changes.


ofxAppUpdater is developed by Paul Vollmer http://wrong-entertainment.com/  
The ofxAppUpdater Project Page is Hosted at http://wrongentertainment.github.com/ofxAppUpdater/  
Check out for New released Version at https://github.com/wrongentertainment/ofxAppUpdater/  

This file is part of ofxAppUpdater.  
Author: Paul Vollmer, Modified: 2012.04.14  


## Versioning 
ofxAppUpdater is stable and versioned using [semantic versioning](http://semver.org/).  
Current version: 1.0.1  


## Authors
Paul Vollmer  
Mail: paul.vollmer@fh-potsdam.de  
Url: http://www.wrong-entertainment.com  
Github: http://www.github.com/wrongentertainment  


## Thanks
Thanks to the creative coding community, Processing and openFrameworks for developing great libraries.  
Thanks to Tim Pulver, Gabriel Credico, Steffen Hänsch, Dimitar Ruszev and all the other guys.  


## Install
Here is a small installation instruction.  
Check install.xml files.    

Platform:
MacOS 10.6  
Dependencies:
openFrameworks version 0.07  


## License 
ofxAppUpdater is Licensed under the GNU Lesser General Public License: http://www.opensource.org/licenses/LGPL-3.0  

Copyright (c) 2012 wrong-entertainment.com, all rights reserved.  


## Changelog
A detailed changelog, intended for programmers.  

- 0.1.0  
  starting addon Repository  
- 1.0.1  
  first beta test  
  for this we create a "release_storage" directory and add versioninfo.xml, release.zip  
  (the versioninfo.xml can also used as a changelog history)  


## Bugs  
You can find a list of all known bugs at  
https://github.com/wrongentertainment/ofxAppUpdater/issues  

If you want to reporting a new Bug, create a new Issue at  
https://github.com/wrongentertainment/ofxAppUpdater/issues  
