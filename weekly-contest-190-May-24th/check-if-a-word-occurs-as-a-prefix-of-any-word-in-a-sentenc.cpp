class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        int count = 1;
        while (!ss.fail()) {
            string word;
            ss >> word;
            if (word.find(searchWord, 0) == 0) {
                return count;
            }
            count++;
        }
        return -1;
    }
};
