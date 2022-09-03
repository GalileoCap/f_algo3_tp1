#include "svector.h"

template<typename T>
SparseVector<T>::SparseVector(const ulong size, T *val) : _size(size), _root(new Stretch(size, val)) {}

template<typename T>
SparseVector<T>::Stretch::Stretch(const ulong size, T *val, struct Stretch *prev, struct Stretch *next) : _size(size), _val(val), _prev(prev), _next(next) {}

template<typename T>
void SparseVector<T>::setAt(ulong pos, T *val) {
  //TODO: inRange
  struct Stretch *s0 = find(pos),
                 *s1, *s2, *tmp = s0;
  s0 = new Stretch(pos, tmp->_val, tmp->_prev, /* s1 */ nullptr);
  s1 = new Stretch(1, val, s0, /* s2 */ nullptr);
  s2 = new Stretch(tmp->_size - (pos + 1), tmp->_val, /* s1 */ nullptr, tmp->_next);
  s0->_next = s1; s1->_next = s2; s2->_prev = s1;
  if (tmp->_prev) tmp->_prev->_next = s0;
  if (tmp->_next) tmp->_next->_prev = s2;

  if (_root == tmp) _root = s0;
  //TODO: Merge and delete
}

template<typename T>
T* SparseVector<T>::getAt(ulong pos) {
  //TODO: inRange
  return find(pos)->_val;
}

template<typename T>
 struct SparseVector<T>::Stretch* SparseVector<T>::find(ulong& pos) {
  //TODO: inRange
   struct Stretch *s = _root;
   while (pos >= s->_size) {
     pos -= s->_size;
     s = s->_next;
   }
   return s;
 }

template struct SparseVector<ulong>; //TODO: Fix needing to declare templates
template struct SparseVector<SparseVector<ulong>>;
