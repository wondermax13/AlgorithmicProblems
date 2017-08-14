class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        size_t pos1, pos2;
        int compareValue = 0;

        string left1 = version1;
        string left2 = version2;
        string right1 = "";
        string right2 = "";
        
        int rightInt1 = 0;
        int rightInt2 = 0;
        
        pos1 = version1.find_first_of(".");
        pos2 = version2.find_first_of(".");
        
        if(pos1 != string::npos) {
            
            left1 = version1.substr(pos1-1);
            right1 = version1.substr(pos1+1);
        }
        
        if(pos2 != string::npos) {
            
            left2 = version2.substr(pos2-1);
            right2 = version2.substr(pos2+1);
        }

        int leftInt1 = stoi(left1);
        int leftInt2 = stoi(left2);
        
        if(leftInt1 < leftInt2) {
            compareValue =  -1;
        }
        if(leftInt1 > leftInt2) {
            compareValue =  1;
        }
        
        if(compareValue == 0) {
            
            if(!right1.empty()) {
                
                rightInt1 = stoi(right1);
            }
            if(!right2.empty()) {
                
                rightInt2 = stoi(right2);
            }
            
            if(rightInt1 == 0 && rightInt2 == 0) {
                
                return 0;
            }
            
            if(rightInt1 < rightInt2) {
                
                    compareValue =  -1;
            }
            if(rightInt2 < rightInt1) {
                
                    compareValue =  1;
            }

        }
        
        
        return compareValue;
    }
};



/*
    BETTER SOLUTION WITH INDEX

int compareVersion(string version1, string version2)
{
    int iLength1 = version1.size(), iLength2 = version2.size();
    string sVersion1, sVersion2;
    int iStart1 = 0, iStart2 = 0, iPoint1 = 0, iPoint2 = 0, iVersion1, iVersion2;
    while(iStart1 < iLength1 || iStart2 < iLength2)
    {
        if(iStart1 >= iLength1)
            iVersion1 = 0;
        else
        {
            iPoint1 = version1.find_first_of('.', iStart1);
            if(-1 == iPoint1)
                iPoint1 = iLength1;
            sVersion1.assign(version1, iStart1, iPoint1 - iStart1);
            iVersion1 = stoi(sVersion1);
        }
        if(iStart2 >= iLength2)
            iVersion2 = 0;
        else
        {
            iPoint2 = version2.find_first_of('.', iStart2);
            if(-1 == iPoint2)
                iPoint2 = iLength2;
            sVersion2.assign(version2, iStart2, iPoint2 - iStart2);
            iVersion2 = stoi(sVersion2);
        }
        if(iVersion1 > iVersion2)
            return 1;
        else if(iVersion1 < iVersion2)
            return -1;
        else
        {
            iStart1 = iPoint1 + 1;
            iStart2 = iPoint2 + 1;
        }
    }
    return 0;
}



*/





