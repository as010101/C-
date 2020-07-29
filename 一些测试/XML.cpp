#include "tinyxml.h"
#include <string>
#include <iostream>

using namespace std;

//box参数结构体
struct BoxSize
{
	int xMin;
	int yMin;
	int xMax;
	int yMax;
};
int main() 
{

	BoxSize pNode;
	vector<BoxSize> vecNode;
	string  str = "C://Users//DK//Desktop//Aurora//Password//servers.xml";
    TiXmlDocument doc(str.c_str());
    if (!doc.LoadFile()) return 0;

    TiXmlHandle hDoc(&doc);
    TiXmlElement* pElem;


    TiXmlHandle hRoot(0);
	TiXmlElement* root = doc.FirstChildElement();
	for (TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
	 {
	     string elemName = elem->Value();
	     const char* attr;
	     attr = elem->Attribute("ID");
		 for (TiXmlElement* elemS = elem->FirstChildElement(); elemS != NULL; elemS = elemS->NextSiblingElement())
		 {

			 string elemName = elemS->Value();
			 const char* attr;
			 attr = elemS->Attribute("ID");
		 }
	     //if (strcmp(attr, "1") == 0)
	     //    {
	     //        TiXmlElement * e1 = elem->FirstChildElement("bold");
	     //        TiXmlNode * e2 = e1->FirstChild();
	     //        cout << "priority=1\t" << e2->ToText()->Value() << endl;
	
			   //      }
		    //    else if (strcmp(attr, "2") == 0)
		    //    {
		    //        TiXmlNode * e1 = elem->FirstChild();
		    //        cout << "priority=2\t" << e1->ToText()->Value() << endl;
		    //    }
		    }
	     doc.Clear();
	     return 0;
	
}
