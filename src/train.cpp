// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : opCount(0), first(nullptr) {}

Train::~Train() {
  while (first) {
    Cage* item = first;
    first = first->next;
    delete item;
  }
}

void Train::addCage(bool light) {
  Cage* item = new Cage;
  item->light = light;
  if (!first) {
    item->next = item;
    item->prev = item;
  } else {
    item->next = first;
    item->prev = first->prev;
    first->prev->next = item;
    first->prev = item;
  }
  first = item;
  opCount += 4;
}

int Train::getLength() {
  Cage* current = first;
  int count = 0;
  while (current) {
    count++;
    current = current->next;
  }
  return count;
}

int Train::getOpCount() {
  return opCount;
}
