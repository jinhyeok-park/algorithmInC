#include <iostream>
#include <map>

using namespace std;
int N;
map<string, int> choice;

int main(void)
{
    cin >> N;
    for (int i = 0 ; i < N ; i++)
    {
        int M;
        cin >> M;
        for (int j = 0 ; j < M ;j++)
        {
            string kinds;
            string empty;
            int count = 1;
            cin >> empty >> kinds;
            if (choice.find(kinds) == choice.end())
            {
                choice.insert({kinds, count});
            }
            else
            {
                choice[kinds]++;
            }
        }
        int ret = 1;
        for (auto k : choice)
        {
            ret *= k.second;
        }
        for (auto j : choice)
        {
            ret += j.second;
        }
        cout <<  ret << "\n";
        choice.clear();
    }
    
}