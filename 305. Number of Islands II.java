class Solution {
    public class Point{
        int x;
        int y;
        Point(int x, int y){
            this.x = x;
            this.y = y;
        }
        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Point point = (Point) o;
            return x == point.x &&
                    y == point.y;
        }
        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
    }
    public Point getParent(Point p, HashMap<Point, Point> mp){
        if(mp.containsKey(p)){
            if(mp.get(p).equals(p)){
                return p;
            }
            else return getParent(mp.get(p), mp);
        }
        return null;
    }
    public Point merge(Point p1, Point p2, HashMap<Point, Point> parent, HashMap<Point, Integer> leg, HashSet<Point> parentSet){
        if(p1.equals(p2)) return p1;
        if(leg.get(p1) <= leg.get(p2)){
            parent.put(p1, p2);
            parentSet.remove(p1);
            if(leg.get(p1) == leg.get(p2)){
                leg.put(p2, leg.get(p1)+1);
            }
            return p2;
        }
        else{
            parentSet.remove(p2);
            parent.put(p2, p1);
            return p1;
        }
    }
    public List<Integer> numIslands2(int m, int n, int[][] positions) {
        ArrayList<Integer> answer = new ArrayList<>();
        int[][] grid = new int[m][n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                grid[i][j] = 0;
            }
        }
        HashMap<Point, Point> parent = new HashMap<>();
        HashMap<Point, Integer> legsize = new HashMap<>();
        HashSet<Point> parentSet = new HashSet<>();
        int posn = positions.length;
        for(int i=0; i<posn; i++){
            int currx = positions[i][0];
            int curry = positions[i][1];
            Point currpoint = new Point(currx, curry);
            if(grid[currx][curry] == 0){
                grid[currx][curry] = 1;
                ArrayList<Point> neighbours = new ArrayList<>();
                if((currx-1 >= 0) && (grid[currx-1][curry]==1)){
                    neighbours.add(new Point(currx-1, curry));
                }
                if((currx+1<m) && (grid[currx+1][curry]==1)){
                    neighbours.add(new Point(currx+1, curry));
                }
                if((curry-1 >= 0) && (grid[currx][curry-1]==1)){
                    neighbours.add(new Point(currx, curry-1));
                }
                if((curry+1<n) && (grid[currx][curry+1]==1)){
                    neighbours.add(new Point(currx, curry+1));
                }
                if(neighbours.isEmpty()){
                    parentSet.add(currpoint);
                    parent.put(currpoint, currpoint);
                    legsize.put(currpoint, 1);
                }
                else{
                    for(int j=0; j<(neighbours.size()-1); j++){
                        Point p1 = neighbours.get(j);
                        Point p2 = neighbours.get(j+1);
                        Point p1_par = getParent(p1, parent);
                        Point p2_par = getParent(p2, parent);
                        Point newParent = merge(p1_par, p2_par, parent, legsize, parentSet);
                        parent.put(currpoint, newParent);
                    }  
                    if(neighbours.size()==1){
                        Point newParent = neighbours.get(0);
                        parent.put(currpoint, newParent);
                    }
                    
                }
            }
            grid[positions[i][0]][positions[i][1]] = 1;
            answer.add(parentSet.size());
        }
        return answer;
    }
}
