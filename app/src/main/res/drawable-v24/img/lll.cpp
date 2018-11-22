//**********************************************************************
// DESCRIPTION:   Time class Implementation file
// Object-oriented approach to modelling time for the purpose 
// of displaying it in standard and military formats.
//**********************************************************************
#include <iostream>
#include <iomanip>
#include <cstring>

class Time 
{
public:
Time(void); 	// constructor: set hour, minute & second to zero

   // set time hour, minute and second to values h, m & s, if valid
   // else set invalid component (hour, minute, second) to zero
   void setTime(const int h, const int m, const int s);

   // function members (actions)
   void displayStandard(void);   // format is: hh:mm:ss AM/PM
   void displayMilitary(void);   // format is: hhmm
private:
   // data members (attributes or characteristics)
   int hour;		// 0..23
   int minute;		// 0..59
   int second;		// 0..59
}; // end class Time


Time::Time(void) 	// constructor: set hour, minute, second to zero
{
   hour = minute = second = 0;
}

