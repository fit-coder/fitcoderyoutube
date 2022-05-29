/*
** @Author: Sandeep Thapar
**
** Quick Sort - It is a Divide and Conquer algorithm.
** It picks an element as pivot and partitions the input array around the picked pivot.
**
** For video explanation, please refer to my Youtube channel in the link below:
** Channel: youtube.com/fitcoder
** Sorting Playlist: https://www.youtube.com/playlist?list=PLFj4kIJmwGu08Rq9e-ensRK5bFA2fVUhz
**
** Please subscribe to the channel if you find this helpful
*/

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &vec, int low, int high)
{
    int pivot = vec[high];
    int partitionIndex = low;

    for (int i = low; i < high; ++i)
    {
        if (vec[i] <= pivot)
        {
            swap(vec[i], vec[partitionIndex]);
            ++partitionIndex;
        }
    }
    swap(vec[high], vec[partitionIndex]);
    return partitionIndex;
}

void quick_sort(vector<int> &vec, int low, int high)
{
    if (low >= high)
        return;
    int partitionIndex = partition(vec, low, high);
    quick_sort(vec, low, partitionIndex - 1);
    quick_sort(vec, partitionIndex + 1, high);
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

    cout << "Sort using Quick sort: ";
    quick_sort(vec, 0, vec.size() - 1);
    print(vec);
    return 0;
}