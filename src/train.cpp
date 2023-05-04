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
    newCage->next = newCage;
    newCage->prev = newCage;
    first = newCage;
  } else {
    Cage *last = first->prev;
    newCage->next = first;
    newCage->prev = last;
    last->next = newCage;
    first->prev = newCage;
  }
}

int Train::getLength() {
  if (first == nullptr)
    return 0;
  int length = 1;
  Cage *current = first->next;
  while (current != first) {
    length++;
    current = current->next;
  }
  return length;
}

int Train::getOpCount() {
  return countOp;
}
