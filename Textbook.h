/***************************************************************
* wk1_reviewProgram.h
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

#ifndef CS260BOOKSTORE_TEXTBOOK_H
#define CS260BOOKSTORE_TEXTBOOK_H

// each book ask for: a code for the book, single copy cost for the book,
// the current number of books on hand, the prospective class enrollment,
// if it required or not, new/used in the past
// output the information



class Textbook {
private: // private variables
    int bookcode,
            onhand,
            enrollment;

    bool is_optional,
            is_used;

    double copyprice;


public:
    Textbook(); // default constructor

    // accessors
    const int GetBookCode() {return bookcode;}
    const int GetOnHand() {return onhand;}
    const int GetEnrollment() {return enrollment;}

    const bool GetIsOptional() {return is_optional;}
    const bool GetIsUsed() {return is_used;}

    const double GetCopyPrice() {return copyprice;}

    // mutators
    void SetBookCode(int);
    void SetOnHand(int);
    void SetEnrollment(int);

    bool SetIsOptional(bool);
    bool SetIsUsed(bool);

    double SetCopyPrice(double);

    // function calculates amount of books need to order.
    int NeedToOrder();


};


#endif //CS260BOOKSTORE_TEXTBOOK_H
