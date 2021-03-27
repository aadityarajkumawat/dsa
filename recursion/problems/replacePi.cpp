#include <iostream>

void replacePi(std::string s)
{
  if (s.length() == 0)
    return;

  if (s[0] == 'p' && s[1] == 'i')
  {
    std::cout << "3.14";
    replacePi(s.substr(2));
  }
  else
  {
    std::cout << s[0];
    replacePi(s.substr(1));
  }
}

int main()
{
  std::string s = "pippxxppiixipi";
  replacePi(s);
  return 0;
}
