class Solution {
    public String intToRoman(int num) 
    {
        String sum="";
        int a1[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        String a2[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        for(int i=0;i<a1.length;i++)
        {
while(num>=a1[i])
{
num=num-a1[i];
sum=sum+a2[i];
}
        }
        System.out.println(sum);
          return sum;
    }
}