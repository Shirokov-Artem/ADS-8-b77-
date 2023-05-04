// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCage(bool light) {
  Cage* newCage = new Cage;
  newCage->light = light;
  if (first == nullptr) {
    first = newCage;
    first->next = first;
    first->prev = first;
  } else {
    Cage* lastCage = first->prev;
    lastCage->next = newCage;
    newCage->prev = lastCage;
    newCage->next = first;
    first->prev = newCage;
  }
}

int Train::getLength() {
  int length = 0;
  if (first != nullptr) {
    Cage* currentCage = first;
    do {
      length++;
      currentCage = currentCage->next;
    } while (currentCage != first);
  }
  return length;
}

int Train::getOpCount() {
  return countOp;
}
