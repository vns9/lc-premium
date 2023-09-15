/*
// Definition for an Interval.
class Interval {
    public int start;
    public int end;

    public Interval() {}

    public Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
    public List<Interval> employeeFreeTime(List<List<Interval>> schedule) {
        List<Interval> answer = new ArrayList<>();
        HashMap<Integer, Integer> mp1 = new HashMap<>();
        HashMap<Integer, Integer> mp2 = new HashMap<>();
        Set<Integer> sett = new TreeSet<>();
        int n = schedule.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<schedule.get(i).size();j++){
                int current_start = schedule.get(i).get(j).start;
                int current_end = schedule.get(i).get(j).end;
                if(!mp1.containsKey(current_start)){
                    mp1.put(current_start, 0);
                }
                if(!mp2.containsKey(current_end)){
                    mp2.put(current_end, 0);
                }
                mp1.put(current_start, mp1.get(current_start)+1);
                mp2.put(current_end, mp2.get(current_end)+1);
                sett.add(current_start);
                sett.add(current_end);
            }
        }   
        // System.out.println(mp);
        int previous_zero = Integer.MIN_VALUE;
        int currentCnt = 0;
        for(int time: sett){
            int prev = currentCnt;

            if(mp1.containsKey(time)){
                currentCnt += mp1.get(time);
            }
            if(mp2.containsKey(time)){
                currentCnt -= mp2.get(time);
            }
            
            if(currentCnt!=0 && prev==0){
                if(previous_zero != Integer.MIN_VALUE) answer.add(new Interval(previous_zero, time));
            }

            if(currentCnt==0 && prev!=0){
                previous_zero = time;
            }
        } 
        return answer;
    }
}
