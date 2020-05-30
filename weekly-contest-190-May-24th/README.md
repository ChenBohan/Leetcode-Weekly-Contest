# Leetcode-Weekly-Contest
Weekly Contest Problems on Leetcode 

### check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence

- [题目](https://leetcode-cn.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/)
- 思路
    - 遍历数组, 检查当前字符串的前缀是目标字符串即可
- 复杂度
    - 时间复杂度 O(NM): N 表示单词个数, M 表示搜索字符串长度, 对于每个单词需要匹配一遍搜索字符串, 所以复杂度是 O(NM)
    - 空间复杂度 O(1) 或 O(N): 如果利用 split 转成字符串列表就是 O(N), 如果直接对字符串本身进行处理就是 O(1). O(1)空间的做法, 就是碰到空格后重置下标即可

### maximum-number-of-vowels-in-a-substring-of-given-length

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

### pseudo-palindromic-paths-in-a-binary-tree

- [题目](https://leetcode-cn.com/problems/pseudo-palindromic-paths-in-a-binary-tree/)
- 思路
    - 根据回文序列性质, 其中的每个字符的个数是有要求的, 最多只能有 1 个字符是奇数个(放在最中间), 其他字符都必须是偶数个。
    - 利用这一点, 我们可以 dfs 遍历, 然后遍历过程中维护一个计数字典, key 是节点值, value 是对应的个数
    - 然后遍历到叶子节点时, 统计当前计数字典是否满足回文序列的要求即可
    ```cpp
    function<void(TreeNode*)> dfs = [&](TreeNode* root) {
        if (!root){
            return;
        }
        addToSet(root->val);
        if (root->left || root->right) {
            dfs(root->left);
            dfs(root->right);
        } else {
            cout<<"leaf";
            print(oddsets);
            if (oddsets.size() <= 1) {
                cnt++;
            }
        }
        // remove cuurent leaf node from oddsets
        addToSet(root->val);
    };
    ```
- 优化
    - 可以额外增加一个变量 oddcnt 代表计数字典中数目为奇数的元素个数, 加速运算, 不需要每次在叶子节点处遍历所有计数字典统计奇数数目 key 的个数了
    - 进一步优化: 可以将上面的计数字典和 oddcnt 转换成一个集合, 只存数目为奇数的元素即可, 然后每次该元素数目变化时, 就根据其新的个数将其从集合移入或移除
- 复杂度
    - 时间复杂度 O(N): 每个节点只需要遍历一遍
    - 空间复杂度 O(N): 递归的栈的消耗, 集合只使用了常数个元素, 因为节点的值是 1~9
- C++
    - `unordered_set`的增删改查
        ```cpp
        auto addToSet = [&oddsets](int val) {
            if (oddsets.find(val) == oddsets.end()) {
                oddsets.insert(val);
            } else {
                oddsets.erase(val);
            }
        };
        ```
        
