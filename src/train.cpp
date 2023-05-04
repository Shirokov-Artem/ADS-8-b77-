// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCage(bool light) {
  countOp++;
  Cage *newCage = new Cage;
  newCage->light = light;
  if (first == nullptr) {
    first = newCage;
    newCage->next = first;
    newCage->prev = first;
  } else if (first->next == first) {
    Cage *last = first;
    last->next = newCage;
    newCage->prev = last;
    newCage->next = last;
    first->prev = newCage;
  } else {
    Cage *last = first->prev;
    last->next = newCage;
    newCage->prev = last;
    newCage->next = first;
    first->prev = newCage;
  }
}

int Train::getLength() {
  if (first == nullptr) {
    return 0;
  }
  int length = 0;
  Cage *current = first;
  do {
    length++;
    current = current->next;
  } while (current != first);
  return length;
}

int Train::getOpCount() {
  return countOp;
}
