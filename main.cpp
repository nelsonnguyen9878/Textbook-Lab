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
    userinput,
    userinput2;

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

        // asking for number of books on hand and setting it
        cout << " number on hand: "; // prints statement
        cin >> onhand; // user input for onhand variable
        textbook1.SetOnHand(onhand); // setting it in class priv variaable

        // asking for prospective enrollment and setting it
        cout << " prospective enrollment: "; // prints statement
        cin >> enrollment; // user input for enrollment
        textbook1.SetEnrollment(enrollment); // setting class variable

        // bool asking if its optional or required
        cout << " 1 for reqd/0 for optional: ";
        cin >> userinput;
        if (userinput < 0 || userinput > 1) {
            do{
                cout << "Please try again." << endl;
                cout << " 1 for reqd/0 for optional: ";
                cin >> userinput;
            } while( userinput < 0 || userinput > 1);
        }
        if(userinput == 1) {
            is_optional = true;
            textbook1.SetIsOptional(is_optional);
        }


        // asking user input for new or used
        cout << " 1 for new/0 for used: "; // prints statement
        cin >> userinput2;
        if(userinput2 < 0 || userinput2 > 1) {
            do { // do while loop if userinput is out of range
                cout << "Please try again." << endl; // error message
                cout << " 1 for new/0 for used: "; // prints statement again
                cin >> userinput2;
            } while (userinput2 < 0 || userinput2 > 1); // loops until its 0 or 1
            if (userinput2 == 1) {
                is_used = true;
                textbook1.SetIsUsed(is_used);
            }
            else if(userinput != 1) {
                is_used = false;
                textbook1.SetIsUsed(is_used);
            }
        }



        cout << "***************************************************" << endl;
        cout << "Book: " << textbook1.GetBookCode() << endl;
        cout << "Price: " << textbook1.GetCopyPrice() << endl;
        cout << "Inventory: " << textbook1.GetOnHand() << endl;
        cout << "Enrollment: " << textbook1.GetEnrollment() << endl << endl;

        if(textbook1.GetIsOptional() && textbook1.GetIsUsed()) {
            cout << "This book is required and used." << endl;
        }
        else if (textbook1.GetIsOptional() && !textbook1.GetIsUsed()){
            cout << "This book is required and new." << endl;
        }
        else if(!textbook1.GetIsOptional()) {
            cout << "This book is not required." << endl;
        }
        cout << "***************************************************" << endl;
        cout << "Need to order: " << textbook1.NeedToOrder() << endl;
        cout << "Total Cost: $";
        cout << textbook1.GetCopyPrice() * textbook1.NeedToOrder() << endl;
        cout << "***************************************************" << endl;
        cout << endl;
        cout << "Enter 1 to do another book, 0 to stop: ";
        cin >> exitnum; // asking for exitnum


    } while(exitnum != 0); // loops until user enters 0


}
