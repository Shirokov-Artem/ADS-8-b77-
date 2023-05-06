// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

int Train::countLength() const {
    int length = 0;
    if (first == nullptr) {
        return length;
    }
    length++;
    Cage* curr = first->next;
    while (curr != first) {
        ++length;
        curr = curr->next;
    }
    return length;
}

void Train::addCage(bool light) {
    auto* newCage = new Cage(light, nullptr, nullptr);
    if (first == nullptr) {
        first = newCage;
        first->next = first;
        first->prev = first;
    } else {
        Cage* last = first->prev;
        last->next = newCage;
        newCage->prev = last;
        newCage->next = first;
        first->prev = newCage;
    }
    countOp = 0;
}

int Train::getLength() {
    int length = 0;
    if (first == nullptr) {
        return length;
    }
    Cage* curr = first;
    do {
        if (curr->light) {
            ++length;
        }
        ++length;
        curr = curr->next;
    } while (curr != first);
    length--;
    return length;
}

int Train::getOpCount() {
    if (countOp == 0) {
        Cage* curr = first;
        int length = countLength();
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
        countOp = length;
    }
    return countOp;
}
