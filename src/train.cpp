// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCage(bool light) {
    Cage* newCage = new Cage;
    newCage->light = light;
    if (first == nullptr) {
        newCage->next = newCage;
        newCage->prev = newCage;
        first = newCage;
    } else {
        newCage->next = first;
        newCage->prev = first->prev;
        first->prev->next = newCage;
        first->prev = newCage;
    }
}

int Train::getLength() {
    if (first == nullptr) {
        return 0;
    }
    int maxLength = 0;
    Cage *cur = first;
    do {
        int currentLength = 0;
        Cage *startCage = cur;
        while (cur->light == false) {
            cur = cur->next;
            currentLength++;
        }
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
        while (cur != startCage && cur->light == true) {
            cur->light = false;
            cur = cur->prev;
            countOp++;
        }
    } while (cur->next != first);
    return maxLength;
}

int Train::getOpCount() {
    return countOp;
}
