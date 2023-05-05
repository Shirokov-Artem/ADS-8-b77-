// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}

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
}

int Train::getLength() {
    if (first == nullptr)
        return 0;
    Cage *curr = first;
    int length = 0;
    do {
        curr = curr->next;
        length++;
    } while (curr != first);

    return length;
}

int Train::getOpCount() {
    if (first == nullptr)
        return 0;
    Cage *curr = first;
    bool prevLight = curr->light;
    curr = curr->next;
    int opCount = 1;
    do {
        if (curr->light != prevLight) {
            opCount++;
            prevLight = curr->light;
        }
        curr = curr->next;
        opCount++;
    } while (curr != first);
    return opCount;
}
