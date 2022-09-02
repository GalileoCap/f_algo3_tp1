#pragma once

#include "utils.h"

template<typename T>
struct SparseVector { //U: Sparse vector //TODO: Templateize
  SparseVector(const ulong size = 0, T *val = nullptr);

  void setAt(ulong pos, T *val);
  T* getAt(ulong pos);

  struct Stretch {
    Stretch(
      const ulong size = 0,
      T *val = nullptr,
      struct Stretch *prev = nullptr, struct Stretch *next = nullptr
    );

    T *_val;
    ulong _size;
    struct Stretch *_prev, *_next;
  };

  struct Stretch* find(ulong& pos);

  ulong _size;
  struct Stretch *_root;
};
