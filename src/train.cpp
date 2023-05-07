// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCage(bool light) {
    Cage* cage = new Cage{ light, nullptr, nullptr };
    if (!first) {
        cage->prev = cage;
        cage->next = cage;
        first = cage;
    } else {
        cage->prev = first->prev;
        cage->next = first;
        first->prev->next = cage;
        first->prev = cage;
    }
    countOp++;
}

int Train::getLength() {
    if (!first) {
        return 0;
    }
    Cage* curCage = first->next;
    bool light = first->light;
    int length = 0;
    while (curCage != first) {
        if (curCage->light != light) {
            length++;
            light = !light;
        }
        curCage = curCage->next;
    }
    if (first->prev->light != first->light) {
        length++;
    }
    return length + 1;
}

int Train::getOpCount() {
    return countOp;
}
