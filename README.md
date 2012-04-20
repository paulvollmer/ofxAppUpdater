# ofxAppUpdater

**General Information**  
AT THE MOMENT THIS ADDON IS PURE ALPHA. WORK IN PROGRESS...  
[openFrameworks](http://www.openframeworks.cc/) addon for application update management.  
With this addon you can Release your openFrameworks Application with an update feature. This can be a solution to manage your Application updates or Test and Debug with a lot of users. If a new Release version is ready to ship, you can upload your zip file and link to it.  
This file must be linked to download and install the new version without errors.  

Addon documentation can be found at [GitHub wiki](https://github.com/WrongEntertainment/ofxAppUpdater/wiki).  


Current version: 1.0.1  
ofxCsv is stable and versioned using [semantic versioning](http://semver.org/).  

Tested Platform: MacOS 10.6  
Dependencies: openFrameworks version 0.07  

**Issues and Bugs**  
You can find a list of all known bugs at [GitHub](https://github.com/wrongentertainment/ofxAppUpdater/issues). Please report if you find an unknown bug.  

Modified: 2012.02.06  

## Changelog
A detailed changelog, intended for programmers.  


1.0.1  
first beta test (for this we create a "release_storage" directory and add versioninfo.xml, release.zip.  
added enum for different modes (CHECK, DOWNLOAD, RELAUNCH)  
create autoUpdate method (method to start the update at setup)  
create example_autoUpdate, rename and clear first example.  
The versioninfo.xml file can also used as a changelog history)      

0.1.0  
- starting addon Repository  

## Author  
ofxAppUpdater is developed by Paul Vollmer http://wrong-entertainment.com/  
Check out for new release at https://github.com/wrongentertainment/ofxAppUpdater/  

Mail: paul.vollmer@fh-potsdam.de  
Url: http://www.wrong-entertainment.com  
Github: http://www.github.com/wrongentertainment  


## License 
ofxAppUpdater is Licensed under the GNU Lesser General Public License: http://www.opensource.org/licenses/LGPL-3.0