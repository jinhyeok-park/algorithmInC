void    backtracking(int M, int N, int M_i, int N_i, int *arr, int arr_size);
int main() {
    // Write C++ code here
    string str;
    int N;
    int M;
    int     i;
    int arr[8];

    i = 0;
    getline(cin, str, '\n');
    
    while (str[i])
    {
       if (str[i] == ' ')
        {
            M = stoi(str.substr(0, i));
            break;
        }
        i++;
    }
    N = stoi(str.substr(i));
    backtracking(M, N, 1, 1, arr, -1);
    
    return 0;
}

int check_self(int *arr,int val, int index)
{
    int i;
    
    i = 0;
    while (i < index)
    {
        if (arr[i] == val)
            return (0);
        i++;
    }
    return (1);
}

int ispromising(int *arr, int arr_size)
{
    int i;
    
    i = 0;
    if (arr_size == -1)
        return (1);
    while (i < arr_size + 1)
    {
        if (!check_self(arr, arr[i], i))
            return (0);
        i++;
    }
    return (1);
}

void    backtracking(int M, int N, int M_i, int N_i, int *arr, int arr_size)
{
    int i;
    int temp;
    
    if (ispromising(arr, arr_size))
    {
        // cout << arr_size << "arr size\n";
        // cout << N << "N size\n";
        if (arr_size == N - 1)
        {
            i = 0;
            while (i < arr_size + 1)
            {
                cout << arr[i];
                if (i != arr_size)
                    cout << ' ';
                i++;
            }
            cout << "\n";
        }
        else
        {
            temp = 1;
            while (temp <= M)
            {
                arr[arr_size + 1] = temp;
                backtracking(M, N, M_i, N_i, arr, arr_size + 1);
                temp++;
            }
        }
    }
}

