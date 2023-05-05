// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
    if (first == nullptr) {
        first = new Cage;
        first->next = first;
        first->prev = first;
        first->light = light;
    } else {
        Cage* newCage = new Cage;
        newCage->prev = first->prev;
        newCage->next = first;
        first->prev->next = newCage;
        first->prev = newCage;
        newCage->light = light;
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
    if (first != nullptr) {
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
    }
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
