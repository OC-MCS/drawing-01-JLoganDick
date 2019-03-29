#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

//Structure that holds the settings for writing to a file
struct settings {
	ShapeEnum shape;
	int numColor;
};


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
	
	// getter function returning curColor
	Color getCurColor()
	{
		return curColor;  
	}

	// getter function returning curShape
	ShapeEnum getCurShape()
	{
		return curShape; 
	}

	// setter function assigning curShape
	void setCurShape(ShapeEnum shape) {
		curShape = shape;
	}

	// setter function assigning curColor
	void setCurColor(Color col) {
		curColor = col;
	}


	// funciton that saves settings to file
	void saveSettings(fstream& outfile) {
		settings tempSet;
		tempSet.shape = curShape;
		tempSet.numColor = curColor.toInteger();

		outfile.write(reinterpret_cast<char*> (&tempSet), sizeof(tempSet));
	}

	// function that reads settings from file
	void readSettings(fstream& infile) {
		settings tempSet;

		if (infile.read(reinterpret_cast<char*> (&tempSet), sizeof(tempSet))) { // sets colors from file
			Color aColor(tempSet.numColor);

			curColor = aColor;
			curShape = tempSet.shape;
		}
		else { // sets default settings
			curColor = Color::Blue;
			curShape = CIRCLE;
		}
	}

};
