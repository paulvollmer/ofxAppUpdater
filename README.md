# ofxAppUpdater


## Readme  
General information about ofxAppUpdater.  
  
AT THE MOMENT THIS ADDON IS NOT READY. WORK IN PROGRESS.  
  
ofxAppUpdater is an addons for [openFrameworks](http://www.openframeworks.cc/) to manage application updates.    


<pre>
	
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
  
ofxAppUpdater is developed by Paul Vollmer http://wrong-entertainment.com/  
The ofxAppUpdater Project Page is Hosted at ...  
Check out for New released Version at https://github.com/wrongentertainment/ofxAppUpdater/  

This file is part of ofxAppUpdater.  
Author: Paul Vollmer, Modified: 2012.04.05  


## Versioning 



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
MacOS  
Dependencies:
openFrameworks version 0.07  


## License 
ofxAppUpdater is Licensed under the GNU Lesser General Public License: http://www.opensource.org/licenses/LGPL-3.0  

Copyright (c) 2012 wrong-entertainment.com, all rights reserved.  


## Changelog
A detailed changelog, intended for programmers.  

- 0.1.0  
  starting addon Repository  


## Bugs  
You can find a list of all known bugs at  
https://github.com/wrongentertainment/ofxAppUpdater/issues  

If you want to reporting a new Bug, create a new Issue at  
https://github.com/wrongentertainment/ofxAppUpdater/issues  
