#include <iostream>

//white
std::string Wblock[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

std::string Bblock[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

std::string inputMap[1000];
int minimum = 9999999;

int W_checker(int x, int y);
int B_checker(int x, int y);

int main(void)
{
    int low , col;
    std::cin >> low >> col;
    for (int i = 0 ; i < low ; i++)
    {
        std::string temp;
        std::cin >> temp;
        inputMap[i] = temp;
    }
    for (int i = 0 ; i < std::abs(low - 7) ; i++)
    {
        for (int j = 0 ; j < std::abs(col - 7) ; j++)
        {
            int min;
            min = std::min(W_checker(i,j), B_checker(i, j));
            if (minimum > min)
            {
                minimum = min;
            }
        }
    }
    std::cout << minimum << std::endl;
}

int W_checker(int x, int y){

    int Wcount = 0;
    for (int i = 0 ; i < 8 ; i++)
    {
        for (int j = 0 ; j < 8 ; j++)
        {
            if (inputMap[x][y] != '\0' && Wblock[i][j] != inputMap[x][y])
            {
                Wcount++;
            }
            y++;
        }
        y = 0;
        x++;
    }
    return Wcount;
}

int B_checker(int x, int y){

    int Bcount = 0;
    for (int i = 0 ; i < 8 ; i++)
    {
        for (int j = 0 ; j < 8 ; j++)
        {
            if (inputMap[x][y] != '\0' && Bblock[i][j] != inputMap[x][y])
                Bcount++;
            y++;
        }
        y = 0;
        x++;
    }
    return Bcount;
}





