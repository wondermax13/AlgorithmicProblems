
#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click);

int main(void) {

	vector<vector<char>> board = {{'E', 'E', 'E', 'E', 'E'},
								  {'E', 'E', 'M', 'E', 'E'},
								  {'E', 'E', 'E', 'E', 'E'},
								  {'E', 'E', 'E', 'E', 'E'}};

	vector<int> click = {3, 0};

	updateBoard(board, click);

	return 0;
}

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        bool finish = false;
        
        int rows = board.size();
        int cols = board[0].size();
        
        stack<pair<int, int>> s;
        
        s.push(make_pair<>(click[0], click[1]));
        
        while(!s.empty() && !finish) {
            
            pair<int, int> top = s.top();
            s.pop();
            
            int row = top.first;
            int col = top.second;

            cout << " row: " << row << " col: " << col << endl;
            
            if(board[row][col] == 'E') { //Not 'B' since that has been tested
                
                int mineCount = 0;
                
                vector<pair<int, int>> neighbours;
                
                if(row - 1 >= 0) {
                	cout << " row - 1 " << endl;
                    neighbours.push_back(make_pair<>(row - 1, col));
                }
                if(row + 1 < rows) {
                	cout << " row + 1 " << endl;
                    neighbours.push_back(make_pair<>(row + 1, col));
                }
                if(col - 1 >= 0) {
                	cout << " col - 1 " << endl;
                    neighbours.push_back(make_pair<>(row, col - 1));
                }
                if(col + 1 < cols) {
                    neighbours.push_back(make_pair<>(row, col + 1));
                }
                if(row - 1 >= 0 && col - 1 >= 0) {
                    neighbours.push_back(make_pair<>(row - 1, col - 1));
                }
                if(row - 1 >= 0 && col + 1 < cols) {
                    neighbours.push_back(make_pair<>(row - 1, col + 1));
                }
                if(row + 1 < rows && col - 1 >= 0) {
                    neighbours.push_back(make_pair<>(row + 1, col - 1));
                }
                if(row + 1 < rows && col + 1 < cols) {
                    neighbours.push_back(make_pair<>(row + 1, col + 1));
                }
                
                int minCount = 0;
                for(auto p : neighbours) {
                    
                    if(board[p.first][p.second] == 'M') {
                        
                        minCount++;
                    }
                }
                
                if(minCount == 0) {
                    
                    board[row][col] = 'B';
                    for(auto p : neighbours) {
                        
                        if(board[p.first][p.second] ==  'E') {
                        	s.push(p);
                    	}
                    }
                }
                else {
                    
                    board[row][col] = '0' + minCount;
                }
            }
            else if(board[row][col] == 'M') {
                
                board[row][col] = 'X';
                finish = true;
            }
        }
        
        return board;
    }