/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        
        List<Interval> result = new LinkedList<Interval>();
        
        if(intervals.size() == 0) {
            
            return result;
        }
        
        Collections.sort(intervals, (left, right) -> Integer.compare(left.start, right.start));
        
        /*new Comparator<Interval>() {
            
           @Override
           public int compare(Interval left, Interval right) {
               
               return left.start - right.start;
           }
        });*/
        
        int start = intervals.get(0).start;
        int end = intervals.get(0).end;
        
        for(Interval interval : intervals) {
            
            if(interval.start <= end) {
                
                end = Math.max(end, interval.end);
            }
            else {
                
                result.add(new Interval(start, end));
                
                start = interval.start;
                end = interval.end;
            }
        }
        
        result.add(new Interval(start, end));
        
        return result;
    }
}