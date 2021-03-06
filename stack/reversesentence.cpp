#include <iostream>
#include <stack>

void reverseSentence(std::string s)
{
    std::stack<std::string> st;

    for (int i = 0; i < s.length(); i++)
    {
        std::string word = "";
        while (s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }
        st.push(word);
    }

    while (!st.empty())
    {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << std::endl;
}

int main()
{
    std::string s = "Hey, how are you doing?";
    reverseSentence(s);
    return 0;
}
