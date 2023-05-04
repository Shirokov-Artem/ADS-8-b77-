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
    newCage->next = first;
    newCage->prev = first;
  } else {
    Cage *last = first->prev;
    last->next = newCage;
    newCage->prev = last;
    newCage->next = first;
    first->prev = newCage;
  }
}

int Train::getLength() {
  Cage *current = first;
  int length = 0;
  do {
    length++;
    current = current->next;
  } while (current != first);

  return length;
}

int Train::getOpCount() {
  Cage *current = first;
  countOp = 0;
  do {
    if (current->light == true) {
      current->light = false;
      countOp += 2;
    }
    current = current->next;
    countOp += 2;
  } while (current != first);
  return countOp;
}
