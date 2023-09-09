// Very SHORT question 

class Solution {
    public class Point{
        int x;
        int y;
        Point(int x_, int y_){
            x = x_;
            y = y_;
        }
    }
    public int minimumSeconds(List<List<String>> land) {
        int rows = land.size();
        int cols = land.get(0).size();
        int sx = 0;
        int sy = 0;
        int dx = 0;
        int dy = 0;
        int[][] floodTime = new int[rows][cols];
        int[][] minReachTime = new int[rows][cols];
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                floodTime[i][j] = Integer.MAX_VALUE;
                minReachTime[i][j] = Integer.MAX_VALUE;
            }
        }
        Queue<Point> q = new LinkedList<>();
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(land.get(i).get(j).equals("S")){
                    sx = i;
                    sy = j;
                }
                if(land.get(i).get(j).equals("D")){
                    dx = i;
                    dy = j;
                }
                if(land.get(i).get(j).equals("*")){
                    q.add(new Point(i, j));
                    floodTime[i][j] = 0;
                }
            }
        }
        int currentTime = 1;
        while(!q.isEmpty()){
            int qsize = q.size();
            for(int i=0; i<qsize; i++){
                Point currpoint = q.poll();
                int cx = currpoint.x;
                int cy = currpoint.y;
                if((cx+1<rows) && (!land.get(cx+1).get(cy).equals("X") && !land.get(cx+1).get(cy).equals("D")) && (floodTime[cx+1][cy]==Integer.MAX_VALUE)){
                    floodTime[cx+1][cy] = currentTime;
                    q.add(new Point(cx+1, cy));
                }
                if((cx-1>=0) && (!land.get(cx-1).get(cy).equals("X") && !land.get(cx-1).get(cy).equals("D")) && (floodTime[cx-1][cy]==Integer.MAX_VALUE)){
                    floodTime[cx-1][cy] = currentTime;
                    q.add(new Point(cx-1, cy));
                }
                if((cy+1<cols) && (!land.get(cx).get(cy+1).equals("X") && !land.get(cx).get(cy+1).equals("D")) && (floodTime[cx][cy+1]==Integer.MAX_VALUE)){
                    floodTime[cx][cy+1] = currentTime;
                    q.add(new Point(cx, cy+1));
                }
                if((cy-1>=0) && (!land.get(cx).get(cy-1).equals("X") && !land.get(cx).get(cy-1).equals("D")) && (floodTime[cx][cy-1]==Integer.MAX_VALUE)){
                    floodTime[cx][cy-1] = currentTime;
                    q.add(new Point(cx, cy-1));
                }
            }
            currentTime++;
        }
        q.clear();
        currentTime = 1;
        q.add(new Point(sx, sy));
        minReachTime[sx][sy] = 0;
        while(!q.isEmpty()){
            int qsize = q.size();
            for(int i=0; i<qsize; i++){
                Point qtop = q.poll();
                int cx = qtop.x;
                int cy = qtop.y;
                if((cx+1<rows) && (!land.get(cx+1).get(cy).equals("X")) && (minReachTime[cx+1][cy]==Integer.MAX_VALUE)){
                    if(currentTime < floodTime[cx+1][cy]){
                        minReachTime[cx+1][cy] = currentTime;
                        q.add(new Point(cx+1, cy));
                    }
                }
                if((cx-1>=0) && (!land.get(cx-1).get(cy).equals("X")) && (minReachTime[cx-1][cy]==Integer.MAX_VALUE)){
                    if(currentTime < floodTime[cx-1][cy]){
                        minReachTime[cx-1][cy] = currentTime;
                        q.add(new Point(cx-1, cy));
                    }
                }
                if((cy+1<cols) && (!land.get(cx).get(cy+1).equals("X")) && (minReachTime[cx][cy+1]==Integer.MAX_VALUE)){
                    if(currentTime < floodTime[cx][cy+1]){
                        minReachTime[cx][cy+1] = currentTime;
                        q.add(new Point(cx, cy+1));
                    }
                }
                if((cy-1>=0) && (!land.get(cx).get(cy-1).equals("X")) && (minReachTime[cx][cy-1]==Integer.MAX_VALUE)){
                    if(currentTime < floodTime[cx][cy-1]){
                        minReachTime[cx][cy-1] = currentTime;
                        q.add(new Point(cx, cy-1));
                    }
                }
            }
            currentTime++;
        }
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                System.out.print(floodTime[i][j]+" ");
            }
            System.out.println();
        }
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                System.out.print(minReachTime[i][j]+" ");
            }
            System.out.println();
        }
        if(minReachTime[dx][dy] == Integer.MAX_VALUE) return -1;
        return minReachTime[dx][dy];
    }
}
