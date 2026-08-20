class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j=0,c=0;//j=cookie index,c=content children count
        while(j<s.size()&&c<g.size()){
            if(s[j]>=g[c]){
                c++;
            }
            j++;
        }
        return c;
    }
};