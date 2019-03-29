#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	
public:
	// holds all shapes to be redrawn next frame
	vector <DrawingShape*> shapeHolder;

	ShapeMgr()
	{}
	// adds a shape that has been drawn to the shapeHolder Vector
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

	// saves shapes to the file
	void saveFile(fstream& outfile) {
		filewrite tempData;
		

		for (int i = 0; i < shapeHolder.size(); i++) {
			tempData = shapeHolder[i]->getFileRecord();
			outfile.write(reinterpret_cast<char*> (&tempData), sizeof(tempData));
		}
	}


	// reads shapes from the file
	void readFile(fstream& infile) {
		filewrite tempData;
		
			while (infile.read(reinterpret_cast<char*> (&tempData), sizeof(tempData))) {
				Color aColor(tempData.colNum);

				if (tempData.shape == CIRCLE) {
					Circle* newCircle;
					newCircle = new Circle(aColor, tempData.pos, CIRCLE);
					shapeHolder.push_back(newCircle);
				}
				if (tempData.shape == SQUARE) {
					Square* newSquare;
					newSquare = new Square(aColor, tempData.pos, SQUARE);
					shapeHolder.push_back(newSquare);
				}
			}
	}
};
