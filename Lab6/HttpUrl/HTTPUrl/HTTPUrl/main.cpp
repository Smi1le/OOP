// HTTPUrl.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "HTTPUrl.h"

int main()
{
	try
	{
		CHttpUrl url("frp://vk.com/android.html");
	}
	catch (std::invalid_argument const &e)
	{
		std::cout << "Error -" << e.what() << std::endl;
	}
    return 0;
}

