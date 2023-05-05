// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
    Cage* newCage = new Cage;
    newCage->light = light;
    if (first == nullptr) {
        first = newCage;
        newCage->next = first;
        newCage->prev = first;
    } else {
        newCage->next = first;
        newCage->prev = first->prev;
        first->prev->next = newCage;
        first->prev = newCage;
        first = newCage;
    }
}

int Train::getLength() {
    int length = 0;
    if (first != nullptr) {
        Cage* cur = first;
        do {
            length++;
            cur = cur->next;
        } while (cur != first);
    }
    return length;
}

int Train::getOpCount() {
    int opCounter = 0;
    Cage* cur = first;
    do {
        if (cur->light == true) {
            cur->light = false;
            opCounter += 2;
            Cage* temp = cur->next;
            while (temp != cur) {
                temp->light = !temp->light;
                opCounter++;
                temp = temp->next;
            }
        }
        cur = cur->next;
        opCounter++;
    } while (cur != first);
    countOp = opCounter;
    return opCounter;
}

Train::~Train() {
    if (first != nullptr) {
        Cage* cur = first;
        do {
            Cage* temp = cur->next;
            delete cur;
            cur = temp;
        } while (cur != first);
    }
}
