#include <iostream>

int N;
std::string dp[10001] = {"-1" ,};

std::string stringAdd(std::string a, std::string b)
{
    std::string ret;
    int len = std::max(a.length(), b.length());
    int minlen = std::min(a.length(), b.length());
    int temp = 0;
    int pre = 0;
    for (int i = 0 ; i < len ; i ++)
    {
        if (i < minlen)
        {
            // temp = std::(a[i]) + std::stoi(b[i]) + pre;
            temp = static_cast<int>(a[i]) - '0' + static_cast<int>(b[i]) - '0' + pre;
            pre = 0;
            if (temp > 9)
            {
                pre = 1;
                temp %= 10;
                ret += std::to_string(temp);
            }
            else if (temp < 10)
            {
                ret += std::to_string(temp);
            }
        }
        // else if ( i > minlen)
    }
    return ret;
}

int main(void)
{
    std::cin >> N;
    for (int i = 0 ; i <= N ; i ++)
    {
        if (i == 0)
            dp[i] = "0";
        else if (i == 1)
            dp[i] = "1";
        else if (i > 1)
        {
            dp[i] = stringAdd(dp[i - 1], dp[i - 2]);
        }
    }
    std::cout << dp[N] << std::endl;
}