#include "Textbook.h"

#include <iostream>
using namespace std;



void EnterMenu(Textbook);

int main() {
    Textbook textbook1;

    EnterMenu(textbook1);



    return 0;
}

void EnterMenu(Textbook textbook1) {
    // variables
    int exitnum,
    bookcode,
    onhand,
    enrollment,
    userinput;

    bool is_optional = false,
    is_used = false;

    double copyprice;



    do {
        // asking and setting bookcode
        cout << "Please enter the book code: "; // prints statement
        cin >> bookcode; // user input for bookcode
        textbook1.SetBookCode(bookcode); // sets class bookcode

        // asking for price of a single copy and setting it.
        cout << " single copy price: "; // prints statement
        cin >> copyprice; // user input for copyprice
        textbook1.SetCopyPrice(copyprice); // sets the class copyprice

        // asking for prospective enrollment and setting it
        cout << " prospective enrollment: "; // prints statement
        cin >> enrollment; // user input for enrollment
        textbook1.SetEnrollment(enrollment); // setting class variable

        // bool asking if its optional or required
        cout << " 1 for reqd/0 for optional: ";
        cin >> userinput;
        do{
            cout << "Please try again." << endl;
            cout << " 1 for reqd/0 for optional: ";
            cin >> userinput;
        } while( userinput < 0 || userinput > 1);
        if(userinput = 1) {
            is_optional = true;
        }

        // asking user input for new or used
        cout << " 1 for new/0 for used: "; // prints statement
        cin >> userinput; // asking for userinput
        do { // do while loop if userinput is out of range
            cout << "Please try again." << endl; // error message
            cout << " 1 for new/0 for used: "; // prints statement again
            cin >> userinput; // asking for user input again
        } while (userinput < 0 || userinput > 1); // loops until its 0 or 1
        cout << "***************************************************" << endl;

        cout << "Book: " << textbook1.GetBookCode();
        cout << "Price: " << textbook1.GetCopyPrice();
        cout << "Inventory: " << textbook1.GetOnHand();
        cout << "Enrolmment: " << textbook1.GetEnrollment();

        if()
        cout << "***************************************************" << endl;


        cin >> exitnum; // asking for exitnum
    } while(exitnum != 0); // loops until user enters 0


}
