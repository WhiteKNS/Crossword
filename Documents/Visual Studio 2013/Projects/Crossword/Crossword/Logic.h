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
	int** matrix; //our field
	//string CharField[LINES][COLUMNS]; //
	vector<int> field; //here we work with the data of one level 
	vector<string> words;
	vector<string> questions;
	vector<int> arrows;
	vector<bool> Flag;
	unsigned int counter;
	string checkword; 
	Painter *painter; //for paint the crossword
	DataBase *base;  //to get data from data base

	string Input(); //here user'll input data


public:

	Logic();
	~Logic();
	bool InitLevel(const int level);
	bool Game();  //
	const int getLevels(); //get info about number of levels
};

#endif