/*
** @Author: Sandeep Thapar
**
** Radix Sort - Radix sort is a sorting technique in which there is digit by digit sorting that is performed
** starting from the LSD to the MSD.
** It uses Counting Sort as a subroutine.
**
** For video explanation, please refer to my Youtube channel in the link below:
** Channel: youtube.com/fitcoder
** Sorting Playlist: https://www.youtube.com/playlist?list=PLFj4kIJmwGu08Rq9e-ensRK5bFA2fVUhz
**
** Please subscribe to the channel if you find this helpful
*/

#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int> &vec, int position)
{
    int size = vec.size();
    vector<int> output(size);
    vector<int> count(10, 0);

    // Store count of each element
    for (int i=0; i < size; ++i)
    {
        int x = (vec[i] / position) % 10;
        ++count[x];
    }

    // Store cummulative count
    for (int i=1; i < 10; ++i)
    {
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i=size-1; i >= 0; --i)
    {
        int x = (vec[i] / position) % 10;
        output[count[x] - 1] = vec[i];
        --count[x];
    }

    // Copy the sorted elements into original array
    for (int i=0; i < size; ++i)
    {
        vec[i] = output[i];
    }
}

void radix_sort(vector<int> &vec)
{
    int maxe = *max_element(vec.begin(), vec.end());

    for (int i=1; maxe/i > 0; i*=10)
    {
        // Sort using counting sort according to digits at i-th place
        counting_sort(vec, i);
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
    vector<int> vec = {150, 10, 45, 65, 90, 504, 1, 4, 35};
    cout << "Input integer array: ";
    print(vec);

    cout << "Sort using Radix sort: ";
    radix_sort(vec);
    print(vec);
    return 0;
}