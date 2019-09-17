#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<fstream>
#include<map>
#include<time.h>
#include<ctime>

using namespace std;

class KthElement {
public:
	vector<int> UnsortedArray;
	int N;
	int k;

	KthElement();
	~KthElement();


	int PriorityQueueMethod(int k, vector<int> a, int N);
	int QuickSortMethod(int start, int end);
	int BubbleSortMethod(int k, int N);
	int BFPRT(int start, int end, int key);
	int partition(int start, int end, int key);
	long long int MapMethod(map<long long int,int,greater<int>> NumMap, int k);
};
KthElement::KthElement() {
}
KthElement::~KthElement() {
	vector<int>().swap(UnsortedArray);
}
int KthElement::PriorityQueueMethod(int k, vector<int> a, int N) {
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
int KthElement::QuickSortMethod(int start, int end) {
	if (start >= end) {
		return UnsortedArray[end];
	}
	srand((int)time(0));
	int left = start, right = end;
	int cardinal = left+rand()%(right-left+1);
	swap(UnsortedArray[cardinal], UnsortedArray[start]);
	while (left != right) {
		while (UnsortedArray[right] <= UnsortedArray[start] && right > left) {
			right--;
		}
		while (UnsortedArray[left] >= UnsortedArray[start] && right > left) {
			left++;
		}
		if (right > left) {
			swap(UnsortedArray[left], UnsortedArray[right]);
		}
	}
	swap(UnsortedArray[right], UnsortedArray[start]);
	if (right == k - 1)
		return UnsortedArray[right];

	else if (right < k - 1)
		return QuickSortMethod(right + 1, end);
	else if (right > k - 1)
		return QuickSortMethod(start, right - 1);
}
int KthElement::BubbleSortMethod(int k, int N) {
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
int KthElement::BFPRT(int start, int end, int key) {
	if (end - start < 5) {
		sort(UnsortedArray.begin() + start, UnsortedArray.begin() + end + 1, greater<int>());
		return UnsortedArray[start + key - 1];
	}
	int sub_right = start - 1;
	int i, j;
	for (i = start, j = i + 4; j <= end; i += 5) {
		sort(UnsortedArray.begin() + i, UnsortedArray.begin() + j + 1, greater<int>());
		swap(UnsortedArray[++sub_right], UnsortedArray[i + 2]);
		j = j + 5;
	}
	if (i <= end && j > end) {
		sort(UnsortedArray.begin() + i, UnsortedArray.begin() + end, greater<int>());
		swap(UnsortedArray[++sub_right], UnsortedArray[i + (end - i) / 2]);
	}

	int pivotID = (start + sub_right) / 2;
	BFPRT(start, sub_right, pivotID - start + 1);
	int mid = partition(start, end, pivotID);
	if (mid - start == key - 1)
		return UnsortedArray[mid];
	else if (mid - start < key - 1) {
		return BFPRT(mid + 1, end, key - mid+start - 1);
	}
	else {
		return BFPRT(start, mid-1, key);
	}


}
int KthElement::partition(int start, int end, int key) {
	swap(UnsortedArray[key], UnsortedArray[end]);
	int left = start, right = end;
	while (left != right) {
		while (UnsortedArray[left] >= UnsortedArray[end] && right > left) {
			left++;
		}
		while (UnsortedArray[right] <= UnsortedArray[end] && right > left) {
			right--;
		}
		if (right > left) {
			swap(UnsortedArray[left], UnsortedArray[right]);
		}
	}
	swap(UnsortedArray[right], UnsortedArray[end]);
	return right;
}
long long int KthElement::MapMethod(map<long long int,int,greater<int>> NumMap, int k) {
	map<long long int, int, greater<int>>::iterator it;
	for (it = NumMap.begin(); it!=NumMap.end(); it++) {
		k -= (*it).second;
		if (k <= 0) return (*it).first;
	}
	return 0;
}

int main(int argc, char** argv) {
	KthElement solution;
	int re;
	scanf_s("%d %d", &solution.N, &solution.k);
	//int start_t = clock();
	for (int i = 0; i < solution.N; i++) {
		int temp;
		scanf_s("%d ", &temp);
		solution.UnsortedArray.push_back(temp);
	}

	//re = solution.PriorityQueueMethod(solution.k, solution.UnsortedArray, solution.N);
    //re = solution.QuickSortMethod(0, solution.N - 1);
	//re = solution.BubbleSortMethod(solution.k, solution.N);
	re = solution.BFPRT(0, solution.N-1, solution.k);
	//re = solution.MapMethod(NumMap, solution.k);
	//int end_t = clock();
	printf("%d", re);
	//cout << end_t - start_t << endl;
	//system("pause");
	return 0;
}