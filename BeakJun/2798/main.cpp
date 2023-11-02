#include <iostream>
#include <vector>

int main(void)
{
    int card;
    int obj;
    int total;
    int before;
    total = 0;
    before = 0;
    std::cin >> card >> obj;
    std::vector<int> cardarr;
    for (int i = 0 ; i < card ; i++)
    {
        int input;
        std::cin >> input;
        cardarr.push_back(input);
    }
    for (int i = 0 ; i < card ; i++)
    {
        total = 0;
        total += cardarr[i];
        for (int j = i + 1 ; j < card ; j++)
        {
            total += cardarr[j];
            for (int k = j + 1 ; k < card ; k++)
            {
                total += cardarr[k];
                if (before <= total && total <= obj)
                    before = total;
                total -= cardarr[k];
            }
            total -= cardarr[j];
        }
        total -= cardarr[i];
    }
    std::cout << before << std::endl;
}