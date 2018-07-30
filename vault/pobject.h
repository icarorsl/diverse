#include <string>
using std::string;

#pragma once
class pobject
{
	std::string _className;
	std::string _pid;
	std::string _data;
	int _pageInit;

public:
	pobject();
	pobject(std::string className, std::string pid, std::string data);
	virtual ~pobject();

	std::string getPid();
	void setPid(std::string pid);

	std::string getClassName();
	void setClassname(std::string className);

	std::string getData();
	void setData(std::string data);

	int getPageInit();
	void setPageInit(int pageInit);
};

