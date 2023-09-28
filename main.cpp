/***************************************************************
* wk1_reviewProgram.cpp
*
* Summary: The program is to review our coding skills by
 * creating a class named Textbook, to calculate the amount of books that
 * needs to be ordered for the students. Also calculates the total profit
 * made from ordering all the books and selling it.
*
* Test cases: 1221, 150, 30 , 1, 0     total order $4686.65, profit = $937.33
* 1221, 150, 30, 0, 0      prints out that it is not required, $0 profit = $0
* 1221, 150, 30, 1, 1      books ordered 105, total $7344.75, profit = $1468.95
*
* Author: Nelson Nguyen
* Created: 09/28/23
* Summary of Modifications:
 *
*
*
* ***************************************************************/


#include "Textbook.h" // class file

#include <iostream>
using namespace std; // cin cout


// function prototype
void EnterMenu(Textbook); //menu function


// beginning of main
int main() {
    Textbook textbook1; // class named textbook1

    EnterMenu(textbook1); // calling menu function with class

    return 0;
}
// end of main

// menu function to ask display book order results
void EnterMenu(Textbook textbook1) {

    // variables
    int exitnum, // exitcode if = 0;
            bookcode, // book number code
            onhand, // amount of books on hand
            enrollment, // students enrolled
            userinput, //user input for is_optional
            userinput2; // user input for is_used

    bool is_optional, // determining if reuqired or not
            is_used; // determining if it used or not

    double copyprice, // price per copy
    ordertotal, // total price for all the books ordered
    profit; // profit made from all the books sold


    // sets whole program in a do while loop until user enters 0 to exit
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
        // if userinput is 1, it is required
        if(userinput == 1) {
            is_optional = false;
            textbook1.SetIsOptional(is_optional);
        }
        // it is optional or not required
        else if (userinput == 0) {
            is_optional = true;
            textbook1.SetIsOptional(is_optional);
        }



        // asking user input for new or used
        cout << " 1 for new/0 for used: "; // prints statement
        cin >> userinput2; // asking for user input
        // if user input goes out of bounds, goes through while loop
        if(userinput2 < 0 || userinput2 > 1) {
            do { // do while loop if userinput is out of range
                cout << "Please try again." << endl; // error message
                cout << " 1 for new/0 for used: "; // prints statement again
                cin >> userinput2;
                // do while loops until its 0 or 1
            } while (userinput2 < 0 || userinput2 > 1);
        }
        // if user types in 1, then it is new, meaning it is not used
        //sets is_used variable to false and assigned in class
        if (userinput2 == 1) {
            is_used = false;
            textbook1.SetIsUsed(is_used);
        }

            // if user types in 0, then  it is not new
            // sets is_used variable to false and assigns in class
        else if(userinput2 == 0) {
            is_used = true;
            textbook1.SetIsUsed(is_used);
        }


        // prints out description of the order
        cout << "***************************************************" << endl;
        cout << "Book: " << textbook1.GetBookCode() << endl;
        cout << "Price: " << textbook1.GetCopyPrice() << endl;
        cout << "Inventory: " << textbook1.GetOnHand() << endl;
        cout << "Enrollment: " << textbook1.GetEnrollment() << endl << endl;

        // if the book is required and is used
        if(!textbook1.GetIsOptional() && textbook1.GetIsUsed()) {
            cout << "This book is required and used." << endl;
        }
        // if the book is required and is new
        if (!textbook1.GetIsOptional() && !textbook1.GetIsUsed()){
            cout << "This book is required and new." << endl;
        }
        // if the book is optional
        if(textbook1.GetIsOptional()) {
            cout << "This book is not required." << endl;
        }

        // if it is not optional, it is required
        // prints out the cost of the amount of books we need to order
        if (!textbook1.GetIsOptional()) {
            cout << "***************************************************" << endl;
            cout << "Need to order: " << textbook1.NeedToOrder() << endl;
            cout << "Total Cost: $";
            ordertotal = textbook1.GetCopyPrice() * textbook1.NeedToOrder();
            cout << ordertotal << endl;
        }

        // if it is optional, will print out $0 because most students
        // won't buy the books meaning it'll be 0.
        if(textbook1.GetIsOptional()) {
            cout << "***************************************************" << endl;
            cout << "Need to order: 0" << endl;
            cout << "Total Cost: $0" << endl;
        }
        cout << "***************************************************" << endl;
        cout << endl;
        cout << "Enter 1 to do another book, 0 to stop: ";
        cin >> exitnum; // asking for exitnum
        cout << "***************************************************" << endl;

        // calculates profit and sets it to the variable
        profit = ordertotal - (ordertotal * 0.8);

        // if exitnum = 0 , it will exit program and run
        // the profit description, otherwise it will continue running.
        if(exitnum == 0) {
            cout << "Total for all the orders: $" << ordertotal << endl;
            cout << "Profit: $" << profit << endl;
            cout << "***************************************************" << endl;
        }


    } while(exitnum != 0); // loops until user enters 0
}
