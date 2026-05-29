class Solution {
public:
    vector<vector<string>> partition(string s) {
       vector<vector<string>> res;
       vector<string> subset;
        dfs(0, s, subset, res);
       return res; 
    }

    void dfs(int i, string s, vector<string>& subset, vector<vector<string>>& res) {
        if (i >= s.size()) {
            res.push_back(subset);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            if (isPalin(s, i, j)) {
                subset.push_back(s.substr(i, j - i + 1));
                dfs(j+1, s, subset, res);
                subset.pop_back();
            }
        }
    }

    bool isPalin(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }
};
