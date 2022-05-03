/*
** @Author: Sandeep Thapar
**
** Counting Sort - Counting sort is a sorting technique that is based on the keys between specific ranges.
** It performs sorting by counting objects having distinct key values like hashing.
** After that, it performs some arithmetic operations to calculate each object's index position in
** the output sequence. 
**
** For video explanation, please refer to my Youtube channel in the link below:
** Channel: youtube.com/fitcoder
** Sorting Playlist: https://www.youtube.com/playlist?list=PLFj4kIJmwGu08Rq9e-ensRK5bFA2fVUhz
**
** Please subscribe to the channel if you find this helpful
*/

#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int> &vec)
{
    int size = vec.size();
    vector<int> output(size);

    int maxe = *max_element(vec.begin(), vec.end());
    vector<int> count(maxe + 1, 0);

    // Store count of each element
    for (int i=0; i < size; ++i)
    {
        count[vec[i]]++;
    }

    // Store cummulative count
    for (int i=1; i <= maxe; ++i)
    {
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i=0; i < size; ++i)
    {
        output[count[vec[i]] - 1] = vec[i];
        --count[vec[i]];
    }

    // Copy the sorted elements into original array
    for (int i=0; i < size; ++i)
    {
        vec[i] = output[i];
    }
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
    vector<int> vec = {3, 10, 6, 7, 8, 2, 1, 4, 6};
    cout << "Input integer array: ";
    print(vec);

    cout << "Sort using Couting sort: ";
    counting_sort(vec);
    print(vec);
    return 0;
}