/* Author: Utkarsh Ashok Pathrabe
*  Algorithm: Getting the 0-1 Knapsack value using Tabulation (Bottom Up)
*/

/* Problem Statement: Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer
*  arrays val[0...n-1] and wt[0...n-1] which represent values and weights associated with n items respectively, also given an integer W which represents knapsack capacity, find out the
*  maximum value of this subset which is smaller than or equal to W. You cannot break an item, either pick the complete item, or don't pick it(0-1 property).
*/

/* Time Complexity: O(nW) where n is the number of items and W is the capacity of knapsack. */

#include <bits/stdc++.h>

using namespace std;

int KnapSack (int W, vector<int> &val, vector<int> &wt, int n) {
	int KS[n + 1][W + 1];
	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= W; w++) {
			if (i == 0 || w == 0) {
				KS[i][w] = 0;
			} else if (wt[i - 1] > W) {
				KS[i][w] = KS[i - 1][w];
			} else {
				KS[i][w] = max(val[i - 1] + KS[i - 1][w - wt[i - 1]], KS[i - 1][w]);
			}
		}
	}
	return KS[n][W];
}

int main (void) {
	int W, n;
	cout << "Enter the number of items and the maximum capacity:" << endl;
	cin >> n >> W;
	vector<int> val;
	vector<int> wt;
	for (int i = 0; i < n; i++) {
		int v, w;
		cout << "Enter value and weight of " << (i + 1) << " item:" << endl;
		cin >> v >> w;
		val.push_back(v);
		wt.push_back(w);
	}
	cout << "The maximum sum of values that we can get (given the restrictions on weights) is:" << KnapSack(W, val, wt, n) << endl;
	val.erase(val.begin(), val.end());
	wt.erase(wt.begin(), wt.end());
	return 0;
}
