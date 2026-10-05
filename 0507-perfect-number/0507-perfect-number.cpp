class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum=0;
        for(int i=1;i*i<num;i++){
            if(num%i==0){
                int n2=num/i;
                    sum=sum+i+n2;
            }
        }
        if((sum-num)==num)
            return true;
        else
            return false;
    }
};