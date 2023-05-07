// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
    Cage* cage = new Cage{ light };
    if (first == nullptr) {
        first = cage;
        cage->prev = cage;
        cage->next = cage;
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
    }
    int length = 1;
    Cage* curCage = first->next;
    bool curState = first->light;
    while (curCage != first) {
        if (curCage->light != curState) {
            curState = !curState;
            length++;
        }
        curCage = curCage->next;
    }
    return length;
}

int Train::getOpCount() {
    return countOp;
}
