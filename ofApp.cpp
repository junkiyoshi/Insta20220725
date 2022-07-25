#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	vector<ofColor> color_list = { ofColor(255, 0, 0), ofColor(0, 255, 0), ofColor(0, 0, 255) };

	for (int y = -200; y <= 200; y += 200) {

		int param_x = ofMap((ofGetFrameNum() * 8 + y * ofGetWindowWidth() / 3) % ofGetWindowWidth(), 0, ofGetWindowWidth(), ofGetWindowWidth() * -0.5 - 120, ofGetWindowWidth() * 0.5 + 120);
		for (int color_index = 0; color_index < color_list.size(); color_index++) {

			auto noise_seed = ofRandom(1000);

			
			for (int x = ofGetWindowWidth() * -0.5; x <= ofGetWindowWidth() * 0.5; x += 18) {

				for (int i = 0; i < 3; i++) {

					auto noise_value = ofNoise(noise_seed, x * 0.02, i * 0.1 + ofGetFrameNum() * 0.001);
					auto param = ofMap(noise_value, 0, 1, -150, 150);
					auto len = abs(param_x - x);

					if (len < 120) {

						param *= ofMap(len, 0, 120, 1, 0);
					}
					else {

						param *= 0;
					}

					ofSetColor(color_list[color_index]);
					ofNoFill();
					ofDrawCircle(x, y + param, 7);

					ofSetColor(color_list[color_index], 192 - i * 64);
					ofFill();
					ofDrawCircle(x, y + param, 7);
				}
			}
			
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}