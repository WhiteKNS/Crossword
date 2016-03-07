#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>

#define LINES 9
#define COLUMNS 13


using namespace std;


class DataBase
{

private:

	DataBase();
	~DataBase();

	fstream fin;
	vector<vector<int>> vec;
	vector<vector<string>> words;
	vector<vector<string>> questions;
	vector<vector<int>> arrows;
	static DataBase* instance;

	void SetToArrows(string current_str);
	void SaveToString(string current_str);
	void SaveToArrow(const string current_str);
	void SaveToField(const string current_str);
	void SaveToQuestions(const string current_str);

public:
	
	static DataBase* getInstance();

	const vector<int> getArrows(const int level);
	const vector<int> getCrossword(const int level);
	const vector<string> getWords(const int level);
	const vector<string> getQuestions(const int level);
	const int getNumberOfLevels();

	void setField();
	void setWords();
	void setQuestions();
	void setArrows();

	//void PrintArrows();
	//void PrintWords();
	//void PrintQuestions();
	//void PrintVector();
	
};

#endif