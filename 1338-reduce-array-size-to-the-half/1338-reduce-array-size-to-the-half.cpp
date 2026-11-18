class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>cnt;
        for(int x:arr) ++cnt[x];

        vector<int>freqs;
        for (auto [_, freq] : cnt) freqs.push_back(freq);
        sort(freqs.begin(), freqs.end());
        
        int ans = 0, removed = 0, half = arr.size() / 2, i = freqs.size() - 1;
        while (removed < half) {
            ans += 1;
            removed += freqs[i--];
        }
        return ans;
    }
};