class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> result;
        vector<vector<int>> graph(numCourses,vector<int>(0));
        vector<int> indegree(numCourses,0);

        //构造有向图、保存入度
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
            indegree[prerequisites[i].first]++;
        }

        //将入度为0的顶点压入队列
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        //检查队列中的每一个顶点
        while(q.empty() == false){
            int curr = q.front();
            result.push_back(curr);
            q.pop();
            for(int i = 0; i < graph[curr].size(); i++){
                indegree[graph[curr][i]]--;
                if(indegree[graph[curr][i]] == 0) q.push(graph[curr][i]);
            }
        }

        if(result.size() != numCourses){
            result.clear();
        }

        return result;
    }
};