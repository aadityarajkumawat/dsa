#include <iostream>
#include <stack>

void insertAtBottom(std::stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }
    int topele = st.top();
    st.pop();
    insertAtBottom(st, ele);

    st.push(topele);
}

void reverse(std::stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int ele = st.top();
    st.pop();
    reverse(st);

    insertAtBottom(st, ele);
}

int main()
{
    std::stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverse(st);

    while(!st.empty()) {
        std::cout << st.top() << std::endl;
        st.pop();
    }
    return 0;
}