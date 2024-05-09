#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int V, vector<vector<int>> adj[],vector<pair<int,int>> &mst)
	{
		priority_queue<pair<int,pair<int, int>>,
		               vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq;

		vector<int> vis(V, 0);
		// {wt, node}
		pq.push({0,{0, -1}});
		int sum = 0;
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
            int parent=it.second.second;
			int node = it.second.first;
			int wt = it.first;

			if (vis[node] == 1) continue;
            if(parent!=-1) mst.push_back({parent,node});
			vis[node] = 1;
			sum += wt;
			for (auto it : adj[node]) {
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					pq.push({edW,{adjNode, node}});
				}
			}
		}
		return sum;
	}
};


int main() {

	int V = 5;
	vector<vector<int>> edges = {{0, 1, 4}, {0, 2, 1}, {1, 2, 2}, {1, 3, 5}, {2, 3, 2}, {2, 4, 1},{3, 4, 3},{4, 5, 2}};
	vector<vector<int>> adj[V];
    vector<pair<int,int>> mst;
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	Solution obj;
	int sum = obj.spanningTree(V, adj,mst);
	cout << "The sum of all the edge weights: " << sum << endl;
    cout<<"The edges of the minimum spanning tree are: ";
    for(auto it:mst){
        cout<<it.first<<" "<<it.second<<endl;
    }

	return 0;
}