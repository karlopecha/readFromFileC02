/************************************************
* \file		main.cpp
* \brief	deomnstrate reading from a file and the use of .eof()
* 
* \author	S0542111
* \date		October 2023
***********************************************/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	using namespace std;

	char aCaharacter;
	//char fileName[30];
	string fileName;

	ifstream fin;
	ofstream fout;

	cout << "Enter a filename: ";
	cin >> fileName;

	fin.open(fileName.c_str());
	if (fin.fail() || !fin.is_open())
	{
		cerr << "Failed to open file." << endl;
	}
	else
	{
		fout.open("main_copy.cpp");
		if (fout.fail() || !fout.is_open())
		{
			cerr << "Failed to open output file." << endl;
		}
		else
		{
			fin.get(aCaharacter);
			while (!fin.eof() && !fin.fail())
			{
				cout.put(aCaharacter);
				fout.put(aCaharacter);
				fin.get(aCaharacter);
			}
			fout.close();
		}
		fin.close();
	}

	return 0;
}