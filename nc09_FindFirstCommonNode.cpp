#include <iostream>
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL || pHead2 == NULL)
            return NULL;
        int len1 = 0, len2 = 0;
        ListNode *p1 = pHead1, *p2 = pHead2;
        while (p1){
            p1 = p1->next;
            len1++;
        }
        p1 = pHead1;
        while (p2){
            p2 = p2->next;
            len2++;
        }
        p2 = pHead2;
        if (len1 <= len2){
            for (int dist = len2 - len1; dist > 0; --dist)
                p2 = p2->next;
        }else{
            for (int dist = len1 - len2; dist > 0; --dist)
                p1 = p1->next;
        }
        while (p1 != NULL){
                if (p1 == p2) return p1;
                p1 = p1->next;
                p2 = p2->next;
        }
        return NULL;
    }
};