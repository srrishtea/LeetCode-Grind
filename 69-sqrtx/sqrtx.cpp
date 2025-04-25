class Solution {
public:
    int mySqrt(int x) {
        if(x==1|| x==0) return x;
        int low=0, high=x, ans=-1;
        //vector<int>nums(n);
        while(low<=high) {
            int mid=low+(high-low)/2;
            long long sq = 1LL * mid * mid;
            if(sq==x) return mid;
            if(sq>x) {
                
                high=mid-1;

            } else {
                ans=mid;
                low=mid+1;

            }
        }
        return ans;
    }
};