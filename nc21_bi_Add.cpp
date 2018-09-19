class Solution {
public:
    int Add(int num1, int num2)
    {
        int n1 = (num1 & num2) << 1;
        int n2 = num1 ^ num2;
        while (n1 != 0){
            int n1t = (n1 & n2) << 1;
            n2 = n1 ^ n2;
            n1 = n1t;
        }
        return n2;
    }
};

//https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=11201&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking