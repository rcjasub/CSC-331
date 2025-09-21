// Coded by:  Jocsan Rodriguez

#include <iostream>
#include "clockType.h"
using namespace std;

int main() {
   
    clockType myClockTime;
    clockType otherClockTime;

    myClockTime.setTime(14, 30, 0);

    int nycHours, nycMinutes, nycSeconds;
    myClockTime.getTime(nycHours, nycMinutes, nycSeconds);

    int londonHours = (nycHours + 5) % 24;  // wrap around 24 hours
    otherClockTime.setTime(londonHours, nycHours, nycSeconds);

    cout << "New York Time: ";
    myClockTime.printTime();
    cout << endl;

    cout << "London Time: ";
    otherClockTime.printTime();
    cout << endl;

	//check if times are equal
    if (myClockTime == otherClockTime) {
        cout << "Times are equal!" << endl;
    }
    else {
        cout << "Times are different!" << endl;
    }

    return 0;
}
