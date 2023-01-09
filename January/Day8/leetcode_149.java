class Solution {
    public int maxPoints(int[][] points) {
        int max=10001;
        int count=0;
        for(int i=0;i<points.length;i++){
            HashMap<Double,Integer> map= new HashMap<>();
            for(int j=i+1;j<points.length;j++){
                if(points[i][0]==points[j][0])map.put(10001.0,map.getOrDefault(10001.0,0)+1);
                else {
                    double slope= (points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                    if(slope==-0.0)slope=0.0;

                    map.put(slope,map.getOrDefault(slope,0)+1);
                    System.out.println(slope);
                }
            }
            for(Map.Entry<Double,Integer> mapElement : map.entrySet()) {
            count=Math.max(count,mapElement.getValue()+1);
            }

        }
        return count==0?1:count;
        
    }
}
