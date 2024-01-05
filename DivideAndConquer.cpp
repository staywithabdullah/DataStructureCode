#include <bits/stdc++.h>
using namespace std;
struct Result
{
    int sum;
    int leftIndex;
    int rightIndex;
};
Result crossingSum(int arr[], int left, int mid, int right)
{
    int sum = arr[mid];
    int LS = arr[mid];
    int indexLS = mid;
    for (int i = mid - 1; i >= left; i--)
    {
        sum = sum + arr[i];
        if (sum > LS)
        {
            LS = sum;
            indexLS = i;
        }
    }
    sum = arr[mid + 1];
    int RS = arr[mid + 1];
    int indexRS = mid + 1;
    for (int i = mid + 2; i <= right; i++)
    {
        sum = sum + arr[i];
        if (sum > RS)
        {
            RS = sum;
            indexRS = i;
        }
    }
    Result crossing;
    crossing.sum = LS + RS;
    crossing.leftIndex = indexLS;
    crossing.rightIndex = indexRS;
    return crossing;
}
Result maximumSumSubarray(int arr[], int left, int right)
{
    if (left == right)
    {
        Result result;
        result.sum = arr[left];
        result.leftIndex = left;
        result.rightIndex = right;
        return result;
    }
    else
    {
        int mid = (left + right) / 2;
        Result leftSideMaximum = maximumSumSubarray(arr, left, mid);
        Result rightSideMaximum = maximumSumSubarray(arr, mid + 1,
                                                     right);
        Result crossingMaximum = crossingSum(arr, left, mid, right);
        if (leftSideMaximum.sum >= rightSideMaximum.sum &&
            leftSideMaximum.sum >= crossingMaximum.sum)
            return leftSideMaximum;
        else if (rightSideMaximum.sum >= leftSideMaximum.sum &&
                 rightSideMaximum.sum >= crossingMaximum.sum)
            return rightSideMaximum;
        else
            return crossingMaximum;
    }
}
int main()
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    Result result = maximumSumSubarray(arr, 0, N - 1);
    cout << "The most effective training period is day " << result.leftIndex + 1
         << " to day " << result.rightIndex + 1 << "." << endl;
    cout << "Total improvement score: " << result.sum << endl;
    return 0;
}
