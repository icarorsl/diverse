#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

#include "DSIndex.h"
#include "DSObject.h"
#include "DSPersist.h"

using namespace std;

namespace diverse {

DSPersist::DSPersist(const string fileName) {
	ofilestream = new ofstream(fileName, ios::out | ios::app |/*ios::ate | */ ios::binary);
	//ofilestream->open(fileName, ios::out | ios::app |/*ios::ate | */ ios::binary);
	ifilestream = new ifstream(fileName, ios::in | ios::binary | ios::ate);
	//ifilestream->open(fileName, ios::in | ios::binary | ios::ate);
}

DSIndex* DSPersist::Set(DSObject* dsobject)
{
	//ofstream myfile(fileName, ios::out | ios::app |/*ios::ate | */ ios::binary);
	if (ofilestream->is_open()) {
		//ofilestream.seekp(-1, ios::beg);
		//ofilestream.seekp(-1, ios::end);
		ofilestream->put(1);

		const char * className = dsobject->GetClassName().c_str();
        ofilestream->write(className, strlen(className));

		const char * pid = dsobject->GetPid().c_str();
        ofilestream->write(pid, strlen(pid));

		const char * content = dsobject->GetContent();
        ofilestream->write(content, strlen(content));

		int64_t size = strlen(className);
		ofilestream->write((char*)&size, sizeof(int64_t));
		size = strlen(pid);
		ofilestream->write((char*)&size, sizeof(int64_t));
		size = strlen(content);
		//int64_t size = sizeof(pobj);
		ofilestream->write((char*)&size, sizeof(int64_t));

		int position = ofilestream->tellp();

		ofilestream->flush();

		return new DSIndex(className, pid, position);
        //delete[] &className;
		//delete[] &pid;
		//delete[] &content;
	}

	return NULL;
}

DSObject* DSPersist::Get(const string className, const string pid, DSIndex* dsindex) const {

	if (ifilestream->is_open()) {
		int previousPageStart = 0;
		ifilestream->seekg(0, ios::end);
		int endPos = ifilestream->tellg();

		if (dsindex != NULL) 
			previousPageStart = endPos - dsindex->GetPageInit();

		int64_t recordPageSize = 0;
		int64_t pidPageSize = 0;
		int64_t clsPageSize = 0;

		while (true)
		{
			ifilestream->seekg((previousPageStart) * -1, ios::end);
			//int aasdasd = ifilestream->tellg();
			
			ifilestream->seekg((previousPageStart + (int)sizeof(int64_t)) * -1, ios::end);
			ifilestream->read((char*)&recordPageSize, (int)sizeof(int64_t));

			ifilestream->seekg((previousPageStart + (int)sizeof(int64_t) + (int)sizeof(int64_t)) * -1, ios::end);
			ifilestream->read((char*)&pidPageSize, (int)sizeof(int64_t));

			ifilestream->seekg((previousPageStart + (int)sizeof(int64_t) + (int)sizeof(int64_t) + (int)sizeof(int64_t)) * -1, ios::end);
			ifilestream->read((char*)&clsPageSize, (int)sizeof(int64_t));

			int pageSize = previousPageStart + ((int)sizeof(int64_t) + (int)sizeof(int64_t) + (int)sizeof(int64_t)) + recordPageSize + pidPageSize + clsPageSize + 1;
			//int pageSize = previousPageStart + (int)sizeof(recordPageSize) + recordPageSize + 1;

			ifilestream->seekg(pageSize * -1, ios::end);

			int currentPageInit = ifilestream->tellg();
			previousPageStart = endPos - currentPageInit;

			// read data as a block:
			char ch = ifilestream->get();
			if (ch == 1)
			{
				// allocate memory:
				char * clsBuffer = new char[clsPageSize + 1];
				char * pidBuffer = new char[pidPageSize + 1];
				char * recordBuffer = new char[recordPageSize + 1];

				ifilestream->read(clsBuffer, (int)clsPageSize);
				clsBuffer[clsPageSize] = '\0';

				ifilestream->read(pidBuffer, (int)pidPageSize);
				pidBuffer[pidPageSize] = '\0';

				ifilestream->read(recordBuffer, (int)recordPageSize);
				recordBuffer[recordPageSize] = '\0';
				
                bool result = std::string(pidBuffer) == pid && std::string(clsBuffer) == className;
				//int value = pid.compare(pidBuffer) && className.compare(clsBuffer);
                //bool result = !strcmp(pid.c_str(), pidBuffer) && !strcmp(className.c_str(), clsBuffer);
                //bool result = value == 0;

				DSObject* dsobject;

				if (result)
				{
					dsobject = new DSObject();
					dsobject->SetPageInit(currentPageInit);
					dsobject->SetClassName(clsBuffer);
					dsobject->SetPid(pidBuffer);
					dsobject->SetContent(recordBuffer);
				}

				delete[] clsBuffer;
				delete[] pidBuffer;
				//delete[] recordBuffer;

				if (result) return dsobject;				
			}

			ifilestream->seekg(pageSize * -1, ios::end);
			
			//previousPageStart = endPos - myfile.tellg();

			int pos = ifilestream->tellg();
			if (pos < 1) break;
		}
	}

	return NULL;
}    

void DSPersist::Close() {
    ofilestream->close();
}


}