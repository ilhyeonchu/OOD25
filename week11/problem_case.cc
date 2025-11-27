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
  
  if (begin == std::prev(end) || begin == end) {
    return;
  }

  N comp = N();
  typename T::iterator pivot = begin;
  typename T::iterator left = std::next(begin);
  typename T::iterator i = std::next(begin);

  std::cout << indent << "Processing range: ";
  for (auto it = begin; it != end; ++it) std::cout << *it << " ";
  std::cout << std::endl;
  
  // 모든 원소가 pivot보다 크거나 같으면 left는 그대로 std::next(begin)
  while (i != end) {
    if (comp(*i, *pivot) == 1) {
      Swap(*i, *left);
      left++;
    }
    i++;
  }
  
  std::cout << indent << "left is at: " << *left << ", pivot is: " << *pivot << std::endl;
  std::cout << indent << "left == std::next(begin)? " << (left == std::next(begin) ? "YES" : "NO") << std::endl;
  
  // left가 std::next(begin)인 상태에서 left--를 하면
  // 실제로는 begin과 swap하고, left는 begin을 가리키게 됨
  Swap(*pivot, *(left--));
  std::cout << indent << "After swap, left points to position " << (left - begin) << std::endl;
  
  // 이제 std::prev(left)를 호출하면?
  if (left == begin) {
    std::cout << indent << "WARNING: left == begin, std::prev(left) will be OUT OF BOUNDS!" << std::endl;
    std::cout << indent << "Trying to access std::prev(left)..." << std::endl;
  }
  
  Sort<T, N>(begin, std::prev(left), depth + 1);
  Sort<T, N>(std::next(left), end, depth + 1);
}

int main() {
  // pivot보다 작은 원소가 하나도 없는 경우!
  std::array<int, 4> arr = {0, 1, 2, 3};
  
  Sort<std::array<int, 4>, IntIncreasingOrder>(arr.begin(), arr.end());
  
  return 0;
}
