#pragma once

#include "ofMain.h"
#include "player.h"
#include "astro.h"

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

	Player alien = Player(ofVec2f(10, 20), 200, "alien.png");
	Astro earth = Astro(ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2), 500, "terra.png");
	Astro moon = Astro(ofVec2f(100, 100), 50, "moon_full.png");
};
