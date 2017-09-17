#include <iostream>


enum Colors { RED, GREEN, BLUE, PURPLE };


void printColor(Colors color) {
	switch (color)
	{
	case RED:
		std::cout << "Red";
		break;
	case GREEN:
		std::cout << "Green";
		break;
	case BLUE:
		std::cout << "Blue";
		break;
	case PURPLE:
		std::cout << "Purple";
		break;
	default:
		std::cout << "Not a color";
		break;
	}
}

int main() {

	//Use it as a made up type
	Colors myColor;
	//can be assigned
	myColor = GREEN;
	//Can be used in a conditional
	if (myColor == GREEN) {
		printColor(myColor);
	}

	//What is it really?
	std::cout << std::endl << myColor;

	return 0;
}