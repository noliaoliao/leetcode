struct UndirectedGraphNode   
{  
    int label;  
    vector<UndirectedGraphNode *> neighbors;  
    UndirectedGraphNode(int x) : label(x) {};  
};  
  
class Solution   
{  
public:  
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)   
    {  
        unordered_map<int, UndirectedGraphNode *> track;  
        return cloneGraph(node, track);  
    }  
  
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *> &track){  
        if (!node) return NULL;  
        if (track.count(node->label)) return track[node->label];  //已经访问过了,直接返回邻居
  
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);  
        new_node->neighbors.resize(node->neighbors.size());  
        track[node->label] = new_node;  
        
        //深度拷贝
        for (int i = 0; i < node->neighbors.size(); i++){  
            new_node->neighbors[i] = cloneGraph(node->neighbors[i], track);  
        }
        
        return new_node;  
    }  
};  