#include <iostream>
#include <string.h>

using namespace std;

int N, M;
int subin = 100;
string ten = "0123456789";

int main(void)
{
    string num;

    cin >> N >> M;
    if (N == subin)
    {
        cout << "0";
        return (0);
    }
    num =  to_string(N);
    for (int i = 0 ; i < M ; i++)
    {
        for (int j = 0 ; j < 10 ; j++)
        {
            string temp;
            cin >> temp;
            if (ten[j] == temp);
        }
    }
}