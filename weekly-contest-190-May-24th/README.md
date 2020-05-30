# Leetcode-Weekly-Contest
Weekly Contest Problems on Leetcode 

### check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence

- [题目](https://leetcode-cn.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/)
- 思路
    - 遍历数组, 检查当前字符串的前缀是目标字符串即可
- 复杂度
    - 时间复杂度 O(NM): N 表示单词个数, M 表示搜索字符串长度, 对于每个单词需要匹配一遍搜索字符串, 所以复杂度是 O(NM)
    - 空间复杂度 O(1) 或 O(N): 如果利用 split 转成字符串列表就是 O(N), 如果直接对字符串本身进行处理就是 O(1). O(1)空间的做法, 就是碰到空格后重置下标即可

### check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence

- [题目](https://leetcode-cn.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)
- 思路
    - 固定长度为k的字符串 -> 滑动窗口
    - 固定一个长度为 k 的窗口, 以及窗口内元音字母的数目
    - 然后窗口每次向右滑动1格, 更新元音字母数目, 以及结果即可
    ```cpp
    for (int i = 0; i < s.size(); i++) {
        cnt += check(s[i]);
        if (i >= k) 
            cnt -= check(s[i - k]);
        }
        max_cnt = max(cnt, max_cnt);
    }
    ```
- 复杂度
    - 时间复杂度 O(N): 每个字符只需要遍历两次
    - 空间复杂度 O(1): 只使用了几个变量和常数空间的集合
