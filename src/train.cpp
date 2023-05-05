// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    first = nullptr;
    opCount = 0;
}

void Train::addCage(bool light) {
    Cage* newCage = new Cage();
    newCage->light = light;
    if (!first) {
        first = newCage;
        first->next = first;
    } else {
        Cage* last = first->prev;
        last->next = newCage;
        newCage->prev = last;
        newCage->next = first;
        first->prev = newCage;
    }
}

int Train::getLength() {
    int count = 0;
    Cage* current = first;
    bool found = false;
    bool proceed = true;
    while (proceed) {
        if (current->light) {
            current->light = false;
            found = true;
            for (int i = 0; i < count; i++) {
                current = current->prev;
                opCount++;
            }
            count = 1;
        } else {
            count++;
        }
        current = current->next;
        opCount++;
        if (current == first && found) {
            found = false;
            proceed = true;
        } else if (current == first && !found) {
            proceed = false;
        }
    }
    return count;
}

int Train::getOpCount() {
    return opCount;
}
