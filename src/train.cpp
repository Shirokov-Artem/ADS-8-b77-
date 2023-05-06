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
    Cage *start = nullptr;
    Cage *curr = first;
    do {
        if (curr->light == true) {
            start = curr;
            break;
        }
        curr = curr->next;
        countOp++;
    } while (curr != first);
    if (start == nullptr)
        start = first;
    int length = 0;
    curr = start;
    do {
        if (curr->light == true) {
            length++;
        } else {
            break;
        }
        curr = curr->next;
        countOp++;
    } while (curr != start);
    return length;
}

int Train::getOpCount() {
    if (countOp == 0) {
        countOp++;
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
            getLength();
        }
    }
    return countOp;
}
