class Solution {
public:
    int hammingWeight(int n) {
        string ans="";
        int c=0;
        for(;n>0;){
            int r=n%2;
            if(r==1)
                c++;
            ans=to_string(r)+ans;
            n=n/2;
        }
        return c;
    }
};