#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};
class MergeKList {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int size = lists.size();
		if (size == 0)return NULL;
		if (size == 1)return lists[0];
		vector<ListNode*> temp;
		for (int i = 0; i < size; i = i + 2) {
			if (i + 1 < size)
				temp.push_back(merge2Lists(lists[i], lists[i + 1]));
			else
				temp.push_back(lists[i]);
		}
		return mergeKLists(temp);
	}
	ListNode* merge2Lists(ListNode* a, ListNode* b) {
		if (!a || !b) return a ? a : b;
		ListNode *head=a->val>b->val?b:a; //±£´æÍ·Ö¸Õë
		ListNode *cur=head;
		if (a->val > b->val) b = b->next;
		else a = a->next;
		while (a&&b) {
			if (a->val < b->val) {
				cur->next = a;
				cur = cur->next;
				a = a->next;
			}
			else {
				cur->next = b;
				cur = cur->next;
				b = b->next;
			}
		}
		if (a)cur->next = a;
		if (b)cur->next = b;
		return head;
	}
};
int main() {
	ListNode *h1 = new ListNode(1);
	ListNode *cur1 = h1;
	ListNode *h2 = new ListNode(1);
	ListNode *cur2 = h2;
	cur1->next = new ListNode(4);
	cur1 = cur1->next;
	cur1->next = new ListNode(5);
	cur1 = cur1->next;
	cur2->next = new ListNode(3);
	cur2 = cur2->next;
	cur2->next = new ListNode(4);
	cur2 = cur2->next;
	MergeKList solution;
	vector<ListNode*> v;
	v.push_back(h1);
	v.push_back(h2);
	ListNode* result = solution.mergeKLists(v);
	return 0;


	
}