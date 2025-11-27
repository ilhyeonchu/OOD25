#include <iostream>
#include <array>
#include <iterator>

template <typename T>
void Swap(T& elt1, T& elt2) {
  T tmp = elt1;
  elt1 = elt2;
  elt2 = tmp;
}

class IntIncreasingOrder {
 public:
   int operator()(const int& x, const int& y) {
     if (x > y) return 1;
     else return 0;
   }
};

template <typename T, typename N>
void Sort(typename T::iterator begin, typename T::iterator end, int depth = 0) {
  std::string indent(depth * 2, ' ');
  std::cout << indent << "Sort called: [";
  for (auto it = begin; it != end; ++it) {
    std::cout << *it << " ";
  }
  std::cout << "]" << std::endl;
  
  if (begin == std::prev(end) || begin == end) {
    std::cout << indent << "Base case reached" << std::endl;
    return;
  }

  N comp = N();
  typename T::iterator pivot = begin;
  typename T::iterator left = std::next(begin);
  typename T::iterator i = std::next(begin);

  while (i != end) {
    if (comp(*i, *pivot) == 1) {
      Swap(*i, *left);
      left++;
    }
    i++;
  }
  
  std::cout << indent << "Before swap: pivot=" << *pivot << ", left-1=" << *std::prev(left) << std::endl;
  Swap(*pivot, *(left--));
  std::cout << indent << "After swap: left now points to " << *left << std::endl;
  
  std::cout << indent << "Calling Sort(begin, std::prev(left))" << std::endl;
  Sort<T, N>(begin, std::prev(left), depth + 1);
  std::cout << indent << "Calling Sort(std::next(left), end)" << std::endl;
  Sort<T, N>(std::next(left), end, depth + 1);
}

int main() {
  std::array<int, 4> arr = {1, 3, 2, 0};  // 작은 배열로 테스트
  
  Sort<std::array<int, 4>, IntIncreasingOrder>(arr.begin(), arr.end());
  
  std::cout << "\nResult: ";
  for (int n : arr) std::cout << n << " ";
  std::cout << std::endl;
  
  return 0;
}
