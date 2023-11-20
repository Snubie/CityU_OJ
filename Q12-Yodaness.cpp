#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int ans;

// standard merge sort
void merge(vector<int>& nums, int start, int mid, int end) {
	int llen = mid - start + 1;
	int rlen = end - (mid + 1) + 1;
	vector<int> larr(llen);
	vector<int> rarr(rlen);
	for (int i = 0; i < llen; i++)
		larr[i] = nums[start + i];
	for (int i = 0; i < rlen; i++)
		rarr[i] = nums[mid + 1 + i];

	int lindex = 0, rindex = 0, nindex = start;
	while (lindex < llen && rindex < rlen) {
		if (larr[lindex] <= rarr[rindex])
			nums[nindex++] = larr[lindex++];
		else {
			nums[nindex++] = rarr[rindex++];

			//ans part
			int remain = llen - lindex;
			ans += remain;
		}

	}

	while (lindex < llen)
		nums[nindex++] = larr[lindex++];
	while (rindex < rlen)
		nums[nindex++] = rarr[rindex++];
}

void solve(vector<int>& nums, int start, int end) {
	if (start >= end)
		return;
	int mid = start + (end - start) / 2;
	solve(nums, start, mid);
	solve(nums, mid + 1, end);
	merge(nums, start, mid, end);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;
		ans = 0;

		unordered_map<string, int> map;
		vector<int> nums(n);

		for (int i = 1; i <= n; i++) {
			string temp;
			cin >> temp;
			map.insert({ temp,i });
		}
		for (int i = 0; i < n; i++) {
			string temp;
			cin >> temp;
			nums[i] = map[temp];
		}

		solve(nums, 0, n - 1);
		cout << ans << "\n";
	}
}