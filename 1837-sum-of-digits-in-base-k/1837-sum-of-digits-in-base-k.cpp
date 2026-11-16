class Solution {
public:
    int sumBase(int n, int k) {
        int ttl=0;
        while(n>0){
            ttl=n%k+ttl;
            n/=k;
        }
        return ttl;
    }
};