// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : opCount(0), first(nullptr) {}

void Train::addCage(bool light) {
  Cage* cage = new Cage;
  cage->light = light;
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
  opCount++;
}

int Train::getLength() {
  if (first == nullptr) {
    return 0;
  } else {
    Cage* current = first;
    int len = 1;
    while (current->next != first) {
      current = current->next;
      len++;
    }
    return len;
  }
}

int Train::getOpCount() {
  return opCount;
}

Train::~Train() {
  if (first != nullptr) {
    Cage* current = first;
    do {
      Cage* next = current->next;
      delete current;
      current = next;
      opCount++;
    } while (current != first);
  }
}
