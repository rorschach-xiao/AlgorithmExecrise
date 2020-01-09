#include<iostream>
#include<vector>
using namespace std;
class IntegerReverse {
public:
	int reverse(int x) {
		int pop, rev=0;
		while (x) {
			pop = x % 10;
			x /= 10;
			if (rev > INT_MAX / 10 || rev == INT_MAX && pop > 7)return 0;
			if (rev < INT_MIN / 10 || rev == INT_MIN && pop < -8)return 0;
			rev = rev * 10 + pop;
		}
		return rev;
	}
};
int main(){
	int x = -123;
	IntegerReverse solution;
	cout << solution.reverse(x) << endl;
	system("pause");
	return 0;
}