class Solution {
public:
    string convertToBase7(int num) {
        if(num==0)return "0";
        bool sign;
        sign=num<0?true:false;
        num=abs(num);
        string ans="";

        while(num){
            ans=char((num%7+'0'))+ans;
            num/=7;
        }
        return sign?"-"+ans:ans;
    }
};