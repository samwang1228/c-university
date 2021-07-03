#include<iostream>
#include<string.h>
#include<sstream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
// 題目:
// 讓Iterator多一個Peek()功能此功能會回傳next但是指針位置不會指向next
// 也就是指針位置不改變
// 目前還看不懂copy constructor

 // Below is the interface for Iterator, which is already defined for you.
 // **DO NOT** modify the interface for Iterator.
//原始解法
//將Iterator::next(),hasNext()存起來
class Iterator {
    friend class PeekingIterator_1;
    friend class PeekingIterator;
    struct Data;
    Data* data;
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};
class PeekingIterator_1 : public Iterator {
private:
    int m_next;
    bool m_hasnext;
public:
	PeekingIterator_1(const vector<int>& nums) : Iterator(nums) {
	    m_hasnext = Iterator::hasNext();
	    if (m_hasnext) m_next = Iterator::next();
	}

	int peek() {//因為Peek()指針Iterator位置不變所以回傳值就好
        return m_next;
	}

	int next() {
	    int t = m_next;//先把原本的next()存起來
	    m_hasnext = Iterator::hasNext();//查看是否有下一個
	    if (m_hasnext) m_next = Iterator::next();//如果有指針指向下一個
	    return t;
	}

	bool hasNext() const {
	    return m_hasnext;
	}
};

//使用copy constructor看不懂
// class Iterator {
//     friend class PeekingIterator;
//     struct Data;
//     Data* data;
//     Iterator(const vector<int>& nums);
//     Iterator(const Iterator& iter);

//     // Returns the next element in the iteration.
//     int next();

//     // Returns true if the iteration has more elements.
//     bool hasNext() const;
// };
 

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return Iterator(*this).next();
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    return Iterator::next();
	}
	
	bool hasNext() const {
	    return Iterator::hasNext();
	}
};