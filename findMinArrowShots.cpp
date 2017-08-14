
/*
CORRECT SEQ

	   	 [6,			7]]
	[3,					    9]
		 [6,				9]
[1,						      10],
	  [4,				 	     11],
	  		[8,						12]

						    [9,     12],,,,



MY SORTED SEQ

[1,						      10],   <--- Arrow at 10 might miss [6, 7] but since 6 < 7 my code considers it as a hit
	[3,					    9]
	  [4,				 	     11],
	   	 [6,			7]]
		 [6,				9]
	  		[8,						12]

						    [9,     12],,,,
*/


class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        
        if(points.size() == 0) return 0;
        
        sort(points.begin(), points.end(),
            [](pair<int, int>& left, pair<int, int>& right) {
                
                return left.second == right.second 
                    ? left.first < right.first
                        : left.second < right.second;
                
                /*left.first < right.first ||
                    (left.first == right.first && left.second < right.second);*/
            });
            
            
        int noOfArrows = 1;
        int lastArrow = points[0].second;
        
        for(int ball = 1; ball < points.size(); ball++) {
            
            if(points[ball].first > lastArrow) {
                
                //cout << " lastArrow: " << lastArrow << " missed: " << points[ball].first << endl;
                lastArrow = points[ball].second;
                ++noOfArrows;
            }
        }
        
        return noOfArrows;
    }
};



