
#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

    void recurseWords(
        string& bW, string endWord,
        int& minCount, int& count,
        bool changed[],
        string beginWord, vector<string>& wordList) {

        cout << " bW: " << bW << endl;
        
        if(bW == beginWord || find(wordList.begin(), wordList.end(), bW) != wordList.end()) {
        
            if(bW == endWord) {
            
                cout << " found count: " << count << endl;
                minCount = min(minCount, count);
                cout << " found minCount: " << minCount << endl;
            }
            else {
                
                for(int i = 0; i < bW.size(); i++) {
                    
                    cout << "checking i: " << i << " for: " << bW << endl;
                    if(!changed[i]) {
                        
                        changed[i] = true;
                        ++count;

                        cout << " changed i: " << i << " count: " << count << endl;
                        
                        bW[i] = endWord[i];

                        cout << " recursing for: " << bW << endl;
                        recurseWords(bW, endWord, minCount, count, changed, beginWord, wordList);
                        bW[i] = beginWord[i];
                        
                        changed[i] = false;
                        --count;
                    }
                }
            }
        }
        else {

            cout << "Not found: " << bW << endl;
        }            
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        if(beginWord.size() != endWord.size()
            || find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
                
                return 0;
        }
        
        string bW(beginWord);
        int count = 0, minCount = INT_MAX;
        bool changed[beginWord.size()] ;
        
        for(int i = 0; i < beginWord.size(); i++) {
            
            changed[i] = false;
        }
        
        recurseWords(bW, endWord, minCount, count, changed, beginWord, wordList);
        
        
        return minCount == INT_MAX ? 0 : minCount;
    }
    
int main(void) {
    
    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};


    int ll = ladderLength(beginWord, endWord, wordList);

    cout << " ll: " << ll << endl;

    return 0;
}