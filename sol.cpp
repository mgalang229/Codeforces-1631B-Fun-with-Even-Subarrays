#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		bool same = true;
		for (int i = 1; i < n; i++) {
			same &= (a[i] == a[0]);
		}
		if (same) {
			cout << 0 << '\n';
			continue;
		}
		
		// let l = 1, k = 2
		// range: [l, 2 * k - 1] = [0, 3] -> subtract 1 (zero-based)
		
		// 1 2 3 4 5 6 -> indices
		// 2 1 3 4 5 3 -> elements
		// {2, 1, 3, 4} -> affected
		
		// update:
		// i = 0
		// a[l + i] = a[l + k + i]
		// a[0 + 0] = a[0 + 2 + 0]
		// a[0] = a[2]
		// a[0] = 3
		
		// i = 1
		// a[l + i] = a[l + k + i]
		// a[0 + 1] = a[0 + 2 + 1]
		// a[1] = a[3]
		// a[1] = 4
		
		// if we have k elements starting at (l - 1), then the range would be [l - 1, 2 * k - 1]
		// therefore, a[l + 0] = a[l + k + 0], ..., a[l + (k - 1)] = a[l + 2k - 1]
		
		// 2 1 3 4 5 3
		// 2 1 5 3 5 3
		// 5 3 5 3 5 3
		// 3 3 3 3 3 3
		
		// n = 4
		// 4 2 1 3
		// 4 2 3 3
		// 3 3 3 3
		// 2 operations
		
		// n = 5
		// 4 2 1 3 5
		// 4 2 1 3 3
		// 4 3 3 3 3
		// 3 3 3 3 3
		// 3 operations

		// 1 2 3 4 5 6 7 8
		// 1 2 3 4 5 6 8 8
		// 1 2 3 4 8 8 8 8
		// 8 8 8 8 8 8 8 8
		// 3 operations
		
		// 1 2 3 4 5 6 7 8 9
		// 1 2 3 4 5 6 7 9 9
		// 1 2 3 4 5 9 9 9 9
		// 1 9 9 9 9 9 9 9 9
		// 9 9 9 9 9 9 9 9 9
		// 4 operations
		
		// 1 2 3 4 5 6 9 9 9
		// 1 2 3 9 9 9 9 9 9
		// 9 9 9 9 9 9 9 9 9
		// 2 operations
		
		// 1 2 3 4 5 6 9 8 9
		// 1 2 3 4 5 6 9 9 9
		// 1 2 3 9 9 9 9 9 9
		// 9 9 9 9 9 9 9 9 9
		// 3 operations
		
		// 1 2 3 4 5 6 7
		// 1 2 3 4 5 7 7
		// 1 2 3 7 7 7 7
		// 7 7 7 7 7 7 7
		// 3 operations
		
		// 4 4 3 2 4
		// 4 4 3 4 4
		// 4 4 4 4 4
		
		// 1 2 3 9 5 6 7 8 9
		// 1 2 3 9 5 6 7 9 9
		// 1 2 3 9 5 6 7 9 9
		// 1 2 3 9 5 9 9 9 9
		// 1 9 9 9 9 9 9 9 9
		// 9 9 9 9 9 9 9 9 9
		// 4 operations
		
		// 1 2 3 4 5 9 9 9 9
		// 1 9 9 9 9 9 9 9 9
		// 9 9 9 9 9 9 9 9 9
		// 2 operations
		
		// 1 2 3 4 5
		// 1 2 3 5 5
		// 1 5 5 5 5
		// 5 5 5 5 5
		// 3 operations
		
		// 1 2 3
		// 1 3 3
		// 3 3 3
		// 2 operations
		
		// 9 9 9 9 9 9 9 9 1
		// 9 9 9 9 9 9 9 1 1
		// 9 9 9 9 9 1 1 1 1
		// 9 1 1 1 1 1 1 1 1
		// 1 1 1 1 1 1 1 1 1
		// 4 operations
		
		// 1 2 9 9 9 9 9 9 9
		// 9 9 9 9 9 9 9 9 9
		// 1 operation
		
		// 1 2 9 9 9 3 9 9 9
		// 1 2 9 9 9 9 9 9 9
		// 9 9 9 9 9 9 9 9 9
		// 2 operations
		
		int cnt = 0;
		int ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] == a[n - 1]) {
				cnt++;
			} else {
				int id = i;
				bool equal = true;
				int temp = cnt;
				while (id >= max(0, i - temp + 1)) {
					//cout << a[id] << " ";
					equal &= (a[id] == a[n - 1]);
					cnt++;
					id--;
				}
				if (!equal) {
					ans++;
				}
				i = id + 1;
			}
		}
		//cout << '\n';
		cout << ans << '\n';
	}
	return 0;
}
