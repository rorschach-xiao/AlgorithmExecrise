#include<iostream>
#include<vector>
using namespace std;
class CountInverse {
public:
	vector<int> arr;
	int arr_size;
	vector<int> temp_arr;

	CountInverse();
	~CountInverse();

	int merge(int left, int mid, int right);
	int Count(int left, int right);
};

CountInverse::CountInverse() {}
CountInverse::~CountInverse() {
	vector<int>().swap(arr);
	vector<int>().swap(temp_arr);
}
int CountInverse::merge(int left, int mid, int right) {
	//count the number of inversion
	int i = mid, j = right;
	long long int count = 0;
	while (i >= left && j > mid) {
		if (arr[i] > (long long)arr[j] * 3) {
			count += j - mid;
			i--;
		}
		else {
			j--;
		}
	}
	//merge two subsequences into temp_arr
    i = mid, j = right;
	int k = 0;
	while (i >= left && j > mid) {
		if (arr[i] > arr[j]) {
			temp_arr.push_back(arr[i--]);
			k++;
		}
		else {
			temp_arr.push_back(arr[j--]);
			k++;
		}
	}
	if (i >= left) {
		while (i >= left) {
			temp_arr.push_back(arr[i--]);
			k++;
		}
	}
	if (j > mid) {
		while (j > mid) {
			temp_arr.push_back(arr[j--]);
			k++;
		}
	}
	//Inverse the temp_arr and fill arr with it 
	for (int i = 0; i < k; i++) {
		arr[right - i] = temp_arr[i];
	}
	vector<int>().swap(temp_arr);
	return count;
}
int CountInverse::Count(int left, int right) {
	int result = 0;
	if (right > left) {
		int mid = (left + right) / 2;
		result += Count(left, mid);
		result += Count(mid + 1, right);
		result += merge(left, mid, right);
	}
	return result;
}
int main(int argc, char** argv) {
	CountInverse counter;
	int count = 0;

	cin >> counter.arr_size;
	for (int i = 0; i < counter.arr_size; i++) {
		int temp;
		cin >> temp;
		counter.arr.push_back(temp);
	}
	count = counter.Count(0, counter.arr_size - 1);
	cout << count << endl;
	system("pause");
	return 0;
}