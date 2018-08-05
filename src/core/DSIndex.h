#include <string>
#include "DSObject.h"

using namespace std;

#pragma once

namespace diverse {

    /**
     * @brief Base class for persistent objects
     * 
     */
    class DSIndex {
        
        /**
         * @brief Object class name
         * 
         * TODO: describe
         */
        string _className;

        /**
         * @brief Object unique ID
         * 
         * TODO: describe
         */    
        string _pid;

        /**
         * @brief record position
         * 
         */
        int _pageInit;

        public:
            DSIndex(const string className, const string pid, const int pageInit);
            DSIndex(DSObject * dsobject);
            virtual ~DSIndex() = default;

            string GetClassName() const;
            string GetPid() const;
            int GetPageInit() const;        
    };
}