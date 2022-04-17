/*
** @Author: Sandeep Thapar
**
** A sorting algorithm is used to arrange elements of an array/list in a specific order.
** Many types of sorting algorithms are there.
** C++ STL provides a similar function sort that sorts a vector or array (items with random access). 
** 
** It generally takes two parameters, the first one being the point of the array/vector from where the
** sorting needs to begin and the second parameter being the length up to which we want the array/vector
** to get sorted. The third parameter is optional and can be used to provide your own comparator function.
** By default, the sort() function sorts the elements in ascending order.
**
** For video explanation, please refer to my Youtube channel in the link below:
** Channel: youtube.com/fitcoder
** Sorting Playlist: https://www.youtube.com/playlist?list=PLFj4kIJmwGu08Rq9e-ensRK5bFA2fVUhz
**
** Please subscribe to the channel if you find this helpful
*/

#include <bits/stdc++.h>
using namespace std;

// Custom comparator
struct comparator {
    // Sort by second element of pair. If second element is same, sort by first element.
    bool operator() (pair<char, int>& p1, pair<char, int>& p2) {
        if (p1.second == p2.second)
            return p1.first < p2.first;
        return p1.second < p2.second;
    }
};

int main() {
    cout << "Input integer array: ";
    vector<int> v = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    for (int i=0; i < v.size(); i++)
        cout << v[i] << ", ";
    cout << endl;

    cout << "Sort in increasing order: ";
    std::sort(v.begin(), v.end());
    for (int i=0; i < v.size(); i++)
        cout << v[i] << ", ";
    cout << endl;

    cout << "Sort in decreasing order: ";
    std::sort(v.begin(), v.end(), greater<int>());
    for (int i=0; i < v.size(); i++)
        cout << v[i] << ", ";
    cout << endl;
    cout << endl;

    cout << "Input pairs array: ";
    vector<pair<char, int>> p = {{'D', 90}, {'A', 95}, {'G', 90}, {'E', 95}, {'C', 90}};
    for (int i=0; i < p.size(); i++)
        cout << p[i].first << ":" << p[i].second << ", ";
    cout << endl;
    cout << "Sort pairs using custom comparator: ";
    std::sort(p.begin(), p.end(), comparator());
    for (int i=0; i < p.size(); i++)
        cout << p[i].first << ":" << p[i].second << ", ";
    
    return 0;
}