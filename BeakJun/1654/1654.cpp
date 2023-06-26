#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
    int         k, n;
    int         temp;
    int         maxval;
    unsigned int left, right, mid, sum, result;
    vector<int> arr;

    cin >> k >> n;
    for (int i = 0 ; i < k; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    maxval = *max_element(arr.begin(), arr.end());
    left = 1;
    right = maxval;
    result = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;

        sum = 0;
        for (int i = 0 ; i < k ; i++)
        {
            sum += arr[i] / mid;
        }
        if (sum >= n)
        {
            left = mid + 1;
            result = max(result, mid);
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << result << "\n";
}