class Solution {
public:
    bool possible(int day, vector<int>&arr,int m,int k) {
        int cnt=0, boq=0;
        for(int i=0;i<arr.size();i++) {
            if(arr[i]<=day) {
                cnt++;
                if(cnt==k) {
                    boq++;
                    cnt=0;
                }
            } else {
                cnt=0;
            }
        }
        return boq>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
       if(1LL*m*k>bloomDay.size()) return -1;
       int low=*min_element(bloomDay.begin(), bloomDay.end());
       int high=*max_element(bloomDay.begin(),bloomDay.end());
       int ans=-1;

       while(low<=high) {
        int mid=(low+high)/2;
        if(possible(mid,bloomDay,m,k)) {
            ans=mid;
            high=mid-1;
        } else{
            low=mid+1;
        }
       } 
       return ans;
    }
};