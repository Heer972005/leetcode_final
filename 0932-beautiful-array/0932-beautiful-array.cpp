class Solution {
public:
    unordered_map<int, vector<int>> memo;

    vector<int> beautifulArray(int N) {
        memo.clear();
        return f(N);
    }

    vector<int> f(int N) {
        // If already calculated, return it
        if (memo.find(N) != memo.end()) {
            return memo[N];
        }

        vector<int> ans(N);

        // Base case
        if (N == 1) {
            ans[0] = 1;
        }
        else {
            int t = 0;

            // Odds
            for (int x : f((N + 1) / 2)) {
                ans[t++] = 2 * x - 1;
            }

            // Evens
            for (int x : f(N / 2)) {
                ans[t++] = 2 * x;
            }
        }

        // Store result in memo
        memo[N] = ans;

        return ans;
    }
};