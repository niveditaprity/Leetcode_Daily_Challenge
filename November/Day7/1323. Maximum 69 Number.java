class Solution {
    public int maximum69Number (int num) {
        int temp=num;
        int index=0;
        int i=1;
        while(temp>0){
            int rem=temp%10;
            if(rem==6){
                index=i;
            }
            temp=temp/10;
            i++;
        }
        if(index==0)return num;
        num=num+3*(int)Math.pow(10,index-1);
        return num;
    }
}