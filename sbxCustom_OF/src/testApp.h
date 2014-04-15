#pragma once

#include "ofMain.h"
#include "ofxSpacebrew.h"
#include "sbxCustom.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        Spacebrew::Connection sb;
    
        void onMessage( Spacebrew::Message & m );
    
        //in this example we're using sbx Custom to hold 3d screen values: X, Y and Z. We'll later use only X and Y.
        sbx::custom outVec;
        sbx::custom inVec;
};
