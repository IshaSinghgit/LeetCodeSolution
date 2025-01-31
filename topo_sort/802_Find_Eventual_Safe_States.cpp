// 2022.07.20
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseg(n);
        vector<int> d(n, 0);
        for(int i = 0; i < n; i++) {
            for(auto u : graph[i]) {
                reverseg[u].emplace_back(i);
                d[i]++;
            }
        }
        queue<int> que;
        for(int i = 0; i < n; i++) {
            if(!d[i]) {
                que.push(i);
            }
        }
        vector<int> res;
        while(!que.empty()) {
            int cur = que.front();
            que.pop();
            for(int i = 0; i < reverseg[cur].size(); i++) {
                d[reverseg[cur][i]]--;
                if(d[reverseg[cur][i]] == 0) {
                    que.push(reverseg[cur][i]);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(d[i] == 0) {
                res.emplace_back(i);
            }
        }
        return res;
    }
};

// 2022.07.21
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseg(n);
        vector<int> d(n);
        for(int i = 0; i < n; i++) {
            for(auto u : graph[i]) {
                reverseg[u].emplace_back(i);
                d[i]++;
            }
        }
        queue<int> que;
        for(int i = 0; i < n; i++) {
            if(d[i] == 0) {
                que.push(i);
            }
        }
        while(!que.empty()) {
            int cur = que.front();
            que.pop();
            for(int i = 0; i < reverseg[cur].size(); i++) {
                d[reverseg[cur][i]]--;
                if(d[reverseg[cur][i]] == 0) {
                    que.push(reverseg[cur][i]);
                }
            }
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(d[i] == 0) {
                res.emplace_back(i);
            }
        }
        return res;
    }
};

// 2022.07.27
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseg(n);
        vector<int> d(n, 0);
        queue<int> que;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            for(auto u : graph[i]) {
                reverseg[u].emplace_back(i);
                d[i]++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(d[i] == 0) {
                que.push(i);
            }
        }
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            for(auto v : reverseg[u]) {
                d[v]--;
                if(d[v] == 0) {
                    que.push(v);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(d[i] == 0) {
                res.emplace_back(i);
            }
        }
        return res;
    }
};

// 2022.09.29
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rg(n);
        vector<int> in(n, 0);
        queue<int> que;
        for(int i = 0; i < n; i++) {
            for(auto& u : graph[i]) {
                rg[u].emplace_back(i);
                in[i]++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(in[i] == 0) {
                que.push(i);
            }
        }
        vector<int> res;
        while(!que.empty()) {
            int cur = que.front();
            que.pop();
            res.emplace_back(cur);
            for(auto& u : rg[cur]) {
                in[u]--;
                if(in[u] == 0) {
                    que.push(u);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};