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
    Cage* currentWagon = first;
    if (!currentWagon->light) {
        currentWagon->light = true;
    }
    int result = 0;
    int wagonCount = 0;
    while (true) {
        currentWagon = currentWagon->next;
        countOp++;
        wagonCount++;
        while (!currentWagon->light) {
            currentWagon = currentWagon->next;
            countOp++;
            wagonCount++;
        }
        currentWagon->light = false;
        result = wagonCount;
        while (wagonCount > 0) {
            countOp++;
            wagonCount--;
            currentWagon = currentWagon->prev;
        }
        if (!currentWagon->light) {
            return result;
        }
    }
}

int Train::getOpCount() {
    return countOp;
}
