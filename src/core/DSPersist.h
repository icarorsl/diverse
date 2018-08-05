#include "DSObject.h"
#include "DSIndex.h"

#pragma once

namespace diverse {

    /**
     * @brief DataStore Persist
     * 
     * Persist data to file
     */

    class DSPersist {
        ofstream* ofilestream;
        ifstream* ifilestream;

        public:
            DSPersist(const string fileName);
            virtual ~DSPersist() = default;

            DSIndex* Set(DSObject* dsobject);
            DSObject* Get(const string className, const string pid, DSIndex* dsindex) const;

            void Close();
    };
}