// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), opCount(4) {}

int Train::getLength() {
  int len = 0;
  if (first) {
    len = 1;
    Cage* current = first->next;
    while (current != first) {
      len++;
      current = current->next;
      opCount += 1;
    }
  }
  opCount++;
  return len;
}

int Train::getOpCount() {
  return opCount;
}

void Train::addCage(bool light) {
  Cage* item = new Cage;
  item->light = light;
  if (!first) {
    item->next = item;
    item->prev = item;
    first = item;
    opCount += 5;
  } else {
    item->prev = first->prev;
    item->next = first;
    first->prev->next = item;
    first->prev = item;
    opCount += 6;
  }
  opCount++;
}

Train::~Train() {
  if (first) {
    Cage* current = first;
    while (current->next != first) {
      Cage* tmp = current;
      current = current->next;
      delete tmp;
      opCount++;
    }
    delete current;
    opCount++;
  }
}
