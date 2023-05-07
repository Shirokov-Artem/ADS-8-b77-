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
    if (first == nullptr) {
        return 0;
    }
    Cage* start = first;
    if (!first->light) {
        while (start->next != first && !start->next->light) {
            start = start->next;
            countOp++;
        }
    }
    int length = 0;
    bool prevLight = first->light;
    Cage* curr = first->next;
    while (curr != first) {
        if (prevLight != curr->light) {
            length++;
            prevLight = curr->light;
        }
        curr = curr->next;
        if (curr == start) {
            break;
        }
        countOp++;
    }
    if (prevLight != first->light) {
        length++;
    }
    if (start != first) {
        curr = start->next;
        while (curr != first) {
            if (prevLight != curr->light) {
                length++;
                prevLight = curr->light;
            }
            curr = curr->next;
            countOp++;
        }
        if (prevLight != start->light) {
            length++;
        }
    }
    countOp++;
    return length;
}

int Train::getOpCount() {
    return countOp;
}
