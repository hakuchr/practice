#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == NULL) return 0;
        int depth_left = TreeDepth(pRoot->left);
        int depth_right = TreeDepth(pRoot->right);
        return (depth_left >= depth_right) ? depth_left+1 : depth_right+1;
    }
};