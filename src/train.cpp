// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
    Cage* newCage = new Cage;
    newCage->light = light;
    newCage->next = nullptr;
    if (first == nullptr) {
        first = newCage;
    } else {
        Cage* curCage = first;
        while (curCage->next != nullptr) {
            curCage = curCage->next;
        }
        curCage->next = newCage;
    }
}

int Train::getLength() {
    Cage* curCage = first;
    int length = 0;
    bool isMovL = false;
    while (curCage != nullptr) {
        ++length;
        if (isMovL) {
            curCage = curCage->prev;
        } else {
            curCage = curCage->next;
        }
        if (curCage != nullptr) {
            if (curCage->light) {
                if (isMovL) {
                    if (curCage->prev == nullptr) {
                        curCage = nullptr;
                    } else {
                        curCage = curCage->prev->prev;
                    }
                } else {
                    if (curCage->next == nullptr) {
                        curCage = nullptr;
                    } else {
                        curCage = curCage->next->next;
                    }
                }
                isMovL = !isMovL;
                if (curCage != nullptr) {
                    countOp += length;
                    length = 0;
                }
            }
        } else {
            isMovL = true;
            curCage = first->prev;
            if (curCage != nullptr) {
                countOp += length * 2;
                length = 0;
            }
        }
    }
    return length;
}

int Train::getOpCount() {
    return countOp;
}
