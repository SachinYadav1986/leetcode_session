class Solution {
public:
    void gen(vector<int>& candidates, int i, int target, int sum,
             vector<int> temp, vector<vector<int>>& res) {
        temp.push_back(candidates[i]);
        if (sum == target) {
            res.push_back(temp);
            return;
        }
        if (sum > target)
            return;

        gen(candidates, i, target, sum + candidates[i], temp, res);

        for (int j = i + 1; j < candidates.size();j++) {
            gen(candidates, j, target, sum + candidates[j], temp, res);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;

        for (int i = 0; i < candidates.size(); i++) {
            vector<int> temp;
            gen(candidates, i, target, candidates[i], temp, res);
        }
        return res;
    }
};
