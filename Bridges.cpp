int n; // number of nodes
vector<vector<int>> g; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low; // time when node is entered, low-link value to find backedge.
int timer; // timer it provides an unique id

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]); // Note : here minimum of low-link of node and time to enter a child.
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]); // Note: Here minimum of low link of node and child.
            if (low[to] > tin[v])     
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}
