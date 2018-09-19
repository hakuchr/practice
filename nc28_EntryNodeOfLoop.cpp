#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        unordered_map<ListNode*, bool> map;
        while (pHead){
            unordered_map<ListNode*, bool>::iterator iter = map.find(pHead);
            if (iter != map.end())
                return pHead;
            map[pHead] = true;
            pHead = pHead->next;
        }
        return NULL;
    }
};