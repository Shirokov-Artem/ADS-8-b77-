// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCage(bool light) {
    Cage *cage = new Cage{light, nullptr, nullptr};
    if (first == nullptr) {
        first = cage;
        first->next = first;
        first->prev = first;
    } else {
        Cage *last = first->prev;
        last->next = cage;
        cage->prev = last;
        cage->next = first;
        first->prev = cage;
    }
    countOp = 0;
}

int Train::getLength() {
    if (first == nullptr) {
        return 0;
    }
    Cage* end = first->prev;
    Cage* curr = first;
    int length = 0;
    do {
        if (curr->light != end->light) {
            length++;
        }
        curr = curr->next;
        end = end->prev;
        countOp++;
    } while (curr != first);
    countOp++;
    return length + 1;
}

int Train::getOpCount() {
    return countOp;
}
