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
    int maxLength = 0;
    int currLength = 0;
    Cage *curr = first;
    do {
        if (curr->light == true) {
            currLength = 1;
        } else {
            currLength = 0;
        }
        Cage *it = curr->next;
        while (it != curr) {
            if (it->light == true) {
                currLength++;
            } else {
                break;
            }
            it = it->next;
        }
        if (currLength > maxLength) {
            maxLength = currLength;
        }
        curr = curr->next;
        countOp++;
    } while (curr != first);
    return maxLength;
}

int Train::getOpCount() {
    if (countOp == 0) {
        countOp = 0;
        if (first != nullptr) {
            Cage *curr = first;
            Cage *next = curr->next;
            do {
                if (curr->light && next->light) {
                    curr->light = false;
                    next->light = false;
                    curr = curr->prev;
                    next = curr->next;
                } else {
                    curr = next;
                    next = curr->next;
                }
                countOp++;
            } while (curr != first);
        }
    }
    return countOp;
}
