public class RandomizedSet {

    /** Initialize your data structure here. */
    public RandomizedSet() {
        
        map = new HashMap<Integer, Integer>();
        indices = new ArrayList<Integer>();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        
        if(map.containsKey(val)) {
            return false;
        }
        
        map.put(val, indices.size());
        indices.add(val);
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        
        if(!map.containsKey(val)) {
            return false;
        }
        
        int index = map.get(val);
        int currentLastValue = indices.get(indices.size() - 1);
        
        indices.set(index, currentLastValue);
        map.put(currentLastValue, index);
        
        map.remove(val);
        indices.remove(indices.size() - 1);
        
        return true;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        
        return indices.get(new Random().nextInt(indices.size()));
    }
    
    HashMap<Integer, Integer> map;
    List<Integer> indices;
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */