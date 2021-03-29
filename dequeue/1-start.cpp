#include <iostream>
#include <deque>

int main()
{
  std::deque<int> dq;
  dq.push_front(1);
  dq.push_back(2);
  dq.push_back(3);

  for (auto i : dq)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  std::cout << dq.front() << std::endl;
  std::cout << dq.back() << std::endl;

  dq.pop_front();

  for (auto i : dq)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
