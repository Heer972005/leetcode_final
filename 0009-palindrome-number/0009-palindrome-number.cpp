class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int rev=0;
        int n=x;
        // if  x>0 then will not work for negative numbers
        while(x>0){
            int pop=x%10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
                return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
                return 0;
            rev = rev * 10 + pop;
            x/=10;
        }
        // if(x<0) return (-1*rev);
        return (rev==n);
    }
};
