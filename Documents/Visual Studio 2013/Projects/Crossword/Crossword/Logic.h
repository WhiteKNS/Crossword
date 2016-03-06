#ifndef LOGIC_H
#define LOGIC_H
#include <iostream>
#include <vector>
#include "DB.h"
#include <Windows.h>

using namespace std;

class Logic
{
	int** matrix;
	string CharField[LINES][COLUMNS];
	vector<int> field;
	vector<string> words;
	vector<string> questions;
	vector<int> arrows;
	vector<int> Flag;
	unsigned int counter;
	string checkword;

	string Input();

	void gotoXY(int column, int line);
	void InitialHorizontal(const string word,const int column1,const int line1);
	void InitialVertical(const string word,const int column1,const int line1);

	void PrintMatrix();
	void PrintChar();
	void Print();

public:

	Logic();
	~Logic();
	bool InitLevel(const int level);
	void Game();
};

#endif