/*
** @Author: Sandeep Thapar
**
** Insertion Sort - A simple sorting algorithm that builds the final sorted list one item at a time.
** The list is virtually split into a sorted and an unsorted part.
** Values from the unsorted part are picked and placed at the correct position in the sorted part.
**
** For video explanation, please refer to my Youtube channel in the link below:
** Channel: youtube.com/fitcoder
** Sorting Playlist: https://www.youtube.com/playlist?list=PLFj4kIJmwGu08Rq9e-ensRK5bFA2fVUhz
**
** Please subscribe to the channel if you find this helpful
*/

#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>& vec)
{
    int j, key;
    for (int i=1; i < vec.size(); ++i)
    {
        key = vec[i];
        j = i-1;
        while (j >= 0 && vec[j] > key)
        {
            vec[j+1] = vec[j];
            j = j-1;
        }
        vec[j+1] = key;
    }
}

void print(vector<int>& vec)
{
    int i = 0;
    for (;i < vec.size()-1; ++i)
        cout << vec[i] << ", ";
    cout << vec[i];
    cout << endl;
}

int main() {
    vector<int> vec = {3, 15, 6, 11, 12, 2, 1, 4, 6};
    cout << "Input integer array: ";
    print(vec);

    cout << "Sort using Insertion sort: ";
    insertion_sort(vec);
    print(vec);
    return 0;
}