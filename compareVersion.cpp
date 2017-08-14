class Solution {
public:
    int compareVersion(string version1, string version2) {
    
        bool mismatch = false;
        int start1 = 0;
        int start2 = 0;
        int num1 = 0;
        int num2 = 0;
        
        while((start1 != -1 || start2 != -1) && !mismatch) {
            
            num1 = getNextLevelRevision(version1, start1);
            num2 = getNextLevelRevision(version2, start2);
            
            mismatch = num1 != num2;
            
            cout << " num1: " << num1 << endl;
            cout << " num2: " << num2 << endl;
        }
        
        return num1 == num2 
            ? 0 : num1 < num2 
                ? -1 : 1;
    }
    
    int getNextLevelRevision(string version, int& start) {
        
        int num = 0;
        cout << start << " of " << version << endl;
        
        string nextVersion;
        
        int index = version.find('.', start);
        
        cout << " found . at" << index << " of " << version << endl;
        
        if(index != string::npos) {
            
            nextVersion = version.substr(start, index - start);
            start = index + 1;
            
            num = stoi(nextVersion);
        }
        else {
            
            if(start != -1 && start < version.size()) {
            
                nextVersion = version.substr(start);
                num = stoi(nextVersion);
            }
            start = -1;
        }
        
        return num;
    }
};