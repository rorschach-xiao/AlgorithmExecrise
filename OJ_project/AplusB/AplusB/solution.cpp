#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
class BigNumSum {
public:
	string A;
	string B;
	string result="";

	BigNumSum(string filename);
	BigNumSum();
	~BigNumSum();

	string GetSum(string a, string b);
};
BigNumSum::BigNumSum() {
	this->A = "";
	this->B = "";
}
BigNumSum::BigNumSum(string filename) {
	char a[30];
	ifstream input(filename,ios::in);
	if (!input) {
		cout << "can't open the file" << endl;
		return;
	}
	input.getline(a, sizeof(a));
	stringstream list(a);
	list >> A >> B;
	cin >> A >> B;
}
BigNumSum::~BigNumSum() {}
string BigNumSum::GetSum(string a, string b) {
	int size_A, size_B;
	size_A = a.size();
	size_B = b.size();
	string re_inv="";
	int cur_A = size_A-1,cur_B=size_B-1, flag = 0;
	while (cur_A >= 0&&cur_B >= 0) {
		int temp = 0;
		if (flag == 1) {
			temp = flag;
			flag = 0;
		}
		temp += a[cur_A] - '0' + b[cur_B] - '0';
		if (temp >= 10) {
			flag = 1;
			temp = temp % 10;
		}
		re_inv += temp + '0';
		cur_A--;
		cur_B--;
	}
	if (cur_B >= 0 ) {
		while (cur_B >=0) {
			int temp = b[cur_B]-'0';
			if (flag == 1) {
				temp += flag;
				flag = 0;
			}
			if (temp >= 10) {
				flag = 1;
				temp = temp % 10;
			}
			re_inv += temp + '0';
			cur_B--;
		}
	}
    if (cur_A >= 0) {
		while (cur_A >= 0) {
			int temp = a[cur_A]-'0';
			if (flag == 1) {
				temp += flag;
				flag = 0;
			}
			if (temp >= 10) {
				flag = 1;
				temp = temp % 10;
			}
			re_inv += temp + '0';
			cur_A--;
		}
	}
	if (flag == 1)
		re_inv += '1';
	string re(re_inv.rbegin(), re_inv.rend());
	return re;
}
int main(int argc, char **argv) {
	BigNumSum sum;
	cin >> sum.A >> sum.B;
	sum.result = sum.GetSum(sum.A, sum.B);
	cout << sum.result << endl; 
	ofstream output("output.txt", ios::out);
	output << sum.result << endl;
	output.close();
	system("pause");
	return 0;
}