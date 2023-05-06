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
    Cage *start = nullptr;
    int length = 1;
    do {
        if (curr->light == true) {
            curr->light = false;
            length++;
            if (start == nullptr)
                start = curr;
        }
        if (curr != first && curr->next->light == true && curr != start)
            curr = curr->next;
        else
            curr = curr->next->light == true ? curr->next : curr;
        countOp++;
    } while (curr != first);
    return length;
}

int Train::getOpCount() {
    if (countOp == 0) {
        Cage *curr = first;
        bool found = false;
        do {
            if (curr->light == true) {
                curr->light = false;
                found = true;
            }
            curr = curr->next;
            countOp++;
        } while (curr != first);
        if (found) {
            int len = getLength();
            countOp += len + 1;
        } else {
            countOp += getLength();
        }
    }
    return countOp;
}
