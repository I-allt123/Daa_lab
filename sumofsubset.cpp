#include <iostream>
using namespace std;

int arr[20], subset[20], n, target;

void sumOfSubsets(int sum, int k, int r) {
    if (sum == target) {
        cout << "Subset: ";
        for (int i = 0; i < k; i++) {
            cout << subset[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = k; i < n; i++) {
        if (sum + arr[i] <= target) {
            subset[k] = arr[i];
            sumOfSubsets(sum + arr[i], i + 1, r - arr[i]);
        }
    }
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    sumOfSubsets(0, 0, 0);

    return 0;
}