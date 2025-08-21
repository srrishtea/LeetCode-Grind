class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int num:nums) {
            pq.push(num);
        }
        long long sum=0;
        while(k>0) {
            int num=pq.top();
            pq.pop();
            sum+=num;
            pq.push((num + 3 - 1) / 3);
            k--;
        }
        return sum;
    }
};