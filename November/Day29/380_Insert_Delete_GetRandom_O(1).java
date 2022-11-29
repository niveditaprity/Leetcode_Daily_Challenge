class RandomizedSet {
    List<Integer> ls = new ArrayList<>();
    HashMap<Integer,Integer> map = new HashMap<>();
    public RandomizedSet() {
        
    }
    
    public boolean insert(int val) {
        if(map.containsKey(val))return false;
        map.put(val,ls.size());
        ls.add(val);
        return true;
    }
    
    public boolean remove(int val) {
        if(!map.containsKey(val))return false;
        
        int index= map.get(val);
        int lastel= ls.get(ls.size()-1);
        ls.set(index,lastel);
        map.put(lastel,index);
        map.remove(val);
        ls.remove(ls.size()-1);
        return true;
    }
    
    public int getRandom() {
        int randomIdx = (int) (Math.random() * ls.size());
        return ls.get(randomIdx);
        
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
