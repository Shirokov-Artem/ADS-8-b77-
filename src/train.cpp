// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCage(bool light) {
    if (first == nullptr) {
        first = new Cage{light, nullptr, nullptr};
        first->next = first;
        first->prev = first;
    } else {
        Cage* lastCage = first->prev;
        lastCage->next = new Cage{light, first, lastCage};
        first->prev = lastCage->next;
    }
    countOp++;
}

int Train::getLength() {
  if (first == nullptr) {
      return 0;
  }
  Cage* currentCage = first;
  int len = 0;
  do {
      len++;
      currentCage = currentCage->next;
  } while (currentCage != first);
  return len;
}

int Train::getOpCount() {
  if (first == nullptr) {
      return 0;
  }
  int nSwitch = 0;
  Cage* currentCage = first->next;
  do {
      if (currentCage->light != currentCage->prev->light)
          nSwitch++;
      currentCage = currentCage->next;
  } while (currentCage != first->next);
  return getLength() + nSwitch;
}
