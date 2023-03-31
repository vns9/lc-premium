// https://leetcode.com/problems/design-hit-counter/description/

class HitCounter {
public:
    vector<int> v1;
    vector<int> v2;
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        if(v1.empty()){
            v1.push_back(timestamp);
            v2.push_back(1);
        }
        else{
            if(timestamp>v1.back()){
                v1.push_back(timestamp);
                v2.push_back(v2.back()+1);
            }
            else{
                int tmp = v2.back();
                v2.pop_back();
                v2.push_back(tmp+1);
            }
        }
    }
    
    int getHits(int timestamp) {
        // less than or equal to 
        int lo = 0;
        int hi = v1.size()-1;
        int idx1 = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(v1[mid]>timestamp){
                hi = mid-1;
            }
            else{
                idx1 = mid;
                lo = mid+1;
            }
        }
        // less than or equal to
        lo = 0;
        hi = v1.size()-1;
        int idx2 = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(v1[mid]>(timestamp-300)){
                hi = mid-1;
            }
            else{
                idx2 = mid;
                lo = mid+1;
            }
        }
        int ans = 0;
        if(idx1>=0) ans = v2[idx1];
        if(idx2>=0) ans -= v2[idx2];
        return ans;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
