#include <iostream>

#include <random>
#include <string>
#include <time.h>
#include <math.h>
#include "finance.h"
#include "fint.h"

int main()
{   
    finance<std::string> jerry = finance<std::string>(450000, "USD"); // $4500 as 450000 as to account for cents
    jerry.getCompoundValue();
    // jerry.getKeyCodes();

    // getCompoundValue();

    // getKeyCodes();

    return 0;

    srand(time(NULL));
    std::cout << "- Prepare for re-entry -\n";
    
    std::cout << "\nWhat is the starting value?\n" << 
                    "Capital : ";
    std::string capitalString;

    std::getline(std::cin, capitalString);

    // (filterNumerals(&capitalString, 0));
    std::cout << "Starting Capital : " << capitalString << "\n";

    return 0;
}