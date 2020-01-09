#include <iostream>
#include <vector>
using namespace std;
class MajorityElement {
public:
	vector<long long int> multiset;
	int n;

	MajorityElement();
	~MajorityElement();

	long long int vote(vector<long long int>multiset);
};
MajorityElement::MajorityElement() {}
MajorityElement::~MajorityElement() {
	vector<long long int>().swap(multiset);
}
long long int MajorityElement::vote(vector<long long int>multiset) {
	int count=0;
	int candidate;
	for (int i = 0; i < n; i++) {
		if (count == 0) {
			candidate = multiset[i];
			count++;
		}
		else if (candidate == multiset[i]) count++;
		else {
			count--;
		}
	}
	return count;
}
int main(int argc, char** argv) {
	MajorityElement s;
	scanf_s("%d", &s.n);
	int count = 0;
	long long int candidate;
	for (int i = 0; i < s.n; i++) {
		long long int temp;
		scanf_s("%lld", &temp);
		s.multiset.push_back(temp);
	}
	printf("%lld", candidate);
	system("pause");
	return 0;
}