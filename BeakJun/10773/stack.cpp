#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string str;
    int     k;
    int     num;
    int     result;
    int     stack_size;
    stack<int> stack_;
    
    result = 0;
    getline(cin, str, '\n');
    k = stoi(str);
    while (k--)
    {
        getline(cin, str, '\n');
        num = stoi(str);
        if (num == 0)
            stack_.pop();
        else
            stack_.push(num);
    }
    stack_size = stack_.size();
    while (stack_size--)
    {
        result += stack_.top();
        stack_.pop();
    }
    cout << result;
    
    return 0;
}