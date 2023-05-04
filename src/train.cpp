// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCage(bool light) {
    if (first == nullptr) {
        first = new Cage;
        first->next = first;
        first->prev = first;
        first->light = light;
    } else {
        Cage* last = first->prev;
        last->next = new Cage;
        last->next->prev = last;
        last = last->next;
        last->next = first;
        first->prev = last;
        last->light = light;
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
