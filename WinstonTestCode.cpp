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




int get_output_pin()
{
	if (output_pins.find(GPIO::model) == output_pins.end())
	{
		cerr << "PWM not supported on this board\n";
		terminate();
	}

	return output_pins.at(GPIO::model);
}

inline void delay(int s)
{
	this_thread::sleep_for(chrono::seconds(s));
}

static bool end_this_program = false;

void signalHandler(int s)
{
	end_this_program = true;
}



int MoveMotor(int motor)
{


    cout << "GPIO ";
    cout << motor;
    cout << " is on.\n";
    GPIO::PWM p(motor, 50);
    auto val = 25.0;
    p.start(val);


    cout << "PWM running. Press CTRL+C to exit." << endl;

	while (!end_this_program)
	{
		delay(1);
	}

    p.stop();

	return 0;
}

int main()
{

	cout << "Hello World!\n";

    //set standard for way to number I/O pins - current BOARD = pin # of 40 pin GPIO header
    GPIO::setmode(GPIO::BOARD);
    

    // Pin Definitions
	int output_pin = get_output_pin();


    int motorLeft = 3;
    GPIO::setup(motorLeft, GPIO::OUT, GPIO::LOW);
    int motorRight = 5;
    GPIO::setup(motorRight, GPIO::OUT, GPIO::LOW);


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



