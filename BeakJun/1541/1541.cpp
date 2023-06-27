#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> digit;
vector<char> oper;

int result;
bool is_minus = false;

int main(void)
{
    string s;
    string num;

    cin >> s;
    for (int i = 0 ; i <= s.length() ; i++)
    {
        if (s[i] == '-' || s[i] == '+' || !s[i])
        {
            if (is_minus)
                result -= stoi(num);
            else
                result += stoi(num);
            num = "";
        }
        else
            num += s[i];
        if (s[i] == '-')
            is_minus = true;
    }
    cout << result;
}