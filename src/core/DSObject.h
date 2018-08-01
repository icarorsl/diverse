#include <string>

using namespace std;

#pragma once

namespace diverse {

    /**
     * @brief Base class for persistent objects
     * 
     */
    class DSObject {
        
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
         * @brief Object content
         * 
         * It could be a JSON or whatever. Mayve it need to be changed to another type... like char * or so...
         */
        string _content;

        int _pageInit;

        public:
            DSObject();
            DSObject(const string className, const string pid, const string content);
            virtual ~DSObject() = default;

            string GetClassName() const;
            string GetPid() const;
            string GetContent() const;
            int GetPageInit() const;

            void SetClassName(const string className);
            void SetPid(const string pid);
            void SetContent(const string content);
            void SetPageInit(const int pageInit);
    };
}