// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCage(bool light) {
  Cage *cage = new Cage;
  cage->light = light;
  if (first == nullptr) {
    first = cage;
    cage->next = cage;
    cage->prev = cage;
  } else {
    cage->next = first;
    cage->prev = first->prev;
    first->prev->next = cage;
    first->prev = cage;
  }
}

int Train::getLength() {
  int length = 0;
  if (first != nullptr) {
    Cage *current = first;
    do {
      length++;
      current = current->next;
    } while (current != first);
  }
  return length;
}

int Train::getOpCount() {
  return countOp;
}
