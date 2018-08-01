#include "DSObject.h"

#pragma once

namespace diverse {

    /**
     * @brief DataStore Persist
     * 
     * Persist data to file
     */

    class DSPersist {
        public:
            DSPersist(const string fileName);
            virtual ~DSPersist() = default;

            void Set(const DSObject dsobject);
            bool Get(const string className, const string pid,  DSObject * dsobject) const;

            void Close();
    };
}