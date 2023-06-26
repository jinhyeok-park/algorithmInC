#include <iostream>

using namespace std;

void    Z(int x, int y, int size);
int N , r, c;
int counter;

int main(void)
{
    cin >> N >> r >> c;
    Z(0, 0, (1 << N));
    return (0);
}

void    Z(int x, int y, int size)
{
    if (r == y && c == x)
    {
        cout << counter;
        return ;
    }
    if (r < y + size && r >= y && c < x + size && x <= c)
    {
        Z(x, y, size / 2);
        Z(x + (size / 2), y, size / 2);
        Z(x, y + (size / 2), size / 2);
        Z(x + (size / 2), y + (size / 2), size / 2);
    }
    else
    {
        counter += size * size;
    }
}


