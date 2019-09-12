#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class KthElement{
public:
	vector<int> UnsortedArray;
	int N;

	KthElement();
	~KthElement();

	int GetKthElement(int k, vector<int> a,int N);
};
KthElement::KthElement(){}
KthElement::~KthElement() {
	vector<int>().swap(UnsortedArray);
}
int KthElement::GetKthElement(int k, vector<int> a,int N) {
	priority_queue<int, vector<int>, greater<int>> Q;
	int result;
	for (int i = 0; i < k; i++) { //find the kth largest element of the topk elements.
		Q.push(a[i]);
	}
	for (int i = 0; i < N - k; i++) {
		if (a[k + i] > Q.top()) {
			Q.pop();
			Q.push(a[k + i]);
		}
	}
	result = Q.top();
	return result;
}
int main(int argc,char** argv) {
	KthElement solution;
	int k,re;
	cin >> solution.N >> k;
	for (int i = 0; i < solution.N; i++) {
		int temp; 
		cin >> temp;
		solution.UnsortedArray.push_back(temp);
	}
	re = solution.GetKthElement(k, solution.UnsortedArray, solution.N);
	cout << re << endl;
	system("pause");
	return 0;
}