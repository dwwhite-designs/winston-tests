//compile with g++ -o your_program_name your_source_code.cpp -lJetsonGPIO


//Headers
#include <iostream>
#include <chrono>
#include <thread>
#include <map>
#include <string>
#include <signal.h> //signal handling
#include </usr/include/JetsonGPIO/include/JetsonGPIO.h> //Jetson GPIO C++ controls


//Namespace
using namespace std;
//using namespace GPIO; // optional


const map<string, int> output_pins{{"JETSON_XAVIER", 18}, {"JETSON_NANO", 33}};

int MoveMotor(int motor)
{


    cout << "GPIO ";
    cout << motor;
    cout << " is on.\n";

	return 0;
}


int get_output_pin()
{
	if (output_pins.find(GPIO::model) == output_pins.end())
	{
		cerr << "PWM not supported on this board\n";
		terminate();
	}

	return output_pins.at(GPIO::model);
}


int main()
{

	cout << "Hello World!\n";

    //set standard for way to number I/O pins - current BOARD = pin # of 40 pin GPIO header
    GPIO::setmode(GPIO::BOARD);
    

    // Pin Definitions
	int output_pin = get_output_pin();


    int motorLeft = 3;
    int motorRight = 5;

    cout << "output pin: ";
    cout << output_pin;
    cout << "\n";

    MoveMotor(motorLeft);


	//std::cin.clear(); // reset any error flags
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find an enter character
    //std::cin.get(); // get one more char from the user


    GPIO::cleanup();
    return 0;
}



