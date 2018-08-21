#include <iostream>
#include <vector>
#include "invokeCounter.h"
using namespace std;

int main() {
    InvokeCounter<void, vector<int>&, int, int> mergeSort
            = [&](vector<int>& v, int start, int end) -> void {
                int length = end - start; // exclude end
                if (length < 2) {
                    return;
                }
                int mid = (end + start) / 2;

                // recursive call
                mergeSort(v, start, mid);
                mergeSort(v, mid, end);


                // merge
                vector<int> merged;

                int left = start;
                int right = mid;

                while(left < mid && right < end) {
                    merged.push_back(v[left] < v[right] ? v[left++] : v[right++]);
                }

                while (left < mid) {
                    merged.push_back(v[left++]);
                }

                while (right < end) {
                    merged.push_back(v[right++]);
                }

                for (int i = 0; i < length; i++) {
                    v[start + i] = merged[i];
                }
            };

    vector<int> v = {2, 4, 5, 7, 8, 3, 1, 6};

    mergeSort(v, 0, v.size());

    for (int i : v) {
        cout << i << ", ";
    }
    cout << endl;

    cout << "Count : " << mergeSort.getCount() << endl;

    return 0;
}