class Solution {
    public int minTotalDistance(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int xsum = 0;
        int ysum = 0;
        int xmin = Integer.MAX_VALUE;
        int ymin = Integer.MAX_VALUE;
        int[] xdis = new int[cols];
        int[] ydis = new int[rows];
        for(int i=0; i<cols; i++){
            xdis[i] = 0;
        }
        for(int i=0; i<rows; i++){
            ydis[i] = 0;
        }
        ArrayList<Integer> xf = new ArrayList<>();
        ArrayList<Integer> yf = new ArrayList<>();
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1){
                    xsum += j;
                    ysum += i;
                    xf.add(j);
                    yf.add(i);
                }
            }
        }
        Collections.sort(xf);
        Collections.sort(yf);
        int xfs = xf.size();
        int px = -1;
        int currxsum = 0;
        for(int i=0; i<cols; i++){
            while(((px+1) < xfs) && (xf.get(px+1)<=i)){
                px++;
                currxsum += xf.get(px);
            }
            xdis[i] = (i)*(px+1) - currxsum;
            xdis[i] += (xsum - currxsum - (xfs-px-1)*(i));
            xmin = Math.min(xmin, xdis[i]);
        }
        int yfs = yf.size();
        int py = -1;
        int currysum = 0;
        for(int i=0; i<rows; i++){
            while(((py+1) < yfs) && (yf.get(py+1)<=i)){
                py++;
                currysum += yf.get(py);
            }
            ydis[i] = (i)*(py+1) - currysum;
            ydis[i] += (ysum - currysum - (yfs-py-1)*(i));
            ymin = Math.min(ymin, ydis[i]);
        }
        return xmin+ymin;
    }
}
