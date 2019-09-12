#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class KthElement{
public:
	vector<int> UnsortedArray;
	int N;
	int k;

	KthElement();
	~KthElement();

	int PriorityQueueMethod(int k, vector<int> a,int N);
	int QuickSortMethod(int start,int end);
	int BubbleSortMethod(int k,int N);
};
KthElement::KthElement(){}
KthElement::~KthElement() {
	vector<int>().swap(UnsortedArray);
}
int KthElement::PriorityQueueMethod(int k, vector<int> a,int N) {
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
int KthElement::QuickSortMethod(int start,int end ) {
	if (start >= end) {
		return UnsortedArray[end];
	}
	int left = start, right = end;
	int cardinal = UnsortedArray[left];
	while (left != right) {
		while (UnsortedArray[right] <= cardinal && right > left) {
			right--;
		}
		while (UnsortedArray[left] >= cardinal && right > left) {
			left++;
		}
		if (right > left) {
			int temp;
			temp = UnsortedArray[left];
			UnsortedArray[left] = UnsortedArray[right];
			UnsortedArray[right] = temp;
		}
	}
	UnsortedArray[start] = UnsortedArray[right];
	UnsortedArray[right] = cardinal;
	if (right == k - 1)
		return UnsortedArray[right];

	else if (right < k - 1)
		return QuickSortMethod(right + 1, end);
	else if (right > k - 1)
		return QuickSortMethod(start, right - 1);
}
int KthElement::BubbleSortMethod(int k,int N) {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (UnsortedArray[j] > UnsortedArray[j + 1]) {
				int temp = UnsortedArray[j];
				UnsortedArray[j] = UnsortedArray[j + 1];
				UnsortedArray[j + 1] = temp;
			}
		}
	}
	return UnsortedArray[N - k];
}
int main(int argc,char** argv) {
	KthElement solution;
	int re;
	cin >> solution.N >> solution.k;
	for (int i = 0; i < solution.N; i++) {
		int temp; 
		cin >> temp;
		solution.UnsortedArray.push_back(temp);
	}
	//re = solution.PriorityQueueMethod(solution.k, solution.UnsortedArray, solution.N);
	re = solution.QuickSortMethod(0, solution.N - 1);
	//re = solution.BubbleSortMethod(solution.k, solution.N);
	cout << re << endl;
	system("pause");
	return 0;
}