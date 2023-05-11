// Copyright 2023 Uvarkin Ilya

#include <algorithm>
#include "../include/set.h"

void Set::insert(int elem) {
  elems.insert(std::upper_bound(elems.begin(), elems.end(), elem), elem);
}

void Set::erase(int elem) {
  auto it = std::find(elems.begin(), elems.end(), elem);
  if (it != elems.end()){
    elems.erase(it);
  }
}

int Set::count(int elem) {
  auto it = std::find(elems.begin(), elems.end(), elem);
  return it != elems.end() ? 1 : 0;
}
