
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

//In a realworld application this function would be changed
// You would initialise specific GPIO depending on the hardware
int readThrottlePositionSensor() {

    return rand() % 1024;
}

// Converting ADC value to throttle position percentage
double convertToThrottlePosition(int adcValue) {
    const int ADC_MAX = 1023;  
    return (static_cast<double>(adcValue) / ADC_MAX) * 100.0;
}

int main() {
    srand(static_cast<unsigned>(time(0)));  

    while (true) {
        int adcValue = readThrottlePositionSensor();  
        double throttlePosition = convertToThrottlePosition(adcValue);  

        cout << "ADC Value: " << adcValue << " -> Throttle Position: " << throttlePosition << "%" << endl;


        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}
