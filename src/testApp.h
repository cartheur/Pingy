#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "PingyControlPanel.h"

class testApp : public ofBaseApp{
	public:
		testApp();
	
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// main gui
		ofxUICanvas mainGui;
		void mainGuiEvent(ofxUIEventArgs &e);

		// panels
		vector<PingyControlPanel*> thePanels;

	protected:
		void adjustPanels();
		string fitStringToWidth(const string s, const int w, ofTrueTypeFont ttf);
};
