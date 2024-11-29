#include <iostream>
#include <string>
#include <sstream>

double extractNumeric(const std::string& user_input) {
    std::istringstream iss(user_input);
    double value;
        if (iss >> value) {
        char remaining;                                                 //Checks if there is extra stuff after the num
        if (iss >> remaining) {
            return -999999.99;                                          //Invalid input by extra stuff
        }
        return value;                                                   // If given a valid number
    }
    return -999999.99;                                                  // Invalid input by other exceptions
}

int main() {
    std::string user_input;
    while (true) {                                                      //Infinite Loop till broken out of
        std::cout << "Enter a number with lenght of 7 (END to quit): ";
        std::getline(std::cin, user_input);                             //Reads in the user given value
           if (user_input == "END") {                                   //Checks if user entered "END" as the first thing
            break;
        }
        double result = extractNumeric(user_input);                     //Function call

        if (result == -999999.99) {                                     //Runs if the function detects its an invalid input
            std::cout << "Invalid input: " << user_input << std::endl;  //Prints invalid
        } else {                                                        
            std::cout << "Extracted value: " << result << std::endl;    //Prints the user input in double form
        }
    }
    
    std::cout << "Program terminated." << std::endl;                    //Only runs once the while loop is broke out of
    return 0;
}