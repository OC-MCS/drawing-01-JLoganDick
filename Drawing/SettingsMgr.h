#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	ShapeEnum curShape;
	Color curColor;
public:
	

	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		curColor = startingColor;
		curShape = startingShape;
	}

	Color getCurColor()
	{
		return curColor; // just to make it compile 
	}


	ShapeEnum getCurShape()
	{
		return curShape; // just to make it compile;
	}

	void setCurShape(ShapeEnum shape) {
		curShape = shape;
	}

	void setCurColor(Color col) {
		curColor = col;
	}

};
