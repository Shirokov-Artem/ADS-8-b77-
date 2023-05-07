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
        cage->next = first;
        cage->prev = first->prev;
        first->prev->next = cage;
        first->prev = cage;
        countOp++;
    }
}

int Train::getLength() {
    if (first == nullptr) {
        return 0;
    } else {
        bool curState = first->light;
        Cage* curCage = first->next;
        int length = 1;
        while (curCage != first) {
            if (curCage->light != curState) {
                curState = curCage->light;
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
