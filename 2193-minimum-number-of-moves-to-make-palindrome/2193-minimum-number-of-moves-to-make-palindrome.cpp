class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int l=0;
        int r=s.length()-1;

        int c=0;
        int center=-1;
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
                continue;
            }
            int k=l+1;
            for(;k<r;k++){
                if(s[k]==s[r]){
                    break;
                }
            }
            if(k==r){
                //odd center
                center=r;
                r--;
                continue;
            }
            for(int j=k;j>l;j--){
                swap(s[j],s[j-1]);
                c++;
            }
            l++;
            r--;
            }
            if(center!=-1){
                c+=(center-s.length()/2);
            }
        return c;
    }
};