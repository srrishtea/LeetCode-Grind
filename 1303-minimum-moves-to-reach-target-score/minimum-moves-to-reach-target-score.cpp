class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
        
        while (target > 1) {
            if (maxDoubles > 0 && target % 2 == 0) {
                target /= 2;  // Divide by 2
                maxDoubles--;
            } else if (maxDoubles == 0) {
                return moves + (target - 1);  // If no more doubles, just do (target-1) additions
            } else {
                target--;  // Subtract 1
            }
            moves++;
        }
        return moves;
    }
};
