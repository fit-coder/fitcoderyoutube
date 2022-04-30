/*
** @Author: Sandeep Thapar
**
** Selection Sort - Sorts an array by repeatedly finding the minimum element (considering ascending order)
** from unsorted part and putting it at the beginning.
**
** For video explanation, please refer to my Youtube channel in the link below:
** Channel: youtube.com/fitcoder
** Sorting Playlist: https://www.youtube.com/playlist?list=PLFj4kIJmwGu08Rq9e-ensRK5bFA2fVUhz
**
** Please subscribe to the channel if you find this helpful
*/

#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>& vec)
{
    int min_idx;
    for (int i=0; i < vec.size(); ++i)
    { 
        min_idx = i;
        for (int j = i+1; j < vec.size(); ++j)
        {
            if (vec[j] < vec[min_idx])
                min_idx = j;
        }
        swap(vec[min_idx], vec[i]);
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

    cout << "Sort using Selection sort: ";
    selection_sort(vec);
    print(vec);
    return 0;
}