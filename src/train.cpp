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
                currLen += 1;
                nextCage = nextCage->next;
            }
            if (currLen > maxLen)
                maxLen = currLen;
        }
        currCage = currCage->next;
    } while (currCage != first);
    return maxLen;
}

int Train::getOpCount() {
    if (countOp == 0) {
        countOp = 0;
        if (first != nullptr) {
            Cage *currCage = first;
            do {
                if (currCage->light == true && currCage->next->light == true) {
                    currCage->light = false;
                    currCage->next->light = false;
                    countOp += 2;
                    if (currCage->prev == currCage) {
                        currCage = currCage->next;
                    } else {
                        currCage = currCage->prev;
                    }
                } else {
                    currCage = currCage->next;
                    countOp += 1;
                }
            } while (currCage != first);
        }
    }
    return countOp;
}
