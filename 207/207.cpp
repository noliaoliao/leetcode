class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses,vector<int>(0));
        vector<int> visited(numCourses,0);

        //构造有向图
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }

        //dfs每个顶点
        for(int i = 0; i < numCourses; i++){
            if(dfs(graph,visited,i) == false) return false;
        }

        return true;
    }

    bool dfs(vector<vector<int>> &graph, vector<int> &visited, int i){
        if(visited[i] == 1) return false;
        if(visited[i] == -1) return true;
        visited[i] = 1;
        for(int j = 0; j < graph[i].size(); j++){
            if(dfs(graph,visited,graph[i][j]) == false) return false;
        }
        visited[i] = -1;
        return true;
    }
};