#pragma once

#include "ofMain.h"
#include "player.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofVec2f mouse;
	bool mouseIsDown;
	ofImage wall, piramid, moon;
	Player alien = Player(ofGetWidth() / 2, ofGetHeight() / 2, "alien.png");

	void Start() {
		ofSetBackgroundColor(0, 0, 0);
		wall.load("Wall.png");
		moon.load("moon.png");
		piramid.load("piramid.png");
		alien.pos.set(ofGetWidth() / 2, ofGetHeight() / 2);
		alien.vel.set(0, 0);
	}
	
};
