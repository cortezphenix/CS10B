/*
Cortez Phenix
The 21st of January, 2021
CS10B, Mr. Harden
Assignment 1.1

This program uses variables, type conversions, and if-then else-if-then statements, in order to
allow the user to input a specially formatted date, then determine if the date is "magic" or not,
meaning that the month times the day is equal to the year.
*/

#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    // Initialize variables
    std::string mm,dd,yy;

    // Prompt for input
    std::cout << "Enter a date in the format month/day/2-digit-year: ";

    /* Then split it using std::getline() with delimiter '/'
    and assign them to the appropiate variables*/
    std::getline(std::cin, mm,'/');
    std::getline(std::cin, dd, '/');
    std::cin >> yy;

    // Convert the string variables to int
    int month, day, year;
    month = std::stoi(mm);
    day = std::stoi(dd);
    year = std::stoi(yy);

    //Determines whether the given date is "magic" or not!
    if (month * day == year){
        std::cout << "\nThat is a magic date!\n";
    }

    else if (month * day != year){
        std::cout << "\nThat is not a magic date!\n";
    }

    return 0;
}

/*
Sample Run:

Enter a date in the format month/day/2-digit-year: 6/25/02

That is not a magic date!
*/

