#include <iostream>
#include <string>
#include <sstream>
#include </usr/include/JetsonGPIO/include/JetsonGPIO.h>
//using namespace GPIO; // optional


int MoveMotor(int motor)
{

/*
    std::ostringstream gpioNum;

    gpioNum << "GPIO " << motor << " is on.";
    std::string var = gpioNum.str() ;
*/
	return 0;
}

int main()
{

	std:cout << "Hello World!\r";

    int motorLeft = 3;
    int motorRight = 5;



    MoveMotor(motorLeft);


	std::cin.clear(); // reset any error flags
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find an enter character
    //std::cin.get(); // get one more char from the user
    return 0;
}



