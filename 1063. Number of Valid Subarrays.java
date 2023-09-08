class Solution {
    public int validSubarrays(int[] nums) {
        int answer = 0;
        int n = nums.length;
        int[] nsi = new int[n];
        for(int i=0; i<n; i++){
            nsi[i] = n;
        }
        Stack<Integer> s = new Stack<>();
        for(int i=0; i<n; i++){
            while(true){
                if(s.empty() || nums[s.peek()]<=nums[i]){
                    s.push(i);
                    break;
                }
                else{
                    nsi[s.peek()] = i;
                    s.pop();
                }
            }
        }
        for(int i=0; i<n; i++){
            answer += (nsi[i]-i);
        }
        return answer;
    }
}