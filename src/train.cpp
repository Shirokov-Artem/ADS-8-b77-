// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCage(bool light) {
    Cage* cage = new Cage{light};
    if(first == nullptr) {
        first = cage;
        first->prev = first->next = first; 
    } else {
        cage->prev = first->prev;
        cage->next = first;
        first->prev->next = cage;
        first->prev = cage;
    }
}

int Train::getLength() {
    if(first == nullptr) {
        return 0;
    }
    Cage* curCage = first->next;
    bool curState = first->light;
    int CageC = 1;
    while(curCage != first) {
        if(curCage->light != curState) {
            curState = !curState;
            countOp += 2;
            curCage = curCage->next;
            CageC++;
        } else {
            CageC++;
            curCage = curCage->next;
        }
    }
    return CageC;
}

int Train::getOpCount() {
    return countOp;
}
