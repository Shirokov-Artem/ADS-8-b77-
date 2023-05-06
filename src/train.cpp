// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

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
    ++length;
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
        bool isLight = false;
        int count = 0;
        while (count < length) {
            if (curr->light) {
                isLight = true;
            } else if (isLight) {
                curr->light = true;
                countOp++;
                isLight = false;
            } else {
                curr->light = false;
            }
            curr = curr->next;
            count++;
        }
        countOp += length;
    }
    return countOp;
}
