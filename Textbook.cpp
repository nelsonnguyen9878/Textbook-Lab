//
// Created by Nelso on 9/26/2023.
//

#include "Textbook.h"



Textbook::Textbook() {

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



