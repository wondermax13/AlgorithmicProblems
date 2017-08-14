
#include <algorithm>
#include <iostream>
#include <vector>


typedef std::vector<int> V;

void printGrid(std::vector<V> grid) {

	for(int row = 0; row < grid.size(); row++) {

		for(int col = 0; col < grid[0].size(); col++) {

			std::cout << " " << grid[row][col];
		}

		std::cout << "\n";
	}
	
}

void backTracking(std::vector<V>& grid, V& currPermute, int nums[]) {

	int length = sizeof(nums)/sizeof(nums[0]);

	if(currPermute.size() == length) {

		grid.push_back(currPermute);
	}

	else{

		for(int index = 0; index < length; index++) {

			//OR - used[index] = true
			if(std::find(
				currPermute.begin(),
				currPermute.end(),
				nums[index]) != currPermute.end()) {

				continue;
			}

			currPermute.push_back(nums[index]);
			backTracking(grid, currPermute, nums);
			currPermute.pop_back();
			//OR - used[index] = false

			//currPermute.erase(currPermute.begin(), currPermute.end());
		}
	}



}

int main(void) {
	
	std::vector<V> vec; // = {{1, 2, 3}, {4, 5, 6}};
	int nums[] = {2, 3, 4};

	V curr;

	backTracking(vec, curr, nums);

	printGrid(vec);

	return 0;
}

