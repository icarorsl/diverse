// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Blahh.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "pobject.h"

using namespace std;

void gen_random(char *s, const int len) {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < len; ++i) {
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	s[len] = 0;
}

int main()
{
	
	/*
	const char* FILENAM = "a.txt";
	int toStore = 10;
	ofstream o(FILENAM, ios::binary);

	o.write((char*)&toStore, sizeof(toStore));
	o.close();

	int toRestore = 0;
	ifstream i(FILENAM, ios::binary);
	i.read((char*)&toRestore, sizeof(toRestore));

	cout << toRestore << endl;
	*/

	Blahh blahh("example.txt");

	//pobject pobject1();
	//blahh.Set("example.txt", "obj", "1", "name = 'value1'");
	//blahh.Set("example.txt", "obj", "2", "name = 'value2'");
	
	//pobject pobject2("obj", "2", "name = 'value1'");
	//blahh.Set("example.txt", pobject2);

	//std::string ipid = std::to_string((int)1);
	//blahh.Set("example.txt", "obj", ipid.c_str(), "name = 'valueasd'");

	/*
	for (int i = 1; i <= 20000; i++)
	{
		std::string ipid = std::to_string(i);
		char * data = new char[i * 10 + 1];
		gen_random(data, i * 10);
		blahh.Set("example.txt", "obj", ipid.c_str(), data);
		delete[] data;
	}

	blahh.Commit();

	for (int i = 1; i <= 100; i++)
	{
		blahh.PushValue("example.txt", "obj", std::to_string(i), "name = 'value2'");
	}

	for (int i = 1; i <= 100; i++)
	{
		blahh.PushValue("example.txt", "obj", std::to_string(i), "name = 'value3'");
	}
	*/
	//blahh.PushValue("example.txt", "obj", "1", "name = 'test1'");
	//blahh.PushValue("example.txt", "obj", "2", "name = 'test2'");
	//blahh.PushValue("example.txt", "obj", "1", "name = 'test1test1'");
	//blahh.PushValue("example.txt", "obj", "3", "name = 'test3'");
	//blahh.PushValue("example.txt", "obj", "1", "name = 'test1test1test1'");

	while (true)
	{
		pobject obj1;
		if (blahh.Get("example.txt", "obj", "1", &obj1))
		{
			//cout << obj1.setClassname() << eoln;
			pobject obj2;
			if (blahh.Get("example.txt", "obj", "2", &obj2))
			{
				pobject obj3;

				if (blahh.Get("example.txt", "obj", "3", &obj3))
				{
					pobject obj5000;
					if (blahh.Get("example.txt", "obj", "5000", &obj5000))
					{
						pobject obj10000;
						if (blahh.Get("example.txt", "obj", "10000", &obj10000))
						{
							pobject obj20000;
							if (blahh.Get("example.txt", "obj", "20000", &obj20000))
							{
								pobject obj501;

							}

						}
					}
				}
			}

		}
	}

	return 0;
}

