// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
    if (first == nullptr) {
        first = new Cage{light, nullptr, nullptr};
        first->next = first->prev = first;
    } else {
        Cage* prevLastCage = first->prev;
        prevLastCage->next = new Cage{ light, first, prevLastCage };
        first->prev = prevLastCage->next;
    }
}

int Train::getLength() {
    if (countOp == 0) {
        if (first == nullptr) {
            return 0;
        }
        int length = 0;
        Cage* currentCage = first;
        do {
            if (!currentCage->light) {
                length++;
            } else {
                Cage* prevCage = currentCage->prev;
                int i = length - 1;
                while (i--) {
                    prevCage = prevCage->prev;
                    countOp++;
                }
                if (prevCage == first->prev) {
                    break;
                }
                length = 1;
                currentCage = prevCage->next;
            }
            currentCage = currentCage->next;
        } while (currentCage != first);
        countOp += length;
        return length;
    } else {
        return countOp;
    }
}

int Train::getOpCount() {
    getLength();
    return countOp;
}
