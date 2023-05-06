// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), opCount(-1) {}

void Train::addCage(bool light) {
  Cage* newCage = new Cage{light, nullptr, nullptr};
  if (first == nullptr) {
    first = newCage;
    first->next = first;
    first->prev = first;
  } else {
    newCage->prev = first->prev;
    first->prev->next = newCage;
    first->prev = newCage;
    newCage->next = first;
  }
}

int Train::getLength() {
  if (length > 0) {
    return length;
  } else {
    int len = 0;
    Cage* currentCage = first;
    bool flag = false;
    while (!flag || currentCage != first) {
      flag = true;
      ++opCount;
      if (!currentCage->light) {
        ++len;
        currentCage = currentCage->next;
      } else { // вагон с фонариком
        Cage* moveCage = currentCage->prev;
        for (int i = 0; i < len - 1; ++i) {
          ++opCount;
          moveCage = moveCage->prev;
        }
        ++opCount;
        if (moveCage == first) {
          break;
        } else {
          currentCage = moveCage->next;
          len = 1;
        }
      }
    }
    length = len;
    return length;
  }
}

int Train::getOpCount() {
  if (opCount > -1) {
    return opCount;
  } else {
    getLength();
    return opCount;
  }
}
