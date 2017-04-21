#include "ofApp.h"

GLfloat lightOnePosition[] = {40.0, 40, 100.0, 0.0};
GLfloat lightOneColor[] = {0.99, 0.99, 0.99, 1.0};

GLfloat lightTwoPosition[] = {-40.0, 40, 100.0, 0.0};
GLfloat lightTwoColor[] = {0.99, 0.99, 0.99, 1.0};
float Y = 80;
float X = 0;

//--------------------------------------------------------------
void ofApp::setup(){	
	mySound.load("spaceship/satisfaction.wav");
	shoot.load("spaceship/laser.wav");
	takeoff.load("spaceship/takeoff.wav");
	
	space.load("spaceship/space.jpg");
	ofSetVerticalSync(true);
    //some model / light stuff
    ofEnableDepthTest();
    glShadeModel (GL_SMOOTH);
	
    /* initialize lighting */
    glLightfv (GL_LIGHT0, GL_POSITION, lightOnePosition);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, lightOneColor);
    glEnable (GL_LIGHT0);
    glLightfv (GL_LIGHT1, GL_POSITION, lightTwoPosition);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, lightTwoColor);
    glEnable (GL_LIGHT1);
    glEnable (GL_LIGHTING);
    glColorMaterial (GL_FRONT_AND_BACK, GL_DIFFUSE);
    glEnable (GL_COLOR_MATERIAL);
	
    //load the spaceship model - the 3ds and the texture file need to be in the same folder
    spaceshipModel.loadModel("spaceship/spaceship.3ds", 20);
	spaceshipModel.setScale(0.9, 0.9, 0.9);
	spaceshipModel.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
	
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	space.draw(0, 0, ofGetWidth(), ofGetHeight());
    //lets tumble the world with the mouse
	std::printf("right % f\n",Y);
	glPushMatrix();

        //draw in middle of the screen
        glTranslatef(ofGetWidth()/2,ofGetHeight()/2,0);
        //tumble according to mouse
        glRotatef(-Y,1,0,0);
        glRotatef(X,0,1,0);
        glTranslatef(-ofGetWidth()/2,-ofGetHeight()/2,0);

        ofSetColor(255, 255, 255, 255);
		spaceshipModel.drawFaces();

    glPopMatrix();

   // ofSetHexColor(0x000000);
    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate(), 2), 10, 15);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){ 
	if (key == OF_KEY_DOWN){
		std::printf("down");
		if (Y < 100) {
			Y = Y + 5;
		}
	}
	if (key == OF_KEY_UP) {
		std::printf("up");
		
		if (Y > -70) {
			Y = Y - 5;
		}
	}
	if (key == OF_KEY_LEFT) {
		std::printf("left");
	
		if (X > 40) {
			X = X - 5;
		}
	}
	if (key == OF_KEY_RIGHT) {
		std::printf("right");
		if (X < 140) {
			X = X + 5;
		}
	}
	if (key == GLFW_KEY_SPACE) {
		takeoff.play();
		if (X == 300 && Y == 360) {
			X = 0;
			Y = 0;
		}
		else {
			X = 300;
			Y = 360;
		}
	}
	if (key == 's') {
		std::printf("spushed");
		shoot.play();
	}
}	

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
