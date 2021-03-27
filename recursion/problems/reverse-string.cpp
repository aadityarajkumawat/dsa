#include <iostream>

void reverse(std::string s)
{
  if (s.length() == 0)
    return;

  std::string ros = s.substr(1);
  reverse(ros);

  std::cout << s[0];
}

int main()
{
  reverse("binod");
  return 0;
}
