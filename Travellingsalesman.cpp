#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    vector<int> cities;
    for (int i = 1; i < n; i++) {
        cities.push_back(i);
    }

    int minCost = INT_MAX;

    do {
        int currentCost = 0;
        int k = 0;

        for (int i = 0; i < cities.size(); i++) {
            currentCost += cost[k][cities[i]];
            k = cities[i];
        }

        currentCost += cost[k][0];

        minCost = min(minCost, currentCost);

    } while (next_permutation(cities.begin(), cities.end()));

    cout << "Minimum travelling cost = " << minCost;

    return 0;
}