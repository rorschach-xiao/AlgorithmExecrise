#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>
#include <iomanip>
using namespace std;
#define MaxN 200000

//定义比较函数，对x坐标进行排序
bool cmpx(const pair<double, double>& p1, const pair<double, double>& p2) {
	if (p1.first != p2.first)
		return p1.first < p2.first;
	return p1.second < p2.second;
}
//定义比较函数，对y坐标进行排序
bool cmpy(const pair<double, double>&p1, const pair<double, double>&p2) {
	return p1.second < p2.second;
}
class Min2DDistance {
public:
	pair<double, double> *points;
	pair<double, double> *MediumPoint;

	Min2DDistance(int N);
	~Min2DDistance();

	double GetMinDistance(int left, int right);
	double dist(pair<double, double>p1, pair<double, double> p2);

};
Min2DDistance::Min2DDistance(int N) {
	points = new pair<double, double>[N];
	MediumPoint = new pair<double, double>[N];
}
Min2DDistance::~Min2DDistance() {
	delete[] points;
	delete[] MediumPoint;
}
double Min2DDistance::dist(pair<double, double>p1, pair<double, double> p2) {
	return sqrt((p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second));
}
double Min2DDistance::GetMinDistance(int left, int right) {
	double d = INFINITY;
	int mid = (left + right) / 2;
	double re;
	if (right == left) {
		return d;
	}
	else if (left + 1 == right) {
		return dist(points[left], points[right]);
	}
	else {
		double dl, dr;
		dl = GetMinDistance(left, mid);
		dr = GetMinDistance(mid + 1, right);
		d = dl < dr ? dl : dr;
	}
	//calcualte the points' distance in the range of [-d,+d]
	int k = 0;
	for (int i = left; i <= right; i++) {
		if (abs(points[mid].first - points[i].first) <= d) {
			MediumPoint[k++]=points[i];
		}
	}
	sort(MediumPoint, MediumPoint + k, cmpy);
	double d_mid = INFINITY;
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k&&abs(MediumPoint[j].second -MediumPoint[i].second) <= d; j++) {
			if (dist(MediumPoint[i], MediumPoint[j]) < d_mid) {
				d_mid = dist(MediumPoint[i], MediumPoint[j]);
			}
		}
	}
	re = d < d_mid ? d : d_mid;
	return re;
}
int main(int argc, char** argv) {
	int N;
	cin >> N;
	Min2DDistance ruler(N);
	for (int i = 0; i < N; i++) {
		double x, y;
		cin >> x >> y;
		pair<double, double> temp(x, y);
		ruler.points[i] = temp;
	}
	sort(ruler.points, ruler.points + N, cmpx);
	cout << fixed << setprecision(3) << ruler.GetMinDistance(0, N - 1) / 2 << endl;
	return 0;
}