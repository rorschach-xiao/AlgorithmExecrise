#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct job {
	int p_time;
	int f_time;
};
bool jobcmp(job a, job b) {
	return a.f_time > b.f_time;
}
class JobSchedule {
public:
	vector<job> GetSchedule(vector<int> &p, vector<int> &f) {
		int size = p.size();
		vector<job> schedule;
		if (size == 0)
			return schedule;
		for (int i = 0; i < size; i++) {
			job temp;
			temp.f_time = f[i];
			temp.p_time = p[i];
			schedule.push_back(temp);
		}
		sort(schedule.begin(), schedule.end(), jobcmp);
		return schedule;
	}
	long long GetMinTime(vector<job> schedule) {
		int size = schedule.size();
		if (size == 0)
			return 0;
		long long ending = 0;
		long long p_ending = 0;
		for (int i = 0; i < size; i++) {
			p_ending += schedule[i].p_time;
			if (p_ending + schedule[i].f_time > ending) {
				ending = p_ending + schedule[i].f_time;
			}
		}
		return ending;
	}

};
int main() {
	JobSchedule solution;
	vector<int> p;
	vector<int> f;
	int temp;
	while (scanf_s("%d", &temp) != EOF) {
		p.push_back(temp);
		if (cin.get() == '\n') break;
	}
	while (scanf_s("%d", &temp) != EOF) {
		f.push_back(temp);
		if (cin.get() == '\n') break;
	}
	vector<job> schedule;
	schedule = solution.GetSchedule(p, f);
	cout << solution.GetMinTime(schedule) << endl;
	system("pause");
	return 0;
}