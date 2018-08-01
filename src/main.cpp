#include <string>     // std::string, std::to_string
#include <iostream>
#include "DSObject.h"
#include "DSPersist.h"

//using namespace std;
using namespace diverse;

int main()
{
    std::cout << "Addind values to Example.txt" << '\n'; 

    DSPersist dspersist("Example.txt");
    
	for (int i = 1; i <= 200000; i++)
	{
		//std::string ipid = std::to_string(i);
		//char * data = new char[i * 10 + 1];
		//gen_random(data, i * 10);
        DSObject dsobject("obj", to_string(i), "{code = '" + to_string(i) + "'}");
		dspersist.Set(dsobject);
        dsobject.~DSObject();
		//delete[] data;
	}
    
    dspersist.Close();
    std::cout << "serching" << '\n';

    while (true)
	{
		DSObject obj1;
		if (dspersist.Get("obj", "1", &obj1))
		{
			std::cout << obj1.GetContent() << '\n';
			DSObject obj2;
			if (dspersist.Get("obj", "2", &obj2))
			{
    			std::cout << obj2.GetContent() << '\n';
				DSObject obj3;
				if (dspersist.Get("obj", "3", &obj3))
				{
                    std::cout << obj3.GetContent() << '\n';
					DSObject obj5000;
					if (dspersist.Get("obj", "5000", &obj5000))
					{
                        std::cout << obj5000.GetContent() << '\n';
						DSObject obj10000;
						if (dspersist.Get("obj", "10000", &obj10000))
						{
                            std::cout << obj10000.GetContent() << '\n';
							DSObject obj20000;
							if (dspersist.Get("obj", "20000", &obj20000))
							{
                                std::cout << obj20000.GetContent() << '\n';
								//DSObject obj501;
                                break;
							}
						}
					}
				}
			}

		}
	}    
    
    /*
    DSObject dsobject;
    dsobject.SetClassName("cl1");
    dsobject.SetPid("1");
    dsobject.SetContent("c1");
    dsobject.SetPageInit(10);
    */

    //std::cout << "hello Visual Studio icaro Code! :)" << '\n'; 
    //std::cout << "asdas" << std::to_string(dsobject.GetNumber()) << '\n'; 
    //std::cout << "ddd" << dsobject.GetContent() << '\n';
    return  0;//dsobject.GetPageInit();
    //return 0;
}
