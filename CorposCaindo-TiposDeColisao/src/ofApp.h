#pragma once

#include "ofMain.h"

#include "Body.h"
#include "Circ.h"
#include "Quad.h"
#include "Tri.h"


class ofApp : public ofBaseApp{

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		float gravity = 1.0f;

		Quad quadrado = Quad(ofVec2f(700, 150), ofVec2f(0, 0), 100);	
		Circ circulo = Circ(ofVec2f(300, 150), ofVec2f(0, 0), 80);
		Tri triangulo = Tri(ofVec2f(100, 150), ofVec2f(0, 0), 70);

		vector <Body> bodies;
		
};
