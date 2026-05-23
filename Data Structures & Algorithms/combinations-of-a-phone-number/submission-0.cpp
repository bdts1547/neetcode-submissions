class Solution {
public:
    vector<string> vdigits = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits == "") return res;
        string subset;
        vector<bool> visitedDigit;
        backtracking(0, digits, subset, res, visitedDigit);


        return res;
    }

    void backtracking(int k, string digits, string& subset, vector<string>& res,
    vector<bool>& visitedDigit) {
        if (subset.size() == digits.size()) {
            res.push_back(subset);
            return;
        }
        if (k >= digits.size()) return;


        // for (int i = k; i < digits.size(); i++) {
        //     if (!visitedDigit[i]) {
        //         visitedDigit[i] = true;
        //         int digit = (int) digits[i];
        //         string chars = vdigits[digit];
        //         for (int j = 0; j < chars.size(); j++) {
        //             subset.push_back(chars[j]);
        //             backtracking(k+1, digits, subset, res, visitedDigit);
        //             subset.pop_back();
        //         }

        //         visitedDigit[i] = false;
        //     }
        // }
        int num = digits[k] - '0';
        cout << num << endl;
        string chars = vdigits[num];
        for (int i = 0; i < chars.size(); i++) {
            cout << subset << endl;
            subset.push_back(chars[i]);
            backtracking(k+1, digits, subset, res, visitedDigit);
            subset.pop_back();
        }

    }

    
};
