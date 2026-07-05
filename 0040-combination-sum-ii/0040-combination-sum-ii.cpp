class Solution {
public:
    void solve(int start, int target,
               vector<int>& candidates,
               vector<int>& current,
               vector<vector<int>>& answer) {

        if (target == 0) {
            answer.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicate numbers at the same recursion level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // No need to continue if number is too large
            if (candidates[i] > target)
                break;

            // Choose
            current.push_back(candidates[i]);

            // Explore
            solve(i + 1,
                  target - candidates[i],
                  candidates,
                  current,
                  answer);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(
        vector<int>& candidates,
        int target
    ) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> answer;
        vector<int> current;

        solve(0, target, candidates, current, answer);

        return answer;
    }
};