// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : opCount(0), first(nullptr) {}

int Train::getLength() {
  int len = 0;
  if (first) {
    len = 1;
    Cage* current = first->next;
    while (current != first) {
      len++;
      current = current->next;
      opCount++;
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
    opCount += 2;
  } else {
    item->next = first;
    item->prev = first->prev;
    first->prev->next = item;
    first->prev = item;
    opCount += 4;
  }
  if (getLength() == 1) {
    opCount += 2;
  }
  opCount += 3;
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
