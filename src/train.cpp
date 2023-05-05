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
    if (first == nullptr)
        return 0;
    countOp = 0;
    Cage *curr = first;
    do {
        curr = curr->next;
        countOp++;
    } while (curr != first && curr->light != true);
    return countOp;
}

int Train::getOpCount() {
    if (countOp == 0) {
        Cage *curr = first;
        while (curr->light != true) {
            curr = curr->next;
            countOp++;
        }
        curr->light = false;
        countOp++;
        curr = curr->next;
        while (curr->light != true) {
            curr = curr->next;
            countOp++;
        }
        curr->light = false;
        countOp++;
        getLength();
    }
    return countOp;
}
