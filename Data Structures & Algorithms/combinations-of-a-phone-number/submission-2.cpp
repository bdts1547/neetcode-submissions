class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> vdigits = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if (digits == "") return res;
        string subset;
        backtracking(0, digits, subset, res, vdigits);


        return res;
    }

    void backtracking(int k, string digits, string& subset, vector<string>& res,
    vector<string> vdigits) {
        if (subset.size() == digits.size()) {
            res.push_back(subset);
            return;
        }
        
        int num = digits[k] - '0';
        string chars = vdigits[num];
        for (int i = 0; i < chars.size(); i++) {
            subset.push_back(chars[i]);
            backtracking(k+1, digits, subset, res, vdigits);
            subset.pop_back();
        }

    }

    
};
