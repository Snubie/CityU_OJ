#include <cstdio>
#include <vector>
using namespace std;

void solve() {
	int n, count = 0;
	double avg = 0;
	scanf("%d", &n);
	vector<int> score(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &score[i]);
		avg += score[i];
	}

	avg /= n;

	for (int i = 0; i < n; i++)
		if (score[i] > avg)
			count++;

	double ans = (double) count * 100 / n;
	printf("%.3f%c\n", ans, '%');
}

int main() {
	int c;
	scanf("%d", &c);
	while (c--) {
		solve();
	}
	return 0;
}