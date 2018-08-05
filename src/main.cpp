#include <vector>
#include <string>     // std::string, std::to_string
#include <iostream>
#include "DSObject.h"
#include "DSPersist.h"
#include <tr1/memory>
#include <map>

//using namespace std;
using namespace diverse;

int main()
{
    std::cout << "Addind values to Example.txt" << '\n'; 

    DSPersist* dspersist = new DSPersist("Example.txt");
	DSPersist* ds_indexes = new DSPersist("Indexes.txt");
	//vector<DSIndex> indexes(200000);
	//std::map<string, int> idxs;
    
	for (int i = 1; i <= 200000; i++)
	{
		//std::string ipid = std::to_string(i);
		//char * data = new char[i * 10 + 1];
		//gen_random(data, i * 10);
		string content = "{code = '" + to_string(i) + "'}";

        DSObject* dsobject = new DSObject("obj", to_string(i), content.c_str());
		DSIndex* index = dspersist->Set(dsobject);
		if (index != NULL) {
			const char * pageInit = to_string(index->GetPageInit()).c_str();
			DSObject* idx = new DSObject(dsobject->GetClassName(), dsobject->GetPid(), pageInit);
			DSIndex* idxidx = ds_indexes->Set(idx);
			//idxs.insert(std::pair<string,int>(index->GetPid(),index->GetPageInit()));
			delete idxidx;
			idx->~DSObject();
			delete idx;
		}
        index->~DSIndex();
        dsobject->~DSObject();
		delete index;
		delete dsobject;
		//delete[] data;
	}
    
    dspersist->Close();
	dspersist->Close();
    std::cout << "searching" << '\n';

    //while (true)
	//{
		
		std::cout << "searching for index 1" << '\n';
		DSIndex* idx1 = new DSIndex(ds_indexes->Get("obj", "1", NULL));
		std::cout << "searching for index 2" << '\n';
		DSIndex* idx2 = new DSIndex(ds_indexes->Get("obj", "2", NULL));


		//DSIndex* idx1;
		//DSIndex* idx2;

		//for (auto it=idxs.begin(); it!=idxs.end(); ++it){
			
		//}
		/*

		for (auto &p : indexes) {
			DSIndex* idx = p;
			if (idx->GetClassName() == "obj" && idx->GetPid() == "1") {
				idx1 = idx;
				break;
			}
		}

		std::cout << "searching for index 2" << '\n';
		DSIndex* idx2;
		for (auto &p : indexes) {
			DSIndex* idx = p.get();
			if (idx->GetClassName() == "obj" && idx->GetPid() == "2") {
				idx2 = idx;				
			}
		}
*/

    	std::cout << "searching" << '\n';

		DSObject* obj1;
		if ((obj1 = dspersist->Get("obj", "1", idx1)) != NULL)
		{
			std::cout << obj1->GetContent() << '\n';
			DSObject* obj2;
			if ((obj2 = dspersist->Get("obj", "2", idx2)) != NULL)
			{
    			std::cout << obj2->GetContent() << '\n';
				DSObject* obj3;
				if ((obj3 = dspersist->Get("obj", "3", NULL)) != NULL)
				{
                    std::cout << obj3->GetContent() << '\n';
					DSObject* obj5000;
					if ((obj5000 = dspersist->Get("obj", "5000", NULL)) != NULL)
					{
                        std::cout << obj5000->GetContent() << '\n';
						DSObject* obj10000;
						if ((obj10000 = dspersist->Get("obj", "10000", NULL)) != NULL)
						{
                            std::cout << obj10000->GetContent() << '\n';
							DSObject* obj200000;
							if ((obj200000 = dspersist->Get("obj", "200000", NULL)) != NULL)
							{
                                std::cout << obj200000->GetContent() << '\n';
								//DSObject obj501;
                                //break;
							}
						}
					}
				}
			}

		}
	//}    
    
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
