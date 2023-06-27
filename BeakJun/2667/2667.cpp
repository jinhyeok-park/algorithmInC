#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
    int            N;
    string         temp;
    vector<int>    visit;
    vector<string> arr;


    cin >> N;
    for (int i = 0; i < N ; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }

}

void    dfs(vector<string> arr, int N, vector<int> visit)
{
    for (int i = 0 ; i < N; i++)
    {
        for (int j = 0 ; j < arr[i].length() ; j++)
        {
            if (arr[i][j] == 1 && visit[])
        }
    }


}