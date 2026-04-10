class Solution {
public:
    void generate(vector<string>& s, string p, int n, int open, int close) {
        if (p.size() == 2 * n) {
            s.push_back(p);
            return;
        }
        if (close < open && close < n) {
            p.push_back(')');
            generate(s, p, n, open, close+1);
            p.pop_back();
        }
        if (open < n) {
            p.push_back('(');
            generate(s, p, n, open+1, close);
            p.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        int open = 0;
        int close = 0;
        string p;
        generate(s, p, n, open, close);
        return s;
    }
};
