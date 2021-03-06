#include <cstdlib>
#include <string>
#include "DSObject.h"

using namespace std;

namespace diverse {

    DSObject::DSObject() {

    }

    DSObject::DSObject(const string className, const string pid, const char * content)
    {
        _className = className;
        _pid = pid;
        _content = content;
    }

    void DSObject::SetClassName(const string className) {
        _className = className;
    }

    void DSObject::SetPid(const string pid) {
        _pid = pid;
    }

    void DSObject::SetContent(const char * content) {
        _content = content;
    }

    void DSObject::SetPageInit(const int pageInit)
    {
        _pageInit = pageInit;
    }

    string DSObject::GetClassName() const {
        return _className;
    }

    string DSObject::GetPid() const {
        return _pid;
    }

    const char * DSObject::GetContent() {
        return _content;
    }

    int DSObject::GetPageInit() const {
        return _pageInit;
    }
}