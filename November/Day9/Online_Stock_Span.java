class StockSpanner {
    Stack<Pair<Integer,Integer>> st = new Stack<>();

    public StockSpanner() {
        
    }
    
    public int next(int price) {
        if(st.isEmpty()){
            st.push(new Pair(price,1));
            return 1;
        }
        int ans=1;
        while(!st.isEmpty() && st.peek().getKey()<=price){
            Pair<Integer,Integer> p=st.pop();
            ans+=p.getValue();
        }
        st.push(new Pair(price,ans));
        return ans;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
