// HTTPUrl.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "HTTPUrl.h"

int main()
{
	CHttpUrl url("frp://vk.com/android.html");
	std::cout << url.ToStringProtocol() << std::endl;
	std::cout << url.GetDomain() << std::endl;
	std::cout << url.ToStringPort() << std::endl;
	std::cout << url.GetDocument() << std::endl;
	std::cout << url.GetURL() << std::endl;
    return 0;
}

