#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(107, 107, 107);
	ofEnableDepthTest();

	box.set(10, 10, 10);
	box.setPosition(0, 0, 0);
	cam.setPosition(0, 0, 20);

	ofDisableArbTex();
	ofLoadImage(tex, "rover.jpg");


	numCols = 100;
	numRows = 100;


	for (int i = 0; i < numCols; i++) {
		for (int k = 0; k < numRows; k++) {
			mesh.addVertex(ofPoint(-numCols / 2 * 10 + (i * 10) + 5, -numRows / 2 * 10 + (k * 10) + 5));
		}
	}

	// Set up triangles' indices
	// only loop to -1 so they don't connect back to the beginning of the row
	for (int x = 0; x < numCols - 1; x++) {
		for (int y = 0; y < numRows - 1; y++) {
			int topLeft = x + numCols * y;
			int bottomLeft = x + 1 + numCols * y;
			int topRight = x + numCols * (y + 1);
			int bottomRight = x + 1 + numCols * (y + 1);

			mesh.addTriangle(topLeft, bottomLeft, topRight);
			mesh.addTriangle(bottomLeft, topRight, bottomRight);

		}
	}


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	cam.begin();
	mesh.drawWireframe();
	tex.bind();
	box.draw();
	tex.unbind();
	cam.end();

	//myfont.drawString("control the box with the keys: W,A,S,D. Zoom in and out with the up and down keys. Reset with 'r'.", 0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


	if (key == 119) {  //w key
		box.tiltDeg(5);
	}

	if (key == 97) {  //a key
		box.panDeg(-5);
	}

	if (key == 115) {  //s key
		box.tiltDeg(-5);
	}

	if (key == 100) {  //d key
		box.panDeg(5);
	}

	if (key == 57357) { //up arrow zoom in 
		cam.dolly(-2);
	}

	if (key == 57359) { //down arrow zoom out
		cam.dolly(2);
	}

	if (key == 114) {
		cam.setPosition(ofVec3f(0, 0, 20));
		cam.lookAt(box.getPosition(), ofVec3f(0, 1, 0));
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
