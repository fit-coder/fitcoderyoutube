/*
** @Author: Sandeep Thapar
**
** Bubble Sort - Sorts a list by repeatedly swapping the adjacent elements if they are in the wrong order.
**
** For video explanation, please refer to my Youtube channel in the link below:
** Channel: youtube.com/fitcoder
** Sorting Playlist: https://www.youtube.com/playlist?list=PLFj4kIJmwGu08Rq9e-ensRK5bFA2fVUhz
**
** Please subscribe to the channel if you find this helpful
*/

#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>& vec)
{
    for (int i=0; i < vec.size(); ++i)
    {
        bool isSwapped = false;
        for (int j=0; j < vec.size()-i-1; ++j)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
                isSwapped = true;
            }
        }
        if (isSwapped == false)
            break;
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

    cout << "Sort using Bubble sort: ";
    bubble_sort(vec);
    print(vec);
    return 0;
}