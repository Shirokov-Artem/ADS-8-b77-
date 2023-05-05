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
    int opCount = 0;
    if (first != nullptr) {
        Cage* cur = first;
        do {
            if (cur->light == true) {
                cur->light = false;
                opCount += 2;
                Cage* temp = cur;
                while (temp->next != cur) {
                    temp = temp->next;
                    temp->light = !temp->light;
                    opCount++;
                }
            }
            cur = cur->next;
            opCount++;
        } while (cur != first);
    }
    countOp = opCount;
    return opCount;
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
