#include "memory.h"

template<typename T>
Memory<T>::Memory(const ulong rows, const ulong cols) : _rows(rows), _cols(cols), _memory(rows) {}

template<typename T>
void Memory<T>::setAt(const ulong row, const ulong col, T *val) {
  //TODO: Check in range
  SparseVector<T> *sv = _memory.getAt(row);
  if (sv == nullptr) {
    sv = new SparseVector<T> (_cols);
    _memory.setAt(row, sv); //TODO: Skip setAt
  }

  sv->setAt(col, val);
}

template<typename T>
T* Memory<T>::getAt(const ulong row, const ulong col) {
  //TODO: Check in range
  SparseVector<T> *sv = _memory.getAt(row);
  if (sv != nullptr) return sv->getAt(col);
  else return nullptr;
}

template struct Memory<ulong>;
