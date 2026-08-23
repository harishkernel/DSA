/*
 * File: HouseRobberI.cpp
 * Author: Harish Muthaiyan
 * Created: Sunday, August 16th 2026, 5:11:19 pm
 */

#include <bits/stdc++.h>
using namespace std;

int maxRob(int idx, vector<int>& arr) {
    if(idx < 0) return 0;
    if(idx == 0 || idx == 1) return arr[idx];

    int pick = arr[idx] + maxRob(idx-2, arr);
    int notPick = maxRob(idx-1, arr);
    return max(pick, notPick);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 5;
    vector<int> arr = {2, 7, 9, 3, 1};


    cout << maxRob(n-1, arr) << '\n';
	return 0;
}
