#include<iostream>

using namespace std;
int sum_max(int *num_arr, int M_int, int N_int);

int main()
{
    int     i;
    int     j;
    int     k;
    string  N;
    string  M;
    int     N_int;
    int     M_int;
    int     *num_arr;
    string str;
    
    getline(cin, str, '\n');
    i = 0;
    while(str[i])
    {
        if (str[i] == ' ')
        {
            N = str.substr(0,i);
            M = str.substr(i);
            break;
        }
        i++;
    }
    i = 0;
    j = 0;
    k = 0;
    N_int = stoi(N);
    M_int = stoi(M);
    num_arr = (int *)malloc(sizeof(int) * N_int);
    getline(cin, str, '\n');
    while (str[i])
    {
        if (str[i] == ' ')
        {
            num_arr[j] = stoi(str.substr(k, i));
            k = i;
            j++;
        }
        i++;
    }
    num_arr[j] = stoi(str.substr(k, i));
    cout << sum_max(num_arr, M_int, N_int);
    return 0;
}

int sum_max(int *num_arr, int M_int, int N_int)
{
    int max;
    int prev;
    int i;
    int j;
    int k;
    
    i = 0;
    max = 0;
    prev = 0;
    while (i < N_int - 2)
    {
        j = i + 1;
        while (j < N_int)
        {
            k = j + 1;
            while (k < N_int)
            {
                prev = num_arr[i] + num_arr[j] + num_arr[k];
                if ((prev <= M_int) && (prev > max))
                {
                    cout << i << j<< k << "\n";
                    max = prev;
                }
                k++;
            }
            j++;
        }
        i++;
    }
    return (max);
}
