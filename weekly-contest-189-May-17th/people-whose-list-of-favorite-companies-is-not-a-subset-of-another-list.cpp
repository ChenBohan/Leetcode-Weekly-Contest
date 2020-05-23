class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        // Both ranges of std::includes must be sorted with operator<.
        for (auto& i : favoriteCompanies) {
            sort(i.begin(), i.end());
        }

        map<int, vector<int>> indexLengthMap;
        for (int i = 0; i < favoriteCompanies.size(); i++) {
            indexLengthMap[favoriteCompanies[i].size()].push_back(i);
        }
        
        // c.rbegin() 返回一个逆序迭代器，它指向容器c的最后一个元素
        // c.rend() 返回一个逆序迭代器，它指向容器c的第一个元素前面的位置
        vector<int> ans;
        for (auto it = indexLengthMap.rbegin(); it != indexLengthMap.rend(); it++) {
            for (auto i : it->second) {
                if (it != indexLengthMap.rbegin() && checkSubSet(favoriteCompanies, ans, i)) {
                    continue;
                } else {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }

    bool checkSubSet(vector<vector<string>>& str, vector<int> ans, int i) {
        for (auto j : ans) {
            if (std::includes(str[j].begin(), str[j].end(), str[i].begin(), str[i].end()))
                return true;
        }
        return false;
    }

};
