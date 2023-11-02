#include <iostream>

int T;
int dp[15][15] = {-1, };
int k, n;

int main(void)
{
    std::cin >> T;

    for (int i = 0 ; i < 15 ; i++)
    {
        for (int j = 1 ; j < 15 ; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (i > 0 && j == 1)
                dp[i][j] = dp[i - 1][j];
            else if (i > 0 && j > 1)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    for (int i = 0 ; i < T ; i++)
    {
        std::cin >> k;
        std::cin >> n;
        std::cout << dp[k][n] <<std::endl;
    }

    // for (int i = 0 ; i < 15 ; i ++)
    // {
    //     for (int j = 0 ; j < 15 ; j ++)
    //     {
    //         std::cout << dp[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
}