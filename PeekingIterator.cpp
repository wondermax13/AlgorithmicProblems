// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	    /*
	    length = nums.size();
	    //iter2 = nums.begin();
	    iBegin = nums.begin();
	    iEnd = nums.end();
	    */
	    
	    p_hasNext = Iterator::hasNext();
	    
	    if(p_hasNext) {
	        p_next = Iterator::next();
	    }
	    
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        
        return p_next;
        
        /*
        vector<int>::iterator iter2(iBegin);
        
        int res;
        int moves = 0;
        
        while(moves < length) {
            
            if(!hasNext()) {
                
                iter2 = iBegin;
            }
            
            int nextVal = next();
            
            ++moves;
            
            if(moves == 1) {
                
                res = nextVal;
            }
        }
        */
        
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    
	    int currNext = p_next; //Return the currNext
	    
	    p_hasNext = Iterator::hasNext(); //Store the new hasNext
	    
	    if(p_hasNext) {
	        
	        p_next = Iterator::next(); //Store the new next
	    }
	    
	    return currNext;
	    
	    
	    //return *iter2;
	}

	bool hasNext() const {
	    
	    return p_hasNext;
	    
	    //index != (length - 1);
	    
	    //iter2 != iEnd;
	}
	
	/*
	//Iterator iter;//, iBegin;
	int length;
	vector<int>::const_iterator iBegin, iEnd;
	int index = 0;
	*/
	
	int p_next;
	bool p_hasNext;
	
	
};