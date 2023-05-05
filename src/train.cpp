// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}

void Train::addCage(bool light) {
    Cage* newCage = new Cage();
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
    int length = 0;
    Cage* current = first;
    Cage* last = current->prev;   
    while (current != nullptr) {
        if (current->light) {
            if (length == 1) {
                length--;
                countOp++;
            } else if (length > 1) {
                for (int i = 0; i < length - 1; i++) {
                    last = last->prev;
                    countOp++;
                }
                last->next = current->next;
                current->next->prev = last;
                Cage* temp = current->next;
                delete current;
                current = temp;
                length = 0;
            } else {
                current = current->next;
            }
        } else {
            length++;
            last = current;
            current = current->next;
        }
        countOp++;
    }
    return length;
}

int Train::getOpCount() {
    return countOp;
}
