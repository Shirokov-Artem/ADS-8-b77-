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
    int length = 0;
    bool currLight = first->light;
    Cage* curr = first->next;
    while (curr != first) {
        if (curr->light != currLight) {
            length++;
            currLight = curr->light;
        }
        curr = curr->next;
        countOp++;
    }
    if (currLight != first->light) {
        length++;
    }
    countOp++;
    return length;
}

int Train::getOpCount() {
    return countOp;
}
