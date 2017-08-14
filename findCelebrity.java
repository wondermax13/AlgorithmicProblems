public class Solution extends Relation {
    public int findCelebrity(int n) {

        if(n <= 1) return n;

        int candidate = 0;

        for(int i = 1; i < n; i++) {
        	//Whatever entries have been missed till candidate = c1
        	//don't need to be checked again since there is only 1 celebrity
        	//and they are not celebrity since they have already failed the test
        	//If c1 found then check from c1+1 : n for test
        	if(!(knows(i, candidate) && !knows(candidate, i))) {
        		candidate = i;
        }
        for(int i = 0; i < candidate; i++) if(!(knows(i, candidate) && !knows(candidate, i))) return -1;
        return candidate;
    }
}