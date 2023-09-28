/***************************************************************
* wk1_reviewProgram.cpp
*
* Summary: The program is to review our coding skills by
 * creating a class named Textbook, to calculate the amount of books that
 * needs to be ordered for the students. Also calculates the total profit
 * made from ordering all the books and selling it.
*
*
*
* Author: Nelson Nguyen
* Created: 09/28/23
* Summary of Modifications:
 *
*
*
* ***************************************************************/


// includes .h file to define the functions
#include "Textbook.h"



// default constructor
Textbook::Textbook() {
    bookcode = 0;
    onhand = 0;
    enrollment = 0;

    is_optional = false;
    is_used = false;

    copyprice = 0;
};

// mutators
void Textbook::SetBookCode(int bookcode) {
    this->bookcode = bookcode;
}

void Textbook::SetOnHand(int onhand) {
    this->onhand = onhand;
}

void Textbook::SetEnrollment(int enrollment) {
    this->enrollment = enrollment;
}

bool Textbook::SetIsOptional(bool is_optional) {
    this->is_optional = is_optional;
}

bool Textbook::SetIsUsed(bool is_used) {
    this->is_used = is_used;
}

double Textbook::SetCopyPrice(double copyprice) {
    this->copyprice = copyprice;
}


// defined needtoorder function to calculate how many books need
// to be ordered to determine the profit price.
int Textbook::NeedToOrder() {
    int order = 0; // local variable


    // if its used then 65% of the class will buy it
    // calculating amount of books ordered
    if(GetIsUsed()) {
        order = (GetEnrollment() * 0.65) - GetOnHand();
    }

    // if it's not used, meaning brand new, 90% of the class will
    // buy the new book and calculates the amount of books ordered.
    if (!GetIsUsed()) {
        order = (GetEnrollment() * 0.90) - GetOnHand();
    }

    // returns amount of books need to be ordered.
    return order;
}


