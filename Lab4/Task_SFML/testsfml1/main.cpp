#pragma warning (disable: 4996)
#include "Shapes.h"

int main()
{
	std::string name = "input.txt";
	CShapesController shapes;
	shapes.CreateElements(ReadFromFile(name));
	shapes.DisplayShapes();
	return 0;
}