// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCage(bool light) {
  Cage *newCage = new Cage;
  newCage->light = light;
  newCage->next = nullptr;
  newCage->prev = nullptr;

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
  int length = 0;
  if (first != nullptr) {
    length++;
    Cage *current = first->next;
    while (current != first) {
      length++;
      current = current->next;
    }
  }
  return length;
}

int Train::getOpCount() {
  int opCount = countOp;
  if (first != nullptr) {
    Cage *current = first->next;
    while (current != first) {
      opCount++;
      current = current->next;
    }
  }
  return opCount;
}
