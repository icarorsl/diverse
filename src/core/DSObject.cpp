#include <cstdlib>
#include "DSObject.h"

namespace diverse {

    DSObject::DSObject() {
        _number = 1;
    }

    DSObject::DSObject(const int number){        
        _number = number;
    }
    
    int DSObject::GetNumber() const {

        return _number;
    }
}