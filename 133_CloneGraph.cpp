#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
unordered_map<Node*, Node*> m;

Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        
        Node* head = new Node(node->val);
        m[node] = head;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* copy = q.front();
            q.pop();

            for(int i=0; i<copy->neighbors.size(); i++){
                Node* nb = copy->neighbors[i];
                if(m.find(nb) == m.end()){
                    m[nb] = new Node(nb->val);
                    q.push(nb);
                }
                m[copy]->neighbors.push_back(m[nb]);
            }
        }
        return head;
    }