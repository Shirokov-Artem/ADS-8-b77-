// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCage(bool light) {
    Cage* item = new Cage;
    item->light = light;
    item->next = item->prev = item;

    if(first == nullptr) {
        first = item;
    } else {
        item->prev = first->prev;
        item->next = first;
        first->prev->next = item;
        first->prev = item;
        first = item;
    }
}

int Train::getLength() {
    if(first == nullptr) {
        return 0;
    }
    int CageC = 0;
    bool curState = true;
    Cage* curCage = first;

    do {
        curState = curCage->light;
        curCage = curCage->next;
        CageC++;

        while(curCage->light != curState) {
            curCage = curCage->next;
            countOp++;
        }

        countOp++;
        curCage->light = !curState;
        curCage = curCage->prev;

        while(curCage != first) {
            curCage = curCage->prev;
            countOp++;
        }
        countOp++;
    } while(curCage != first);

    return CageC;
}

int Train::getOpCount() {
    return countOp;
}
