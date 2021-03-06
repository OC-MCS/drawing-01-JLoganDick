#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed

void die(string die);

class SettingsUI
{
private:
	CircleShape blueBtn;
	CircleShape redBtn;
	CircleShape greenBtn;
	RectangleShape squareBtn;
	CircleShape circleBtn;
	SettingsMgr* SetMgrPtr;
public:
	SettingsUI(SettingsMgr *mgr)
	{
		SetMgrPtr = mgr;
		// define blue button
		Vector2f pos1(80, 100);
		blueBtn.setPosition(pos1);
		blueBtn.setRadius(10);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);
		if (mgr->getCurColor() == Color::Blue) {
			blueBtn.setFillColor(Color::Blue);
		}
		else {
			blueBtn.setFillColor(Color::Transparent);
		}

		// define red button
		Vector2f pos2(80, 200);
		redBtn.setPosition(pos2);
		redBtn.setRadius(10);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);
		if (mgr->getCurColor() == Color::Red) {
			redBtn.setFillColor(Color::Red);
		}
		else {
			redBtn.setFillColor(Color::Transparent);
		}
		

		// draw green button
		Vector2f pos3(80, 300);
		greenBtn.setPosition(pos3);
		greenBtn.setRadius(10);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);
		if (mgr->getCurColor() == Color::Green) {
			greenBtn.setFillColor(Color::Green);
		}
		else {
			greenBtn.setFillColor(Color::Transparent);
		}

		// define square shape selection button
		Vector2f sqPos1(80, 425);
		squareBtn.setPosition(sqPos1);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(15, 15));
		if (mgr->getCurShape() == SQUARE) {
			squareBtn.setFillColor(Color::White);
		}
		else {
			squareBtn.setFillColor(Color::Transparent);
		}

		// define circle shape selection button
		Vector2f pos4(80, 525);
		circleBtn.setPosition(pos4);
		circleBtn.setRadius(10);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);
		if (mgr->getCurShape() == CIRCLE) {
			circleBtn.setFillColor(Color::White);
		}
		else {
			circleBtn.setFillColor(Color::Transparent);
		}
	}

	//Detects when & where the coursor is at the time the left mouse button is released
	void handleMouseUp(Vector2f mouse)
	{
		if (blueBtn.getGlobalBounds().contains(mouse)) {
			SetMgrPtr->setCurColor(Color::Blue);
			blueBtn.setFillColor(Color::Blue);
			redBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
		}

		if (redBtn.getGlobalBounds().contains(mouse)) {
			SetMgrPtr->setCurColor(Color::Red);
			blueBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Red);
			greenBtn.setFillColor(Color::Transparent);
		}

		if (greenBtn.getGlobalBounds().contains(mouse)) {
			SetMgrPtr->setCurColor(Color::Green);
			blueBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Green);
		}

		if (squareBtn.getGlobalBounds().contains(mouse)) {
			SetMgrPtr->setCurShape(SQUARE);
			squareBtn.setFillColor(Color::White);
			circleBtn.setFillColor(Color::Transparent);
		}

		if (circleBtn.getGlobalBounds().contains(mouse)) {
			SetMgrPtr->setCurShape(CIRCLE);
			squareBtn.setFillColor(Color::Transparent);
			circleBtn.setFillColor(Color::White);
		}

	}

	// Draws the buttons and texxt in the settings
	void draw(RenderWindow& win)
	{
		win.draw(blueBtn);
		win.draw(redBtn);
		win.draw(greenBtn);
		win.draw(squareBtn);
		win.draw(circleBtn);

		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		// Color Title
		Text title("Drawing Color", font, 25);
		title.setPosition(30, 25);
		win.draw(title);

		// Size Tidle
		Text title2("Drawing shape", font, 25);
		title2.setPosition(30, 350);
		win.draw(title2);
	}
};

// Function that ends program if there is an error
void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}
