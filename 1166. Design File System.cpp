// https://leetcode.com/problems/design-file-system/description/

class FileSystem {
public:
    struct Node {
        string name;
        int val;
        vector<Node*> neib;
        Node (string name, int val, vector<Node*> neib) : name(name), val(val), neib(neib) {}
    };
    Node* root = new Node(".",0,{});

    FileSystem() {
        
    }

    bool createPath(string path, int value) {
        vector<string> pathstr;
        string curr_ = "";
        for(auto c: path){
            if(c!='/'){
                curr_.push_back(c);
            }
            else{
                if(curr_=="") continue;
                pathstr.push_back(curr_);
                curr_ = "";
            }
        }
        if(curr_!=""){
            pathstr.push_back(curr_);
        }
        string lastNode = pathstr.back();
        pathstr.pop_back();
        Node* curr = root;
        int i = 0;
        while(i<pathstr.size()){
            bool found = false;
            for(auto neighbour: curr->neib){
                if(neighbour->name==pathstr[i]){
                    i++;
                    curr = neighbour;
                    found = true;
                    break;
                }
            }
            if(!found) return false;
        }
        for(auto neibs: curr->neib){
            if(neibs->name == lastNode) return false;
        }
        Node* newNode = new Node(lastNode, value, {});
        (curr->neib).push_back(newNode);
        return true;
    }
    
    int get(string path) {
        vector<string> pathstr;
        string curr_ = "";
        for(auto c: path){
            if(c!='/'){
                curr_.push_back(c);
            }
            else{
                if(curr_=="") continue;
                pathstr.push_back(curr_);
                curr_ = "";
            }
        }
        if(curr_!=""){
            pathstr.push_back(curr_);
        }
        Node* curr = root;
        int i = 0;
        while(i<pathstr.size()){
            bool found = false;
            for(auto neighbour: curr->neib){
                if(neighbour->name==pathstr[i]){
                    i++;
                    curr = neighbour;
                    found = true;
                    break;
                }
            }
            if(!found) return -1;
        }
        return curr->val;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
