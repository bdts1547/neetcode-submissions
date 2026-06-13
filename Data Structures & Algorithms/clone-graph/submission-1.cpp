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
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> cloned;
        return dfs(node, cloned);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& cloned) {
        if (cloned.count(node)) {
            return cloned[node];
        }

        Node* newNode = new Node(node->val);
        cloned[node] = newNode;

        for (Node* item: node->neighbors) {
            newNode->neighbors.push_back(dfs(item, cloned));
        }
        
        return newNode;
    }

};














