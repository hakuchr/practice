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
        return BS_Depth(pRoot) != -1;
    }

    int BS_Depth(TreeNode* pRoot) {
        if (pRoot == NULL)
            return 0;
        int Depth_left = BS_Depth(pRoot->left); //后续遍历
        if (Depth_left == -1) //左右若存在-1，则直接返回-1
            return -1;
        int Depth_right = BS_Depth(pRoot->right);
        if (Depth_right == -1)
            return -1;
        if (abs(Depth_left - Depth_right) > 1) //若左子树和右子树的高度差大于1，返回-1
            return -1;
        else
            return 1 + max(Depth_left, Depth_right);
    }
};