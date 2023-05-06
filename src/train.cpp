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
    if (first == nullptr)
        return 0;
    countOp = 0;
    int maxLen = 0;
    int currLen = 0;
    Cage *currCage = first;
    do {
        if (currCage->light == true) {
            currLen = 1;
            Cage *nextCage = currCage->next;
            while (nextCage != currCage && nextCage->light == true) {
                currLen++;
                nextCage = nextCage->next;
            }
            if (currLen > maxLen)
                maxLen = currLen;
        }
        currCage = currCage->next;
        countOp++;
    } while (currCage != first);
    return maxLen;
}

int Train::getOpCount() {
    if (countOp == 0) {
        countOp++;
        Cage *currCage = first;
        while (currCage->light != true) {
            currCage = currCage->next;
            countOp++;
        }
        currCage->light = false;
        
        bool found = false;
        while (!found) {
            if (currCage->light == true) {
                currCage->light = false;
                found = true;
            } else {
                currCage = currCage->next;
                countOp++;
            }
        }
        getLength();
    }
    return countOp;
}
