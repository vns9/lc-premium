class Solution {
    public String nextPalindrome(String num) {
        int n = num.length();
        boolean odd = false;
        if(n%2 == 1){
            odd = true;
        }
        String half = "";
        for(int i=0; i<(n/2); i++){
            half += num.charAt(i);
        }
        int[] cnt = new int[10];
        for(int i=0; i<10; i++){
            cnt[i] = 0;
        }
        String nextHalf = "";
        for(int i = half.length()-1; i>=0; i--){
            int current = half.charAt(i)-'0';
            if(!nextHalf.isEmpty()){
                nextHalf += half.charAt(i);
                continue;
            }
            boolean found = false;
            for(int j=current+1; j<10; j++){
                if(cnt[j] > 0){
                    found = true;
                    cnt[current]++;
                    cnt[j]--;
                    for(int k=9; k>=0; k--){
                        for(int l=1; l<=cnt[k]; l++){
                            nextHalf += String.valueOf(k);
                        }
                    }
                    nextHalf += String.valueOf(j);
                    break;
                }
            }
            if(!found){
                cnt[current]++;
            }
        }
        if(nextHalf.isEmpty()){
            return "";
        }
        String tmp = "";
        for(int i=nextHalf.length()-1; i>=0; i--){
            tmp += nextHalf.charAt(i);
        }
        nextHalf = tmp;
        String reversed = "";
        for(int i=nextHalf.length()-1; i>=0; i--){
            reversed += nextHalf.charAt(i);
        }
        if(!odd) return nextHalf+reversed;
        return nextHalf+num.charAt((int) Math.floor(n*1.0/2))+reversed;
    }
}
