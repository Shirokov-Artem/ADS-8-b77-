// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCage(bool light) {
    Cage* cage = new Cage{ light };
    if (first == nullptr) {
        first = cage;
        first->next = cage;
        first->prev = cage;
    } else {
        cage->prev = first->prev;
        cage->next = first;
        first->prev->next = cage;
        first->prev = cage;
        countOp++;
    }
}

int Train::getLength() {
    if (first == nullptr) {
        return 0;
    } else {
        Cage* curCage = first->next;
        int length = 1;
        while (curCage != first) {
            if (curCage->light != curCage->prev->light) {
                length++;
            }
            curCage = curCage->next;
        }
        return length;
    }
}

int Train::getOpCount() {
    return countOp;
}
