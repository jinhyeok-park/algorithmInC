#include <iostream>
#include <vector>

using namespace std;

vector<int> dp (12, 0);
vector<int> c;

int main(void)
{
    int n;

    cin >> n;
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4 ; i < 11; i ++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    
    for (int i = 0 ; i < n ; i++)
    {
        int temp;
        cin >> temp;
        c.push_back(temp);
    }
    for(int i = 0 ; i < c.size() ; i++)
    {
        cout << dp[c[i]] << "\n";
    }
}