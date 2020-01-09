#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class InorderTraversal {
public:
	vector<int> inorderTraversal_iter(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> result;
		TreeNode *cur = root;
		while (cur || !s.empty()) {
			while (cur) {
				s.push(cur);
				cur = cur->left;
			}
			if (!s.empty()) {
				result.push_back(s.top()->val);
				cur = s.top();
				s.pop();
			}
			cur = cur->right;
		}
		return result;
	}
	vector<int> inorderTraversal_recur(TreeNode* root) {
		vector<int> result;
		inorderTraversal_help(root, result);
		return result;
	}
	void inorderTraversal_help(TreeNode* root, vector<int> &result) {
		if (root) {
			inorderTraversal_help(root->left, result);
			result.push_back(root->val);
			inorderTraversal_help(root->right, result);
		}
	}
};
int main(){}