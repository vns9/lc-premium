class Solution {
    public class Point{
        int x;
        int y;
        Point(int x_, int y_){
            x = x_;
            y = y_;
        } 
    }
    public int minArea(char[][] image, int x, int y) {
        int rows = image.length;
        int cols = image[0].length;
        int minx = x;
        int maxx = x;
        int miny = y;
        int maxy = y;
        Queue<Point> q = new LinkedList<Point>();
        q.add(new Point(x, y));
        while(!q.isEmpty()){
            Point qtop = q.poll();
            int cx = qtop.x;
            int cy = qtop.y;
            image[cx][cy] = '0';
            maxx = Math.max(maxx, cx);
            minx = Math.min(minx, cx);
            maxy = Math.max(maxy, cy);
            miny = Math.min(miny, cy);
            if((cx+1 < rows) && (image[cx+1][cy]=='1')){
                image[cx+1][cy] = '0';
                q.add(new Point(cx+1, cy));
            }
            if((cx-1 >= 0)  && (image[cx-1][cy]=='1')){
                image[cx-1][cy] = '0';
                q.add(new Point(cx-1, cy));
            }
            if((cy+1 < cols) && (image[cx][cy+1]=='1')){
                image[cx][cy+1]='0';
                q.add(new Point(cx, cy+1));
            }
            if((cy-1 >= 0) && (image[cx][cy-1]=='1')){
                image[cx][cy-1]='0';
                q.add(new Point(cx, cy-1));
            }
        }
        return (1+maxx-minx)*(1+maxy-miny);

    }
}
