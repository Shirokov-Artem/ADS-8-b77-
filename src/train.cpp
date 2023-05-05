// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCage(bool light) {
    if (first == nullptr) {
        first = new Cage(light);
        first->next = first;
        first->prev = first;
    } else {
        Cage* newCage = new Cage(light);
        Cage* lastCage = first->prev;
        lastCage->next = newCage;
        newCage->prev = lastCage;
        newCage->next = first;
        first->prev = newCage;
    }
}

int Train::getLength() {
    if (first == nullptr) {
        return 0;
    }
    int count = 1;
    Cage* currentCage = first->next;

    while (currentCage != first) {
        count++;
        currentCage = currentCage->next;
    }
    return count;
}

int Train::getOpCount() {
    if (first == nullptr) {
        return 0;
    }
    Cage* currentCage = first->next;
    int opCount = 2;
    while (currentCage != first) {
        if (!currentCage->light) {
            opCount += 2;
            currentCage->light = true;
        }
        opCount++;
        currentCage = currentCage->next;
    }
    if (!first->light) {
        opCount += 2;
    }
    return opCount;
}
