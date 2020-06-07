# Leetcode-Weekly-Contest
Weekly Contest Problems on Leetcode 

### reorder-routes-to-make-all-paths-lead-to-the-city-zero

- [题目](https://leetcode-cn.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/)
- 思路
    - n 个城市，n-1 条路，路线网形成一颗树，建议连通表
    - 实际上就是以 0 为根节点的树，往下联通时(BFS或DFS)，捋一遍方向
- C++
    - 用下标访问vector时要检查是否以及开辟了空间
        - `edge.resize(n);`

### probability-of-a-two-boxes-having-the-same-number-of-distinct-balls
- [题目](https://leetcode-cn.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/)
