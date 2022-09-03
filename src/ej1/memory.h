#pragma once

#include "svector.h"
#include "utils.h"

template<typename T>
struct Memory { //U: 2D memoization space //TODO: Templateize in size
  Memory(const ulong rows = 0, const ulong cols = 0);

  void setAt(const ulong row, const ulong col, T *val);
  T* getAt(const ulong row, const ulong col);

  ulong _rows, _cols;
  SparseVector<SparseVector<T>> _memory;
};
