// https://leetcode.com/problems/dot-product-of-two-sparse-vectors/description/

class SparseVector {
public:
    vector<pair<int,int>> v;
    SparseVector(vector<int> &nums) {  
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                v.push_back({i, nums[i]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int p1 = 0;
        int p2 = 0;
        int ans = 0;
        while(p1<v.size() && p2<vec.v.size()){
            if(v[p1].first == vec.v[p2].first){
                ans += v[p1].second*vec.v[p2].second;
                p1++;p2++;
            }
            else if(v[p1].first < vec.v[p2].first){
                p1++;
            }
            else p2++;
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
