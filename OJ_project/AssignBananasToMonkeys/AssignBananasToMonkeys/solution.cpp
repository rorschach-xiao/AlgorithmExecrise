#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int bananas[200000];
	int monkeys[200000];
	int i = 0, j = 0;
	int result=0;
	while (cin >> monkeys[i]) {
		i++;
		if (cin.get() == '\n') break;
	}
	sort(monkeys, monkeys + i);
	while (cin >> bananas[j]) {
		j++;
		if (cin.get() == '\n') break;
	}
	sort(bananas, bananas + j);
	int N = i;
	for (i = 0; i < N; i++) {
		if (result < abs(monkeys[i] - bananas[i]))
			result = abs(monkeys[i] - bananas[i]);
	}
	cout << result << endl;
	return 0;
}