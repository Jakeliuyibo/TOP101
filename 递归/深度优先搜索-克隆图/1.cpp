/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    unordered_map<Node* , Node*> history;

    /* 深度搜索拷贝节点     */
    void dfs(Node* node)
    {
        history[node] = new Node(node->val);
        for(auto next : node->neighbors)
        {
            if(!history[next])
            {
                dfs(next);
            }
        }
    }

    Node* cloneGraph(Node* node) 
    {
        /* 输入处理  */
        if(node == nullptr)   return node;

        /* 拷贝节点  */
        dfs(node);

        /* 拷贝边    */
        for(auto [from, to]: history)
        {
            for(auto neighbors: from->neighbors)
            {
                to->neighbors.push_back(history[neighbors]);
            }
        }

        return history[node];
    }



};