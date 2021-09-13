#include <iostream>
#include <cstudio>
#include </usr/include/JetsonGPIO/include/JetsonGPIO.h>
//using namespace GPIO; // optional


int main()
{

	std::cout << "Hello World!\r";

    int motorLeft = 3;
    int motorRight = 5;

	std::cin.clear(); // reset any error flags
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find an enter character
    //std::cin.get(); // get one more char from the user
    return 0;
}


int MoveMotor(int motor)
{

	return 0;
}
