#include <string>     // std::string, std::to_string
#include <iostream>
#include "DSObject.h"

using namespace std;
using namespace diverse;


int main()
{
    diverse::DSObject dsobject(13);
    std::cout << "hello Visual Studio icaro Code! :)" << '\n'; 
    std::cout << "asdas" << std::to_string(dsobject.GetNumber()) << '\n'; 
    return dsobject.GetNumber();
    //return 0;
}
