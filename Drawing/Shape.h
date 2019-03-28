#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed
struct filewrite {
	int colNum;
	Vector2f pos;
	ShapeEnum shape;
};


// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
public:
	ShapeEnum shape;
	Vector2f location;
	Color color;
	DrawingShape(Color c, Vector2f l, ShapeEnum s) {
		shape = s;
		color = c;
		location = l;
	}
	virtual void draw(RenderWindow& w) = 0;

	virtual filewrite getFileRecord() = 0;
};

class Circle : public DrawingShape
{
public:
	CircleShape circle;
	Circle(Color c, Vector2f l, ShapeEnum s) : DrawingShape(c, l, s) {
		circle.setPosition(location);
		circle.setRadius(20.0);
		circle.setOutlineThickness(2);
		circle.setOutlineColor(color);
		// for just an outlined button
		circle.setFillColor(color);
	}


	void draw(RenderWindow& win) 
	{
		// The following renders the circle on the screen
		// win is a RenderWindow (see provided code)
		win.draw(circle);

	}

	filewrite getFileRecord() {
		filewrite temp;
		Color tempCol = circle.getFillColor();
		temp.colNum = tempCol.toInteger();
		temp.pos = circle.getPosition();
		temp.shape = CIRCLE;

		return temp;
	}

};

class Square : public DrawingShape
{
public:
	RectangleShape square;
	Square(Color c, Vector2f l, ShapeEnum s) : DrawingShape(c, l, s) {}
	void draw(RenderWindow& win) 
	{
		square.setPosition(location);
		square.setOutlineColor(color);
		square.setOutlineThickness(2);
		square.setSize(Vector2f(40.0, 40.0));
		square.setFillColor(color);

		// renders a RectangleShape
		win.draw(square);

	}

	filewrite getFileRecord() {
		filewrite temp;
		Color tempCol = square.getFillColor();
		temp.colNum = tempCol.toInteger();
		temp.pos = square.getPosition();
		temp.shape = SQUARE;

		return temp;
	}

};

// add Circle, Square classes below. These are derived from DrawingShape



