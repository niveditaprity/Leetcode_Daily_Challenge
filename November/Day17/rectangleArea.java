class Solution {
    public int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
         int x_overlap, y_overlap;
        int overlap = 0;

        int Area1 = (ax2-ax1)*(ay2-ay1);
        int Area2 = (bx2-bx1) * (by2-by1);

        x_overlap = Math.min(ax2,bx2)-Math.max(ax1,bx1);
        y_overlap = Math.min(ay2,by2) - Math.max(ay1,by1);

        if(x_overlap > 0 && y_overlap > 0) 
        overlap = x_overlap * y_overlap;

        return Area1+Area2-overlap;
    }
}