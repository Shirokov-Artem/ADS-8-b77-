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
    do {
        if (curr->light == true) {
            start = curr;
            length = 1;
        } else {
            length++;
        }
        curr = curr->next;
        countOp++;
    } while (curr != first && curr != start);
    return length;
}

int Train::getOpCount() {
    if (countOp == 0) {
        Cage *curr = first;
        do {
            if (curr->light) {
                curr->light = false;
                curr = curr->next;
                continue;
            }
            if (!curr->next->light) {
                curr = curr->next;
            } else {
               curr = curr->next;
               curr->light = false;
            }
        } while (curr != first);
        countOp = getLength();
    }
    return countOp;
}
