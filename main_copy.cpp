/************************************************
* \file		main.cpp
* \brief	deomnstrate reading from a file and the use of .eof()
* 
* \author	S0542111
* \date		October 2023
***********************************************/

#include <iostream>
#include <fstream>

int main()
{
	using namespace std;

	char aCaharacter;
	ifstream fin;
	ofstream fout;

	fin.open("main.cpp");
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