// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <utility>

// int result;
// int input[11][11];
// int visit[11] = {0, };
// int N;
// int ret = 9999999;

// void    backtracking(int startPoint, int y, int visit_count, int sum);

// int main(void)
// {
//     std::cin >> N;
//     for (int i = 0 ; i < N ; i++)
//     {
//         for (int j = 0 ; j < N ; j++)
//         {
//             int temp;
//             std::cin >> temp;
//             input[i][j] = temp;
//         }
//     }
//     for (int i = 0 ; i < N ; i++)
//     {
//         visit[i] = 1;
//         backtracking(i, i, 0, 0);
//     }
//     std::cout << ret << std::endl;
// }

// void    backtracking(int startPoint, int y, int visit_count, int sum){

//     if (visit_count == N -1 && startPoint == y)
//     {
//         if (ret > sum)
//             ret = sum;
//         return ;
//     }
//     for (int i = 0 ; i < N ; i ++)
//     {
//         if (input[startPoint][i] == 0)
//             continue;
//         if (input[startPoint][i] > 0 && !visit[i])
//         {
//             visit[i] = 1;
//             backtracking(startPoint, i, visit_count + 1, sum += input[startPoint][i]);
//             visit[i] = 0;
//         }
//     }
// }



// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <utility>

// int input[11][11];
// int visit[11] = {0, };
// int N;
// int ret = 999999;

// void backtracking(int startPoint, int y, int visit_count, int sum);

// int main(void)
// {
//     std::cin >> N;
//     for (int i = 0 ; i < N ; i++)
//     {
//         for (int j = 0 ; j < N ; j++)
//         {
//             std::cin >> input[i][j];
//         }
//     }
//     for (int i = 0 ; i < N ; i++)
//     {
//         visit[i] = 1;
//         backtracking(i, i, 1, 0);
//         visit[i] = 0;
//     }
//     std::cout << ret << std::endl;
//     return 0;
// }

// void backtracking(int startPoint, int y, int visit_count, int sum)
// {
//     if (visit_count == N)
//     {
//         if (input[y][startPoint] != 0) // come bact start. 
//         {
//             ret = std::min(ret, sum + input[y][startPoint]);
//         }
//         return;
//     }

//     for (int i = 0 ; i < N ; i++)
//     {
//         if (input[y][i] != 0 && !visit[i])
//         {
//             visit[i] = 1;
//             backtracking(startPoint, i, visit_count + 1, sum + input[y][i]);
//             visit[i] = 0;
//         }
//     }
// }

#include <iostream>
int    map[11][11];
bool    visit[11] = {false , };
int     N = 0;
int     ret = 9999999;

void    backtrack(int start, int y, int sum , int visit_count);

int main(void)
{
    std::cin >> N;
    for (int i = 0 ; i < N ; i ++)
    {
        for (int j = 0 ; j < N ; j ++)
        {
            int input;
            std::cin >> input;
            map[i][j] = input;
        }
    }
    for (int i = 0 ; i < N ; i++)
    {
        visit[i] = true;
        backtrack(i, i, 0 , 0);
        visit[i] = false;
    }
    std::cout << ret << std::endl;
}

void    backtrack(int start, int y, int sum , int visit_count)
{
    if (N - 1 == visit_count)
    {
        if (map[y][start] != 0)
        {
            ret = std::min(ret, sum += map[y][start]);
        }
        return ;
    }
    for (int i = 0 ; i < N ; i++)
    {
        if (!visit[i] && map[y][i] > 0)
        {
            visit[i] = true;
            backtrack(start, i, sum + map[y][i], visit_count + 1);
            visit[i] = false;
        }
    }
}