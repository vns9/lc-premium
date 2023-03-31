// https://leetcode.com/problems/first-unique-number/description/

class FirstUnique {
public:
    set<int> s1;
    set<int> s2;
    queue<int> q;
    FirstUnique(vector<int>& nums) {
        for(auto el: nums){
            add(el);
        }
    }
    
    int showFirstUnique() {
        while(!q.empty()){
            if(s2.count(q.front())==1){
                q.pop();
            }
            else break;
        }
        if(q.empty()) return -1;
        return q.front();
    }
    
    void add(int value) {
        if(s1.count(value)==0){
            s1.insert(value);
            q.push(value);
        }
        else s2.insert(value);
    }  
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
