// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCage(bool light) {
  Cage *newCage = new Cage;
  newCage->light = light;
  if (first == nullptr) {
    first = newCage;
    newCage->next = newCage;
    newCage->prev = newCage;
  } else {
    Cage *lastCage = first->prev;
    lastCage->next = newCage;
    newCage->prev = lastCage;
    newCage->next = first;
    first->prev = newCage;
  }
}

int Train::getLength() {
  if (first == nullptr) {
    return 0;
  }
  Cage *currentCage = first;
  int length = 1;
  while (currentCage->next != first) {
    length++;
    currentCage = currentCage->next;
  }
  return length;
}

int Train::getOpCount() {
  return countOp;
}
