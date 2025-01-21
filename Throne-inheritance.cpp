class ThroneInheritance {
    struct genTreeNode {
        string name;
        bool alive;
        vector<genTreeNode*> children;
        genTreeNode(string name) : name(name),alive(true) { }
    };
    genTreeNode* king;

    unordered_map<string,genTreeNode*> nameToNode;

public:
    ThroneInheritance(string kingName) {
        king= new genTreeNode(kingName);
        nameToNode[kingName]=king;
    }
    
    void birth(string parentName, string childName) {
        genTreeNode* newChild= new genTreeNode(childName);
        nameToNode[childName]=newChild;
        nameToNode[parentName]-> children.push_back(newChild);
    }
    
    void death(string name) {
        nameToNode[name]-> alive=false;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> inheritanceOrder;
        stack<genTreeNode*> s;
        s.push(king);

        while(!s.empty())
        {
            genTreeNode* curSuccessor= s.top();
            s.pop();

            if(curSuccessor-> alive)
            {
                inheritanceOrder.push_back(curSuccessor->name);
            }

            auto& children=curSuccessor->children;
            for(auto nextChild= children.rbegin(); nextChild!=children.rend();++nextChild)
            {
                s.push(*nextChild);
            }            
        }
        return inheritanceOrder;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */