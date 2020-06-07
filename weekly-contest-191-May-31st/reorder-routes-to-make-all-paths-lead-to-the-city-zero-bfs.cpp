class Solution {
public:
    struct Node {
        int next;
        int isReverse;
        Node(int n, int r) : next(n), isReverse(r) {}
    };
    vector<vector<Node>> edge;
    int bfs() {
        int ans = 0;
        vector<bool> visit(edge.size(), false);
        queue<int> que;
        que.push(0);
        while(!que.empty()) {
            auto curt = que.front();
            visit[curt] = true;
            que.pop();
            cout<<curt;
            for (const auto& node : edge[curt]) {
                if (visit[node.next]) {
                    continue;
                }
                ans += node.isReverse;
                que.push(node.next);
            }
            cout<<endl;
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        edge.resize(n);
        for (const auto& pair : connections) {
            edge[pair[0]].push_back(Node(pair[1], 1));
            edge[pair[1]].push_back(Node(pair[0], 0));
        }
        return bfs();
    }
};
