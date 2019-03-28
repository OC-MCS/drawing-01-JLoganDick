#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	
public:

	vector <DrawingShape*> shapeHolder;

	ShapeMgr()
	{
		
	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE) {
			Circle* newCircle;
			newCircle = new Circle(color, pos, whichShape);
			shapeHolder.push_back(newCircle);
		}
		if (whichShape == SQUARE) {
			Square* newSquare;
			newSquare = new Square(color, pos, whichShape);
			shapeHolder.push_back(newSquare);
		}

	}

};
