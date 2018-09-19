class Solution {
public:
    int Sum_Solution(int n) {
        int tmp = n;
        tmp && (tmp += Sum_Solution(n - 1));
        return tmp;
    }
};