class Solution {
public:
    string arrangeWords(string text) {
        text[0] = text[0] - ('A' - 'a');

        string tmp = "";
        int textlen = text.size();
        // 利用map的key自动排序特性，将相同长度的单词，都放在它后面
        map<int, vector<string>> lenStrMap;
        for (int i = 0; i <= textlen; i++) {
            if (text[i] == ' ' || i == textlen){
               lenStrMap[tmp.size()].push_back(tmp);
                // cout<<tmp<<endl;
               tmp = "";
            } else {
                tmp += text[i];
            }
        }

        string ans;
        for (auto &pair : lenStrMap) {
            // std::cout << pair.first;
            for (auto &str : pair.second) {
                ans += str;
                if (ans.size() != textlen) {
                    ans += ' ';
                }
            }
        }
        ans[0] = ans[0] + ('A' - 'a');
        return ans;
    }
};
