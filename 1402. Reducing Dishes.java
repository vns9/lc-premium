class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        int current = 0;
        int add = 0;
        int n = satisfaction.length;
        Arrays.sort(satisfaction);
        for(int i=n-1; i>=0; i--){
            int newCurrent = (current+add)+satisfaction[i];
            if(newCurrent >= current){
                current = newCurrent;
                add += satisfaction[i];
            }
        }
        return current;
    }
}
