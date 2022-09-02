#pragma once

#include "svector.h"
#include "utils.h"

template<typename T>
struct Memory { //U: 3D memoization space //TODO: Templateize in size
  Memory(const ulong height = 0, const ulong width = 0, const ulong depth = 0);

  void setAt(const ulong height, const ulong width, const ulong depth, T *val);
  T* getAt(const ulong height, const ulong width, const ulong depth);

  ulong _height, _width, _depth;
  SparseVector<SparseVector<SparseVector<T>>> _memory;
};
