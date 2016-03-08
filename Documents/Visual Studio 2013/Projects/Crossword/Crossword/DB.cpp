#include "DB.h"


DataBase* DataBase::instance = 0;

DataBase* DataBase::getInstance()
{
	if (instance == 0)
	{
		instance = new DataBase();
	}
	return instance;
}

DataBase::DataBase()
{
	vec.reserve(3);
	arrows.reserve(3);
	for (int i = 0, size = vec.size(); i < size; ++i)
	{
		vec[i].reserve(5);
		arrows[i].reserve(5);
	}
}

	DataBase::~DataBase()
	{
	delete instance;
	}

	const vector<int> DataBase::getCrossword(const int level)
	{
		return vec.at(level);
	}

	void DataBase::SaveToField(const string current_str)
	{
		int start = 0;
		
		for (unsigned int i = 0; i < current_str.length(); ++i)
		{
			if (current_str.at(i) == ' '||i+1==current_str.length())
			{
				string final_str = "";
				for (unsigned int j = start; j < i; j++)
				{
					final_str += current_str.at(j);
				}
				int number = atoi(final_str.c_str());
				vec[vec.size() - 1].push_back(number);
				start = i+1;
			}
		}
	}

	void DataBase::setField()
	{
		fin.open("test.txt");
		string current_str;
		if (!fin.is_open())
		{
			cerr << "Can't open file!" << endl;
		}
		else
		{
			while (!fin.eof())
			{
				getline(fin, current_str, '\n'); //получаем crossword из файла1
				if (current_str.empty()) { break; }
				vec.push_back(vector<int>());
				SaveToField(current_str);
			}
		}
		fin.close();
	}


	void DataBase::setWords()
	{
		fstream f_str;
		f_str.open("words.txt");
		string current_str;
		if (!f_str.is_open())
		{
			cerr << "Can't open words.txt!" << endl;
		}
		else
		{
			while (!f_str.eof())
			{
				getline(f_str, current_str, '\n'); //получаем crossword из файла1
				if (current_str.empty()) { break; }

				words.push_back(vector<string>());
				SaveToString(current_str);
			}
		}
		f_str.close();
	}


	void DataBase::SaveToString(const string current_str)
	{
		int start = 0;

		for (unsigned int i = 0; i < current_str.length(); ++i)
		{
			if (current_str.at(i) == ' '||(i+1)==current_str.length())
			{
				string final_str = "";
				for (unsigned int j = start; j < i; j++)
				{
					final_str += current_str.at(j);
					if (j + 1 == current_str.length() - 1) final_str += current_str.at(++j);
				}
				words[words.size() - 1].push_back(final_str);
				start = i + 1;
			}
		}
	}


	const vector<string> DataBase::getWords(const int level)
	{
		return words.at(level);
	}


	
	void DataBase::setQuestions()
	{
		fstream f_str;
		f_str.open("questions.txt");
		string current_str;
		if (!f_str.is_open())
		{
			cerr << "Can't open questions.txt!" << endl;
		}
		else
		{
			while (!f_str.eof())
			{
				getline(f_str, current_str, '\n'); //получаем questions из файла1
				if (isdigit(current_str[0]))
				{
					questions.push_back(vector<string>());
					continue;
				}
				questions[questions.size() - 1].push_back(current_str);
			}
		}
		f_str.close();
	}

	const vector<int> DataBase::getArrows(const int level)
	{
		return arrows.at(level);
	}
	
	const int DataBase::getNumberOfLevels()
	{
		return arrows.size();
	}

	const vector<string> DataBase::getQuestions(const int level)
	{
		return questions.at(level);
	}


	
	void DataBase::setArrows()
	{
		fstream f;
		f.open("arrows.txt");
		string current_str;
		if (!f.is_open())
		{
			cerr << "Can't open file!" << endl;
		}
		else
		{
			while (!f.eof())
			{
				getline(f, current_str, '\n'); //получаем crossword из файла1
				if (current_str.empty()) { break; }
				arrows.push_back(vector<int>());
				SaveToArrow(current_str);
			}
		}
		f.close();
	}


	void DataBase::SaveToArrow(const string current_str)
	{
		int start = 0;

		for (unsigned int i = 0; i < current_str.length(); ++i)
		{
			if (current_str.at(i) == ' ' || i + 1 == current_str.length())
			{
				string final_str = "";
				if (i + 1 == current_str.length())
				{
					final_str = current_str.at(current_str.length() - 1);
				}
				else {
					for (unsigned int j = start; j < i; j++)
					{
						final_str += current_str.at(j);
					}
				}
				int number = atoi(final_str.c_str());
				arrows.back().push_back(number);

				start = i + 1;
			}
		}
	}

	const void DataBase::setGame()
	{
		setField();
		setWords();
		setQuestions();
		setArrows();
	}

	/*
	void DataBase::PrintVector()
	{
		for (unsigned int i = 0; i < vec.size(); ++i)
		{
			for (unsigned int j = 0; j < vec.at(i).size(); ++j)
			{
				cout << vec.at(i).at(j) << " ";
			}
		}
		cout << "\n" << endl;
	}

	void DataBase::PrintArrows()
	{

		for (unsigned int i = 0; i < arrows.size(); ++i, cout << "\n")
		{
			for (unsigned int j = 0; j < arrows.at(i).size(); ++j)
			{
				cout << arrows.at(i).at(j) << "\n";
			}
		}

		cout << "\n" << endl;
	}

	void DataBase::PrintQuestions()
	{
	for (unsigned int i = 0; i < words.size(); ++i, cout<<"\n")
	{
	for (unsigned int j = 0; j < questions.at(i).size(); ++j)
	{
	cout << questions.at(i).at(j) << "\n";
	}
	}

	cout << "\n" << endl;
	}

	void DataBase::PrintWords()
	{
	for (unsigned int i = 0; i < words.size(); ++i)
	{
	for (unsigned int j = 0; j < words.at(i).size(); ++j)
	{
	cout << words.at(i).at(j) << " ";
	}
	}

	cout << "\n" << endl;
	}

	*/