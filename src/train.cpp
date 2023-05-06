// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(-1), first(nullptr) {}

void Train::addCage(bool light) {
  if (first == nullptr) {
    first = new Cage{light, nullptr, nullptr};
    first->next = first->prev = first;
  } else {
    Cage* newCage = new Cage{light, first, first->prev};
    first->prev->next = newCage;
    first->prev = newCage;
  }
}

int Train::getLength() {
  if (countOp == -1) {
    countOp = 0;
    if (first != nullptr) {
      Cage* currentCage = first;
      int length = 0;
      bool isLightOn = false;
      do {
        if (!isLightOn) {
          length++;
          currentCage = currentCage->next;
        } else {
          int steps = length - 1;
          Cage* prevCage = currentCage;
          while (steps--) {
            countOp++;
            prevCage = prevCage->prev;
          }
          if (prevCage == first) {
            break;
          } else {
            currentCage = prevCage->next;
            length = 1;
          }
        }
        isLightOn = !isLightOn;
        } while (currentCage != first);
      countOp++;
      return length;
    }
    return 0;
  } else {
    return countOp;
  }
}

int Train::getOpCount() {
  if (countOp == -1) {
    getLength();
  }
  return countOp;
}
