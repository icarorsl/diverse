#include "stdafx.h"

// writing on a text file
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>

#include "Blahh.h"
#include "pobject.h"

using namespace std;

ofstream ofilestream;
ifstream ifilestream;// (fileName, ios::in | ios::binary | ios::ate);

Blahh::Blahh(std::string fileName)
{
	ofilestream.open(fileName, ios::out | ios::app |/*ios::ate | */ ios::binary);
	ifilestream.open(fileName, ios::in | ios::binary | ios::ate);
}


void invalidateRecord(const char * pid)
{

}

void Blahh::Set(const char *fileName, const char * className, const char * pid, const char * data)
{
	//ofstream myfile(fileName, ios::out | ios::app |/*ios::ate | */ ios::binary);
	if (ofilestream.is_open())
	{
		ofilestream.put(1);
		//pobject pobj(className, pid, data);
		//myfile.write((char*)&pobj, sizeof(pobj));
		int as = strlen(pid);

		ofilestream.write(className, strlen(className));
		ofilestream.write(pid, strlen(pid));
		ofilestream.write(data, strlen(data));
		int64_t size = strlen(className);
		ofilestream.write((char*)&size, sizeof(int64_t));
		size = strlen(pid);
		ofilestream.write((char*)&size, sizeof(int64_t));
		size = strlen(data);
		//int64_t size = sizeof(pobj);
		ofilestream.write((char*)&size, sizeof(int64_t));
		ofilestream.flush();
		//delete[] &className;
		//delete[] &pid;
		//delete[] &data;
	}
}

bool Blahh::Get(const char *fileName, const char *className, const char *pid, pobject * pobj)
{
	//ifstream ifilestream(fileName, ios::in | ios::binary | ios::ate);

	if (ifilestream.is_open())
	{
		
		int previousPageStart = 0;
		ifilestream.seekg(0, ios::end);
		int endPos = ifilestream.tellg();

		int64_t recordPageSize = 0;
		int64_t pidPageSize = 0;
		int64_t clsPageSize = 0;

		while (true)
		{
			ifilestream.seekg((previousPageStart) * -1, ios::end);
			int aasdasd = ifilestream.tellg();
			
			ifilestream.seekg((previousPageStart + (int)sizeof(int64_t)) * -1, ios::end);
			ifilestream.read((char*)&recordPageSize, (int)sizeof(int64_t));

			ifilestream.seekg((previousPageStart + (int)sizeof(int64_t) + (int)sizeof(int64_t)) * -1, ios::end);
			ifilestream.read((char*)&pidPageSize, (int)sizeof(int64_t));

			ifilestream.seekg((previousPageStart + (int)sizeof(int64_t) + (int)sizeof(int64_t) + (int)sizeof(int64_t)) * -1, ios::end);
			ifilestream.read((char*)&clsPageSize, (int)sizeof(int64_t));

			int pageSize = previousPageStart + ((int)sizeof(int64_t) + (int)sizeof(int64_t) + (int)sizeof(int64_t)) + recordPageSize + pidPageSize + clsPageSize + 1;
			//int pageSize = previousPageStart + (int)sizeof(recordPageSize) + recordPageSize + 1;

			ifilestream.seekg(pageSize * -1, ios::end);

			int currentPageInit = ifilestream.tellg();
			previousPageStart = endPos - currentPageInit;

			// read data as a block:
			char ch = ifilestream.get();
			if (ch == 1)
			{
				// allocate memory:
				char * clsBuffer = new char[clsPageSize + 1];
				char * pidBuffer = new char[pidPageSize + 1];
				char * recordBuffer = new char[recordPageSize + 1];

				ifilestream.read(clsBuffer, (int)clsPageSize);
				clsBuffer[clsPageSize] = '\0';

				ifilestream.read(pidBuffer, (int)pidPageSize);
				pidBuffer[pidPageSize] = '\0';

				ifilestream.read(recordBuffer, (int)recordPageSize);
				recordBuffer[recordPageSize] = '\0';
				
				bool result = !strcmp(pid, pidBuffer) && !strcmp(className, clsBuffer);

				if (result)
				{
					pobject obj;
					pobj->setPageInit(currentPageInit);
					pobj->setClassname(clsBuffer);
					pobj->setPid(pidBuffer);
					pobj->setData(recordBuffer);
				}

				delete[] clsBuffer;
				delete[] pidBuffer;
				delete[] recordBuffer;

				if (result) return true;

				//int pos = myfile.tellg();
				//pobject obj;
				//myfile.read((char*)&pobj, sizeof(pobject));
				//int as = sizeof(pobject);
				//myfile.read((char*)&obj, recordPageSize);

				//if (!obj.getPid().compare(pid) && !obj.getClassName().compare(className))
				//{
				//	pobj->setClassname(obj.getClassName());
				//	pobj->setPid(obj.getPid());
				//	pobj->setData(obj.getData());
				//	return true;
				//}

				//return &pobj;
				//int cp = !pobj.getPid().compare(pid);

				//if (!pobj.getPid().compare(pid) && !pobj.getClassName().compare(className)) return pobj.getData();
				//if (!strcmp(pid, pobj.getPid()) && !strcmp(className, pobj.getClassName())) return pobj.getData();
				//delete[] clsBuffer;
				//delete[] pidBuffer;
				//delete[] recordBuffer;
			}
			ifilestream.seekg(pageSize * -1, ios::end);
			
			//previousPageStart = endPos - myfile.tellg();

			int pos = ifilestream.tellg();
			
			if (pos < 1) break;
		}
	}

	return false;
}

void Blahh::Commit()
{
	ofilestream.flush();
}

vector<string> split(const string& str, const string& delim)
{
	vector<string> tokens;
	size_t prev = 0, pos = 0;
	do
	{
		pos = str.find(delim, prev);
		if (pos == string::npos) pos = str.length();
		string token = str.substr(prev, pos - prev);
		if (!token.empty()) tokens.push_back(token);
		prev = pos + delim.length();
	} while (pos < str.length() && prev < str.length());
	return tokens;
}

Blahh::~Blahh()
{

}