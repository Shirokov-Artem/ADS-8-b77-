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
    if (first == last && first->light == true)
        return 1;
    countOp = 0;
    Cage *curr = first;
    do {
        if (curr->light == true) {
            curr = curr->next;
            countOp++;
            break;
        }
        curr = curr->next;
        countOp++;
    } while (curr != first);
    Cage *start = curr;
    int length = 0;
    bool exit = false;
    do {
        if (curr->light == false) {
            exit = true;
        } else {
            length++;
        }
        curr = curr->next;
        countOp++;
    } while (curr != start && !exit);
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
