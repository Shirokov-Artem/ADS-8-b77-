// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
  Cage* item = new Cage;
  item->light = light;
  item->next = first;
  item->prev = first ? first->prev : item;
  if (first) {
    item->prev->next = item;
    first->prev = item;
  } else {
    first = item;
  }
  opCount += 4;
}

int Train::getLength() {
  Cage* temp = first;
  temp->light = true;
  int count = 1;
  int opCount = 0;
  while (true) {
    temp = temp->next;
    if (temp->light == false) {
      count++;
      opCount++;
    } else {
      temp->light = false;
      opCount++;

      Cage* temp2 = temp->prev;
      int count2 = 1;
      while (true) {
        temp2->light = true;
        opCount++;
        if (temp2 == first) {
          break;
        }
        temp2 = temp2->prev;
        count2++;
      }
      count = count2;

      if (temp->light == false) {
        return count;
      } else {
        count = 1;
      }
    }
  }
}

int Train::getOpCount() {
  int count = 0;
  getLength();
  count = countOp;
  countOp = 0;
  return count;
}
