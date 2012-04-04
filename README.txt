

ofxUpdater


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