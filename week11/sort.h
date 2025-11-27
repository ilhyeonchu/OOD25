#include <iostream>
#include <iterator>

template <typename T>
void Swap(T& elt1, T& elt2) {
  T tmp = elt1;
  elt1 = elt2;
  elt2 = tmp;
}

template <typename T, typename N>
void Sort(typename T::iterator begin, typename T::iterator end) {
  if (begin == end || begin == std::prev(end)) return;

  N comp = N();
  typename T::iterator pivot = begin;
  typename T::iterator left = std::next(begin);
  typename T::iterator i = std::next(begin);

  while (i != end) {
    if (comp(*pivot, *i) == 1) {
      Swap(*i, *left);
      left++;
    }
    i++;
  }
  Swap(*pivot, *(--left));
  Sort<T, N>(begin, left);
  Sort<T, N>(std::next(left), end);
}
