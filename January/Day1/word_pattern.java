
class Solution {
    public boolean wordPattern(String pattern, String s) {
        HashMap<Character,String> map = new HashMap<>();

        String[] str = s.split(" ");

        if(str.length!=pattern.length())
            return false;

        for(int i=0;i<pattern.length();i++)
        {
              
            char ch = pattern.charAt(i);

            if(map.containsKey(ch)){
                if(!map.get(ch).equals(str[i])){
                    return false;
                }
                    
            }
            else
            { 
              if(map.containsValue(str[i]))
                return false;
              map.put(ch,str[i]);
            }
          

        }
       
        return true;

    }
}
