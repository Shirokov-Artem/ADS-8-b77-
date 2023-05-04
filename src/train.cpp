// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
  Cage *cage = new Cage{light, nullptr, nullptr};
  if (first == nullptr) {
    first = cage;
    cage->next = first;
    cage->prev = first;
  } else {
    Cage *last = first->prev;
    last->next = cage;
    cage->prev = last;
    cage->next = first;
    first->prev = cage;
  }
}

int Train::getLength() {
  int length = 0;
  if (first == nullptr) {
    return length;
  }
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
