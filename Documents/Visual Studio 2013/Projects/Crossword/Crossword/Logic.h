#ifndef LOGIC_H
#define LOGIC_H
#include <iostream>
#include <vector>
#include "DB.h"
#include <Windows.h>
#include "Painter.h"
#include <algorithm>

using namespace std;

class Logic
{
	int** matrix;
	string CharField[LINES][COLUMNS];
	vector<int> field;
	vector<string> words;
	vector<string> questions;
	vector<int> arrows;
	vector<bool> Flag;
	unsigned int counter;
	string checkword;
	Painter *painter;
	DataBase *base;

	string Input();


public:

	Logic();
	~Logic();
	bool InitLevel(const int level);
	bool Game();
	const int getLevels();
};

#endif