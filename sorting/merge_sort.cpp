/*
** @Author: Sandeep Thapar
**
** Merge Sort - It is a Divide and Conquer algorithm.
** It divides the input array into two halves, calls itself for the two halves, and then it merges the two
** sorted halves.
**
** For video explanation, please refer to my Youtube channel in the link below:
** Channel: youtube.com/fitcoder
** Sorting Playlist: https://www.youtube.com/playlist?list=PLFj4kIJmwGu08Rq9e-ensRK5bFA2fVUhz
**
** Please subscribe to the channel if you find this helpful
*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& vec, int low, int mid, int high)
{
    vector<int> temp(vec.size(), 0);
    int i = low;
    int j = mid + 1;
    int k = 0;

    //Merge the left and right sub arrays into temp array
    while (i <= mid && j <= high)
    {
        if (vec[i] <= vec[j])
            temp[k++] = vec[i++];
        else
            temp[k++] = vec[j++];
    }

    // Copy the remaining elements if there are any
    while (i <= mid)
        temp[k++] = vec[i++];

    while (j <= high)
        temp[k++] = vec[j++];

    --k;

    // Copy temp array into original array
    while (k >= 0)
    {
        vec[low + k] = temp[k];
        --k;
    }
}

void merge_sort(vector<int> &vec, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low)/2;
    merge_sort(vec, low, mid);
    merge_sort(vec, mid + 1, high);
    merge(vec, low, mid, high);
}

void print(vector<int> &vec)
{
    int i = 0;
    for (; i < vec.size() - 1; ++i)
        cout << vec[i] << ", ";
    cout << vec[i];
    cout << endl;
}

int main()
{
    vector<int> vec = {150, 10, 45, 65, 90, 504, 1, 4, 35};
    cout << "Input integer array: ";
    print(vec);

    cout << "Sort using Merge sort: ";
    merge_sort(vec, 0, vec.size()-1);
    print(vec);
    return 0;
}