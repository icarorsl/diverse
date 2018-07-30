#include <string>
#include "pobject.h"
using std::string;

#pragma once
class Blahh
{
private:

public:
	Blahh(std::string fileName);
	void Set(const char *fileName, const char * className, const char * pid, const char * data);
	bool Get(const char *fileName, const char *className, const char *pid, pobject * pobj);

	void Commit();
	virtual ~Blahh();
};

