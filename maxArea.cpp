class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int size = height.size(), maxArea = 0;
        
        //Brute force
        /*for(int start = 0; start < size - 1; start++) {
            for(int end = start + 1; end < size; end++) {
                
                maxArea = max(maxArea, (end-start)*(min(height[start], height[end])));
            }
        }*/
        
        
        //Skip the entries where height lesser than previous
        int start = 0, end = size - 1;
        while(start < end) {
            
            int min_height_ = min(height[start], height[end]);
            
            maxArea = max(maxArea, (end-start)*(min_height_));
            
            while(height[start] <= min_height_) {
                ++start;
            }
            while(height[end] <= min_height_) {
                --end;
            }
        }
        
        
        
        return maxArea;
        
        /*int h[n + 1][n+1]; //1-n, 0 ignored
        
        h[2] = min(height[0], height[1]);
        
        int area = h[2]*(2-1);
        
        for(int index = 3; index <= n; index++) {
            
            h[index] = h[index - 1];
            
            if(height[index] < height[index - 1]) {
                
                if(h[index - 1]* (index - 1) < h[index]* (index)) {
                    h[index] = height[index-1];
                }
            }
        }*/
        
        //return h[n]*(n-1);
    }
};