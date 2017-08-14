public class Solution {
    public int[][] multiply(int[][] A, int[][] B) {
        
        int [][] result = new int[A.length][B[0].length];
        
        List<Integer> aRowEntries = new ArrayList<Integer>(),
                      bRowEntries = new ArrayList<Integer>(),
                      aColEntries = new ArrayList<Integer>(),
                      bColEntries = new ArrayList<Integer>();
        
        for(int aRow = 0; aRow < A.length; aRow++) {
            for(int aCol = 0; aCol < A[0].length; aCol++) {
            
            if(A[aRow][aCol] != 0) {
                
                aRowEntries.add(aRow);
                aColEntries.add(aCol);
            }
            }
        }
        
        for(int bRow = 0; bRow < B.length; bRow++) {
            for(int bCol = 0; bCol < B[0].length; bCol++) {
            
            if(B[bRow][bCol] != 0) {
                
                bRowEntries.add(bRow);
                bColEntries.add(bCol);
            }
            }
        }
        
        for(int aCol = 0; aCol < aColEntries.size(); aCol++) {
            for(int bRow = 0; bRow < bRowEntries.size(); bRow++) {
                
                if(aColEntries.get(aCol) == bRowEntries.get(bRow)) {
                    
                    result[aRowEntries.get(aCol)][bColEntries.get(bRow)] 
                    += A[aRowEntries.get(aCol)][aColEntries.get(aCol)] 
                    * B[bRowEntries.get(bRow)][bColEntries.get(bRow)];
                }
            }
        }
        
        return result;
    }
}
