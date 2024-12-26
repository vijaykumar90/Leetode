/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<NestedInteger> res; // Stack to store elements for traversal

public:
    // Constructor
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Push all elements of the nested list onto the stack in reverse order
        for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it) {
            res.push(*it);
        }
    }
    
    // Retrieve the next integer
    int next() {
        // Assumes hasNext() has already been called and is true
        NestedInteger top = res.top(); // Get the top element
        res.pop(); // Remove it from the stack
        return top.getInteger(); // Return the integer value
    }
    
    // Check if there are more integers
    bool hasNext() {
        while (!res.empty()) {
            NestedInteger top = res.top(); // Peek at the top element
            if (top.isInteger()) {
                return true; // Found an integer, so return true
            }
            // If it's a list, process it
            res.pop(); // Remove the nested list from the stack
            const vector<NestedInteger> &nestedList = top.getList(); // Get the list content
            // Push the elements of the list onto the stack in reverse order
            for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it) {
                res.push(*it);
            }
        }
        return false; // No more integers
    }
};


/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
