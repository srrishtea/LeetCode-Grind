class Solution {
public:
    bool dfs(string& b, int i, string nxt, unordered_map<string, vector<char>>& m, unordered_set<string>& seen) {
        if (b.size() == 1) return true;
        if (i == b.size() - 1) return dfs(nxt, 0, "", m, seen);
        string key = b.substr(i, 2);
        if (m.find(key) == m.end()) return false;
        for (char c : m[key]) {
            string s = nxt + c;
            string st = b.substr(i) + "|" + s;
            if (!seen.count(st)) {
                if (dfs(b, i + 1, s, m, seen)) return true;
                seen.insert(st);
            }
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> m;
        for (auto& a : allowed)
            m[a.substr(0, 2)].push_back(a[2]);
        unordered_set<string> seen;
        return dfs(bottom, 0, "", m, seen);
    }
};
