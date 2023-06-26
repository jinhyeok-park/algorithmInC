#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool    compare(string a, string b);
int main(void)
{
    int            N;
    string         temp;
    vector<string> arr;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end(), compare);
    cout << arr[0] << '\n';
    for (int i = 1 ; i < N; i++)
    {
        if (arr[i - 1] == arr[i])
            continue;
        cout << arr[i] << '\n';
    }

}

bool    compare(string a, string b)
{
    if (a.length() == b.length())
    {
        for (int i = 0 ; i < a.length() ; i++)
        {
            if (a[i] != b[i])
                return (a[i] < b[i]);
        }

    }
    return (a.length() < b.length());
}

// void    bubble(char **str, int N)
// {
//     char *temp;

//     for (int i = 0 ; i < N - 1; i++)
//     {
//         for (int j = 0 ; j + i < N - 1; j++)
//         {
//             if (strlen(str[j]) > strlen(str[j + 1]))
//             {
//                 temp = str[j];
//                 str[j] = str[j + 1];
//                 str[j + 1] = temp;
//             }
//         }
//     }
// }

// void    check_word(char **str, int N)
// {
//     char *temp;
    
//     for(int i = 0 ; i < N - 1; i++)
//     {
//         for (int j = 0 ; j + i < N - 1; j++)
//         {
//             if (strlen(str[j]) == strlen(str[j+1]))
//             {
//                 if (strcmp(str[j], str[j + 1]) == 0)
//                 {
//                     str[j][0] = '-';
//                 }
//                 else if (strcmp(str[j], str[j + 1]) > 0)
//                 {
//                     temp = str[j];
//                     str[j] = str[j + 1];
//                     str[j + 1] = temp;
//                 }
//             }
//         }
//     }
// }