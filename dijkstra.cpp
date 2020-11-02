


void dijkstra(int s, vector<int> &d) {
	d = vector<int>(n, INF);
	d[s] = 0;
	set<pair<int, int>> st;
	st.insert({d[s], s});
	while (!st.empty()) {
		int v = st.begin()->second;
		st.erase(st.begin());
		for (auto [to, w] : g[v]) {
			if (d[to] > d[v] + w) {
				auto it = st.find({d[to], to});
				if (it != st.end()) st.erase(it);
				d[to] = d[v] + w;
				st.insert({d[to], to});
			}
		}
	}
}
