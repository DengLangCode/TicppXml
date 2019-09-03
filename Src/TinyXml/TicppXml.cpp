#include "tinyxml2.h"
#include <iostream>
using namespace tinyxml2;


int main()
{
	try
	{
		tinyxml2::XMLDocument doc;
		doc.LoadFile("XMLFile.xml");
		tinyxml2::XMLElement *root = doc.FirstChildElement("head");
		if (root)
		{
			tinyxml2::XMLElement *p = root->FirstChildElement("version");
			if (p)
			{
				int a = 0;
				a = atoi(p->Attribute("value"));
				printf_s("从xml中读取到a的值为:%d\n",a);
				p->SetAttribute("value", 8);
				a = atoi(p->Attribute("value"));
				printf_s("保存到xml的value值为:%d\n", a);
				doc.SaveFile("XMLFile.xml");
			}
		}
	}
	catch (const std::exception&)
	{
		printf_s("xml读取出错\n");
	}

	system("PAUSE");
	return 0;
}
