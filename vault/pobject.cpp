#include "stdafx.h"
#include "pobject.h"

using namespace std;

pobject::pobject()
{
	//this->className = new char[4];
	//this->pid = new char[2];
	//this->data = new char[16];
}

pobject::pobject(std::string className, std::string pid, std::string data)
{
	_className = className;
	_pid = pid;
	_data = data;
	//this->className = new char[strlen(className) + 1];
	//strcpy_s(className, strlen(className) + 1, className);
	//this->pid = new char[strlen(pid) + 1];
	//strcpy_s(this->pid, strlen(pid) + 1, pid);
	//this->data = new char[strlen(data) + 1];
	//strcpy_s(this->data, strlen(data) + 1, data);
}


pobject::~pobject()
{
	//if (_pid != NULL)  delete _pid;
	//if (_className != NULL)  delete _className;
	//if (_data != NULL)  delete _data;
}


std::string pobject::getPid()
{
	return _pid;
}

void pobject::setPid(std::string pid)
{
	//if (_pid != NULL)  delete _pid;
	_pid = pid;
}

std::string pobject::getClassName()
{
	return _className;
}

void pobject::setClassname(std::string className)
{
	///if (_className != NULL)  delete _className;
	_className = className;
}

std::string pobject::getData()
{
	return _data;
}

void pobject::setData(std::string data)
{
	//if (_data != NULL) delete _data;
	_data = data;
}


int pobject::getPageInit()
{
	return _pageInit;
}

void pobject::setPageInit(int pageInit)
{
	_pageInit = pageInit;
}
