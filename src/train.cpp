// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCage(bool light) {
    Cage* cage = new Cage{ light, nullptr, nullptr };
    if (first == nullptr) {
        cage->prev = cage;
        cage->next = cage;
        first = cage;
    } else {
        cage->prev = first->prev;
        cage->next = first;
        first->prev->next = cage;
        first->prev = cage;
    }
}

int Train::getLength() {
    if (first == nullptr) {
        return 0;
    }
    Cage* curCage = first->next;
    bool light = first->light;
    int length = 1;
    while (curCage != first) {
        if (curCage->light != light) {
            length++;
            light = !light;
        }
        curCage = curCage->next;
    }
    return length;
}

int Train::getOpCount() {
    return countOp;
}
