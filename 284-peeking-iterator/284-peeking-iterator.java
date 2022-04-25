// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html

class PeekingIterator implements Iterator<Integer> {
    Iterator<Integer> it;
    boolean isNext;
    int value;
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
	    it = iterator;
        isNext = false;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        if(isNext)
            return value;
        value = it.next();
        isNext = true;
        return value;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    if(isNext)
            isNext = false;
        else
            value = it.next();
        return value;
	}
	
	@Override
	public boolean hasNext() {
	    if(isNext)
            return true;
        return it.hasNext();
	}
}