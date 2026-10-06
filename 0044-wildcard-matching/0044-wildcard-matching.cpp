class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0;//s
        int j=0;//p

        int strtJ=-1;
        int lst_mtch=-1;

        while(i<s.size()){
            if(j<p.size()&&(s[i]==p[j]||p[j]=='?')){
                i++;
                j++;
            }
            else if(j<p.size()&&p[j]=='*'){
                strtJ=j;
                j++;
                lst_mtch=i;
            }
            else if(strtJ!=-1){
                j=strtJ+1;
                lst_mtch++;
                i=lst_mtch;
            }
            else return false;
        }
        while(j<p.size()&&p[j]=='*')
            j++;
        return j==p.size();
    }
};