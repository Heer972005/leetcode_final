class Solution {
public:
    int minOperations(int k) {
        int sq=sqrt(k);
        int sum=1;
        for(int i=0;i<sq;i++){
            sum+=1;
        }
        //int q=(k-1)/(sq-1);
        return sq+(k-1)/sq-1;
    }
};