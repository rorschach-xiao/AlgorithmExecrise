#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode *insertionSortList(ListNode *head) {
	if (!head || !head->next)
		return head;
	ListNode * dummy = new ListNode(0);
	while (head) {
		ListNode* temp = dummy;//²åÈëµÄÎ»ÖÃ
		ListNode* next = head->next;
		while (temp->next != NULL && temp->next->val < head->val) {
			temp = temp->next;
		}
		head->next = temp->next;
		temp->next = head;
		head = next;
	}
	return dummy->next;
}
ListNode* ReverseNode(ListNode * head) {
	ListNode* prev = nullptr;
	ListNode* curr = head;
	while (curr != NULL && curr->next != NULL) {
		ListNode* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	curr->next = prev;
	return curr;

}
void reorderList(ListNode *head) {
	if (!head || !head->next)
		return;
	ListNode *fast = head->next;
	ListNode *slow = head;

	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode *left = head;
	ListNode *right = ReverseNode(slow->next);
	ListNode *temp = new ListNode(0);
	ListNode *head_t = temp->next;
	while (right != NULL) {
		temp->next = left;
		left = left->next;
		temp = temp->next;
		temp->next = right;
		right = right->next;
		temp = temp->next;
	}
	if (left == slow) {
		temp->next = left;
		temp->next->next = NULL;
	}
	head = head_t;
}

int main() {
	ListNode head(1),next(2),next2(3),next3(4);
	head.next = &next;
	next.next = &next2;
	next2.next = &next3;
	//ReverseNode(&head);
   	reorderList(&head);
	//head=*(insertionSortList(&head));
}
