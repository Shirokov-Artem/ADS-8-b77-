// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
  Cage* cage = new Cage{ light };
  if (first == nullptr) {
    first = cage;
    first->next = cage;
    first->prev = cage;
  } else {
    cage->next = first;
    cage->prev = first->prev;
    first->prev->next = cage;
    first->prev = cage;
  }
}

int Train::getLength() {
  int length = 0;
  bool curState = first->light;
  Cage* curCage = first;
  do {
    length++;
    curCage = curCage->next;
    if (curCage->light != curState) {
      curState = !curState;
      length++;
    }
  } while (curCage != first);

  return length;
}

int Train::getOpCount() {
  return countOp;
}
