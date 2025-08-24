class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a=0,b=0;
        for(int i:bills){
            if(i==5) a++;
            else if(i==10) {
                if(a==0) return false;
                else {
                    b++;
                    a--;}}
            else {
                if(a==0) return false;
                else{
                    if(b==0){
                        if(a<3) return false;
                        else a-=3;} 
                    else {
                        b--;
                        a--;}}}}
        return true;}};