class Solution {
public:
    struct Node {
        int next;
        int isReverse;
        Node(int n, int r) : next(n), isReverse(r) {}
    };
    vector<vector<Node>> edge;
    int dfs(int curt, int prev) {
        int ans = 0;
        for (const auto& node : edge[curt]) {
            if (node.next == prev) {
                continue;
            }
            ans += node.isReverse;
            // cout<<"curt: "<<curt<<" next"<<node.next<<" "<<node.isReverse<<endl;
            ans += dfs(node.next, curt);
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        edge.resize(n);
        for (const auto& pair : connections) {
            edge[pair[0]].push_back(Node(pair[1], 1));
            edge[pair[1]].push_back(Node(pair[0], 0));
        }
        return dfs(0, -1);
    }
};
