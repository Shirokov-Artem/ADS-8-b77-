// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCage(bool light) {
    Cage* newCage = new Cage;
    newCage->light = light;
    countOp += 2;
    if (first == nullptr) {
        first = newCage;
        newCage->next = newCage;
        newCage->prev = newCage;
    } else {
        last->next = newCage;
        newCage->prev = last;
        newCage->next = first;
        first->prev = newCage;
        last = newCage;
    }
}

int Train::getLength() {
    Cage* cur = first;
    int count = 1;
    while (cur != last) {
        count++;
        cur = cur->next;
    }
    return count;
}

int Train::getOpCount() {
    int count = 0;
    Cage* cur = first;
    do {
        if (cur->light != cur->next->light) {
            cur->light = cur->next->light;
            count++;
        }
        cur = cur->next;
    } while (cur != first);
    return count;
}
