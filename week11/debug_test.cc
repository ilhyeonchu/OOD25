#include <iostream>
#include <array>

int main() {
  std::array<int, 8> arr = {1, 3, 5, 2, 6, 8, 4, 0};
  
  auto begin = arr.begin();
  auto end = arr.end();
  auto left = std::next(begin);
  
  std::cout << "Before left--: left points to " << *left << std::endl;
  auto old_left = left--;
  std::cout << "After left--: left points to " << *left << std::endl;
  std::cout << "old_left (used in expression) points to " << *old_left << std::endl;
  
  // 이제 문제 시나리오를 재현
  left = begin;  // left가 begin과 같아지는 경우
  std::cout << "\nWhen left == begin:" << std::endl;
  std::cout << "left points to " << *left << std::endl;
  
  auto result = left--;  // left--를 하면
  std::cout << "After left--, left would point to: ";
  if (left < begin) {
    std::cout << "OUT OF BOUNDS (before begin)!" << std::endl;
  } else {
    std::cout << *left << std::endl;
  }
  
  std::cout << "\nWhat about std::prev(begin)?" << std::endl;
  auto prev_begin = std::prev(begin);
  std::cout << "std::prev(begin) is out of bounds, points to: ";
  std::cout << "address " << &(*prev_begin) << " (invalid!)" << std::endl;
  
  return 0;
}
