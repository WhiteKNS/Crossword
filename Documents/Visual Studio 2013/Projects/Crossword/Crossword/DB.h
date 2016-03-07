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


class DataBase //it's data base - here we get data about the field, words, questions and store it. Now it's 2 levels here, but you can add new levels, as much as you want.
{

private:

	DataBase();
	DataBase (const DataBase &base);
	DataBase& operator=(DataBase &base);
	~DataBase();
	                     //we'll download all data in one step, then we'll get needed level
	fstream fin;
	vector<vector<int>> vec; //info about crossword field
	vector<vector<string>> words; //info about right answers
	vector<vector<string>> questions; //info about questions
	vector<vector<int>> arrows; //info about how we'll print the words(vertical or horizontal)
	static DataBase* instance; //here instance store

	void SaveToString(const string current_str);//store to crossword
	void SaveToArrow(const string current_str);
	void SaveToField(const string current_str);
	void SaveToQuestions(const string current_str);

public:
	
	static DataBase* getInstance();

	const vector<int> getArrows(const int level); //get needed info about level
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