class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        map<int,int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        vector<vector<int>> res;
        for (auto &p : freq) {
            res.push_back({p.first, p.second});
        }
        return res;
    }
};
