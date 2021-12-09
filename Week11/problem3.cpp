#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSubsetSum(vector<int> arr, int n, int sum)
{
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;
 
    if (arr[n - 1] > sum)
        return isSubsetSum(arr, n - 1, sum);

    return isSubsetSum(arr, n - 1, sum)
           || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

int main() {

    int n, sum = 0;
    vector<int> arr;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        arr.push_back(t);
        sum += t;
    }

    if (sum & 1) {
        cout << "No" << endl;
    } else {
        int target = sum / 2;
        if(isSubsetSum(arr, n, target))  cout << "Yes" << endl;
        else cout << "No" << endl;
    }


    return 0;
}