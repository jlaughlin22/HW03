#include "readint.h"
#include <stdexcept>
#include <string>
#include <iostream>
#include <limits>
#include <ios>
#include <typeinfo>
using namespace std;

int read_int(const string &prompt, int low, int high)
{
    if( high <= low ){
        throw invalid_argument("Invalid values have been entered.");
    }
    int input;
    while (true) {
             
        try {
            cout << prompt; //<< endl;
            cin >> input;
            if( !(input >= low && input <= high) ){
                throw range_error("The entered value is outside the bounds of the range.");
            }
            return input;
        }
        catch (range_error& m) {
            cout << "The entered value is outside the bounds of the range.\n";
        }
        catch(ios_base::failure& ex) {
            cout << "Error1\n";
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n'); 
        }
        catch(invalid_argument& t) {

        }
    }
    
    
}
