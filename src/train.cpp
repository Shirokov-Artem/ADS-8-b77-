// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() {
  first = nullptr;
  countOp = 0;
}
void Train::addCage(bool light){
  Cage* cg = new Cage;
  if (first == nullptr) {
    first = cg;
    first->next = cg;
    first->prev = cg;
    first->light = light;
  } else {
    cg->next = first;
    cg->prev = first->prev;
    cg->light = light;
    first->prev = cg;
    cg->prev->next = cg;
  }
}
int Train::getLength() {
  Cage* tmp = first;
  tmp->light = true;
  int len = 1;
  int tr_len;
  while(tmp) {
    tmp = tmp->next;
    if (tmp->light == false) {
      len++;
      countOp++;
      tr_len = len;
    }
    if (tmp->light == true) {
      tmp->light = false;
      while (tr_len > 0){
        tmp = tmp->prev;
        tr_len--;
      }
      countOp += len + 1;
      if (!tmp->light)
        return  len;
      len = 1;
    }
  }
  return tr_len;
}
int Train::getOpCount() {
  if (countOp == -1)
    countOp = getLength();
  return countOp;
}
