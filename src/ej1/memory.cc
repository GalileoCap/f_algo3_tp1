#include "memory.h"
#include "svector.h"

template<typename T>
Memory<T>::Memory(const ulong height, const ulong width, const ulong depth) : _height(height), _width(width), _depth(depth), _memory(height) {}

template<typename T>
void Memory<T>::setAt(const ulong height, const ulong width, const ulong depth, T *val) {
  //TODO: Check in range
  SparseVector<SparseVector<T>> *ssv = _memory.getAt(height);
  SparseVector<T> *sv;
  if (ssv != nullptr) sv = ssv->getAt(width);
  else {
    ssv = new SparseVector<SparseVector<T>> (_width);
    sv = new SparseVector<T> (_depth);
    _memory.setAt(height, ssv);
    //ssv->setAt(width, sv);
  }

  //sv->setAt(depth, val);
}

template<typename T>
T* Memory<T>::getAt(const ulong height, const ulong width, const ulong depth) {
  //TODO: Check in range
  SparseVector<SparseVector<T>> *ssv = _memory.getAt(height);
  if (ssv != nullptr) {
    SparseVector<T> *sv = ssv->getAt(width);
    if (sv != nullptr) return sv->getAt(depth);
  }
  return nullptr;
}

template struct Memory<ulong>;
