class Solution {
public:
    int check (char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return 1;
        } else {
            return 0;
        }
    }

    int maxVowels(string s, int k) {
        int max_cnt = 0, cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt += check(s[i]);
            if (i >= k) {
                cnt -= check(s[i - k]);
            }
            max_cnt = max(cnt, max_cnt);
        }
        return max_cnt;
    }
};
