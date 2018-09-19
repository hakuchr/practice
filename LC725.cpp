#include <iostream>
#include <vector>
using namespace std;
 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> parts(k, NULL);
        ListNode* node = root;
        int len = 0;
        while(node){
            node = node->next;
            ++len;
        }
        int base = len / k;
        int ext = len % k;
        node = root;
        ListNode* prev = NULL;
        for (int i = 0; i < k && node; ++i, --ext){
            parts[i] = node;
            for (int j = 0; j < base + (ext > 0); ++j){
                prev = node;
                node = node->next;
            }
            prev->next = NULL;
        }
        return parts;
    }
};

int main()
{
    Solution Sol;
    int list_len = 0;
    ListNode* s, *p;
    ListNode* root = NULL;
    int k = 0;
    cout << "Input list length: " << endl;
    cin >> list_len;
    cout << "Input list elements: " << endl;
    for (int i = 0; i < list_len; ++i){
        int num = 0;
        cin >> num;
        s = new ListNode;
        s->val = num;
        if (root == NULL)
            root = s;
        else
            p->next = s;
        p = s;
    }
    p->next = NULL;
    cout << "Input num of parts: " << endl;
    cin >> k;
    cout << "Output: " << endl;
    vector<ListNode*> parts = Sol.splitListToParts(root, k);
    for (int i = 0; i < parts.size(); ++i){
        ListNode* node = parts[i];
        cout << '[';
        while (node){
            cout << node->val;
            if (node->next)
                cout << ", ";
            node = node->next;
        }
        cout << "]" << endl;
    }
    system("pause");
    return 0;
}