public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        
        List<Integer> list = new ArrayList<Integer>();
        
        if(matrix.length == 0) return list;
        
        int colBeg = 0, rowBeg = 0,
            colEnd = matrix[0].length - 1,
            rowEnd = matrix.length - 1,
            step = 0;
        
        while(colBeg <= colEnd && rowBeg <= rowEnd) {
            
            //Right
            if(step == 0) {
                
                for(int index = colBeg; index < colEnd + 1; index++) {
                    
                    list.add(matrix[rowBeg][index]);
                }
                
                ++rowBeg;
                step = 1;
            }
            
            //Down
            if(step == 1) {
                
                for(int index = rowBeg; index < rowEnd + 1; index++) {
                    
                    list.add(matrix[index][colEnd]);
                }
                
                --colEnd;
                step = 2;
            }
            
            if(rowBeg <= rowEnd) {
            //Left
            if(step == 2) {
                
                for(int index = colEnd; index >= colBeg; index--) {
                    
                    list.add(matrix[rowEnd][index]);
                }
                
                --rowEnd;
                step = 3;
            }
            }
            
            if(colBeg <= colEnd) {
            //Up
            if(step == 3) {
                
                for(int index = rowEnd; index >= rowBeg; index--) {
                    
                    list.add(matrix[index][colBeg]);
                }
                
                ++colBeg;
                step = 0;
            }
            }
        }
        
        return list;
    }
}