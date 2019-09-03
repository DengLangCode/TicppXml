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
				printf_s("��xml�ж�ȡ��a��ֵΪ:%d\n",a);
				p->SetAttribute("value", 8);
				a = atoi(p->Attribute("value"));
				printf_s("���浽xml��valueֵΪ:%d\n", a);
				doc.SaveFile("XMLFile.xml");
			}
		}
	}
	catch (const std::exception&)
	{
		printf_s("xml��ȡ����\n");
	}

	system("PAUSE");
	return 0;
}
