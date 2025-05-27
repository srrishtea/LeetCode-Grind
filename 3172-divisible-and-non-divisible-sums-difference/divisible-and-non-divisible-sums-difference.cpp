class Solution {
public:
    int differenceOfSums(int n, int m) {
        int s=n*(n+1)/2;
        int num2=m*(n/m)*(n/m+1);
        return s-num2;
    }
};