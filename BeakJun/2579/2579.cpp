#include <iostream>
#include <vector>

using namespace std;

int steps;
int score;
int steps_info[301];
int max_score;
vector<int> v;

int main(void)
{
    cin >> steps;
    for (int i = 1 ; i <= steps ; i++)
    {
        int temp;
        cin >> temp;
        steps_info[i] = temp;
    }
    v.push_back(0);
    v.push_back(steps_info[1]);
    v.push_back(steps_info[1] + steps_info[2]);
    v.push_back(max(steps_info[1] + steps_info[3], steps_info[2] + steps_info[3]));
    for (int i = 4 ; i <= steps; i++)
    {
        v.push_back(max(v[i - 2] + steps_info[i],\
        v[i - 3] + steps_info[i - 1] + steps_info[i]));
    }
    cout << v[steps];
}