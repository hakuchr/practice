#include <iostream>
#include <math.h>
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
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot == NULL)
            return true;
        if (abs(TreeDepth(pRoot->left) - TreeDepth(pRoot->right)) > 1)
            return false;
        else
            return true;
        return (IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right));
    }

    int TreeDepth(TreeNode* pRoot) //两层递归，重复遍历，开销较大
    {
        if (pRoot == NULL) return 0;
        int depth_left = TreeDepth(pRoot->left);
        int depth_right = TreeDepth(pRoot->right);
        return (depth_left >= depth_right) ? depth_left+1 : depth_right+1;
    }
};