class Solution {
    public int maximumBeauty(int[] flowers) {
        int n = flowers.length;
        int[] posflowers = new int[n];
        HashMap<Integer, ArrayList<Integer>> mp = new HashMap<>();
        for(int i=0; i<n; i++){
            posflowers[i] = 0;
            posflowers[i] = Math.max(posflowers[i], flowers[i]);
            if(i-1>=0){
                posflowers[i] += posflowers[i-1];
            }
            if(!mp.containsKey(flowers[i])){
                mp.put(flowers[i], new ArrayList<Integer>());
            }
            mp.get(flowers[i]).add(i);
        }
        int answer = Integer.MIN_VALUE;
        for(int key: mp.keySet()){
            if(mp.get(key).size()>=2){
                // .back() in C++ is <3 Ughhh
                int currsize = mp.get(key).size();
                int start = mp.get(key).get(0);
                int end = mp.get(key).get(currsize-1);      
                int currsum = 0;
                if(start+1 == end){
                    answer = Math.max(answer, 2*(flowers[start]));
                }
                currsum = posflowers[end-1];
                currsum -= posflowers[start];
                answer = Math.max(answer, currsum + 2*(flowers[start]));
            }
        }
        return answer;
    }
}