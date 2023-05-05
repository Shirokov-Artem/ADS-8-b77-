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
        Cage* lastCage = first->prev;
        lastCage->next = newCage;
        newCage->next = first;
        newCage->prev = lastCage;
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
    int count = 2;
    while (currentCage != first) {
        if (!currentCage->light) {
            countOp += count;
            currentCage->light = true;
            count = 2;
        }
        count++;
        currentCage = currentCage->next;
    }
    countOp += count;
    return countOp;
}
