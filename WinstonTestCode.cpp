
#include </usr/include/JetsonGPIO/include/JetsonGPIO.h>
#include <iostream>

//using namespace GPIO; // optional


int MoveMotor(int motor)
{


    std::cout << "GPIO ";
    std::cout << motor;
    std::cout << " is on.\n";

	return 0;
}


int main()
{

	std::cout << "Hello World!\n";

    int motorLeft = 3;
    int motorRight = 5;



    MoveMotor(motorLeft);


	//std::cin.clear(); // reset any error flags
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find an enter character
    //std::cin.get(); // get one more char from the user
    return 0;
}



