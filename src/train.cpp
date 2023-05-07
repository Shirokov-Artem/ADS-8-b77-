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
    } else if (first->next == first) {
        return 1;
    }
    int length = 1;
    bool curState = first->light;
    Cage* curCage = first->next;
    do {
        if (curCage->light != curState) {
            curState = !curState;
            length++;
        }
        curCage = curCage->next;
    } while (curCage != first);

    return length;
}

int Train::getOpCount() {
    return countOp;
}
