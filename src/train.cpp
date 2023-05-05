// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}

void Train::addCage(bool light) {
    Cage* newCage = new Cage();
    newCage->light = light;
    if (!first) {
        first = newCage;
        first->next = first;
        first->prev = first;
    } else {
        Cage* last = first->prev;
        newCage->prev = last;
        newCage->next = first;
        last->next = newCage;
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
            if (count > 1) {
                for (int i = 0; i < count-1; i++) {
                    current = current->prev;
                    if (current == nullptr) {
                        return 0;
                    }
                    countOp++;
                }
            }
            count = 1;
        } else {
            count++;
        }
        current = current->next;
        if (current == nullptr) {
            return 0;
        }
        countOp++;
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
    return countOp;
}
