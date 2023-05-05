// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr), last(nullptr) {}

void Train::addCage(bool light) {
    Cage* newCage = new Cage;
    newCage->light = light;
    newCage->next = nullptr;
    if (first == nullptr) {
        first = last = newCage;
        newCage->prev = nullptr;
    } else {
        last->next = newCage;
        newCage->prev = last;
        last = newCage;
    }
}

int Train::getLength() {
    Cage* cur = first;
    int count = 0;
    bool isMovingL = false;
    while (cur != nullptr) {
        ++count;
        if (isMovingL) {
            cur = cur->prev;
        } else {
            cur = cur->next;
        }
        if (cur != nullptr) {
            if (cur->light) {
                if (isMovingL) {
                    cur = cur->next;
                } else {
                    cur = cur->prev;
                }
                isMovingL = !isMovingL;
                countOp += count * 2;
                count = 0;
            } else {
                cur->light = true;
            }
        }
    }
    return count;
}

int Train::getOpCount() {
    return countOp;
}
