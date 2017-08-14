public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        
        
        HashMap<String, List<Integer>> map = new HashMap<String, List<Integer>>();
        List<List<String>> result = new ArrayList<List<String>>();
        
        for(int index = 0; index < strs.length; index++) {
            
            String checkStr = new String(strs[index]);
            char [] chars = checkStr.toCharArray();
            Arrays.sort(chars);
            checkStr = new String(chars);
            
            // sort(checkStr);
            
            if(!map.containsKey(checkStr)) {
                
                map.put(checkStr, new ArrayList<Integer>());
            }
            
            map.get(checkStr).add(index);
        }
        
        for(List<Integer> list : map.values()) {
            
            List<String> entries = new ArrayList<String>();
            
            for(int i : list) {
                entries.add(strs[i]);
            }
            
            result.add(entries);
        }
        
        return result;
    }
}