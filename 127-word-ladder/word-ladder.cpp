class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Create a queue for BFS
        queue<pair<string, int>> q;

        // Create a hashset for quick lookup of words
        unordered_set<string> hashset(wordList.begin(), wordList.end());

        // If the endWord is not in the wordList, return 0 (no transformation possible)
        if (hashset.find(endWord) == hashset.end()) return 0;

        // Start BFS with the beginWord
        q.push({beginWord, 1});
        hashset.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // If we reach the endWord, return the number of steps
            if (word == endWord) return steps;

            // Try transforming each character of the current word
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                // Replace the current character with every possible letter
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    // If the transformed word is in the hashset, add it to the queue
                    if (hashset.find(word) != hashset.end()) {
                        hashset.erase(word); // Erase to prevent revisiting
                        q.push({word, steps + 1});
                    }
                }

                // Restore the original character
                word[i] = original;
            }
        }

        return 0; // If no transformation sequence is found
    }
};
