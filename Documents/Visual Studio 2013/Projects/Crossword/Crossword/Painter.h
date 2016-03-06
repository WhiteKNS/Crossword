#ifndef PAINTER_H
#define PAINTER_H

#include "DB.h"
#include <Windows.h>
#include <string>

using namespace std;

class Painter
{
	string CharField[LINES][COLUMNS];
	Painter();
	~Painter();
	

public:
	Painter(int **matrix, unsigned int words_size);
	void PaintHorizontal(string word, int line1, int column1);
	void PaintVertical(string word, int line1, int column1);
	void Print();
	void gotoXY(int column, int line);
};


#endif