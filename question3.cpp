#include <bits/stdc++.h>
using namespace std;

class assignment
{

public:
  
    int solve(int arr[], int n)
    {

        int maxrange = arr[0];
        int step = arr[0];
        int i = 1;
        int jump = 1;
        while (i < n)
        {
            maxrange = max(maxrange, i + arr[i]);
            ;
            if (i == n - 1)
            {
                return jump;
            }
            step--;
            if (step == 0)
            {
                step = maxrange - i;
                jump++;
            }
            i++;
        }
        return jump;
    }
};


  int input(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }


int main()
{

    int n;
    cin >> n;
    int arr[n];
    input(arr, n);
    assignment minjump;
    int ans = minjump.solve(arr, n);
    cout << ans;

    return 0;
}
