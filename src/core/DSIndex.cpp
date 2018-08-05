#include <string>
#include "DSObject.h"
#include "DSIndex.h"

using namespace std;

namespace diverse {

    DSIndex::DSIndex(const string className, const string pid, const int pageInit) {
        _className = className;
        _pid = pid;
        _pageInit = pageInit;
    }

    DSIndex::DSIndex(DSObject * dsobject) {
        _className = dsobject->GetClassName();
        _pid = dsobject->GetPid();
        _pageInit = atoi(dsobject->GetContent());
    }

    string DSIndex::GetClassName() const {
        return _className;
    }

    string DSIndex::GetPid() const {
        return _pid;
    }

    int DSIndex::GetPageInit() const {
        return _pageInit;
    }    

}