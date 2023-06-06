#pragma once

#include <iostream>
#include <list>
#include <exception>
using namespace std;

template <typename T>
class PriorityQueue {
   
public:
	
	void push(const T& t); 
	T poll();

private:
	std::list<T> lst;

	/**
	* MyComparator struct defines a custom comparison for elements of type T.
	* The operator() function returns true if t1 has higher priority than t2.
	*/
	struct MyComparator
	{
		bool operator()(const T& t1, const T& t2) const 
			/**
			 * Compares two elements of type T.
			 * @param t1 The first element.
			 * @param t2 The second element.
			 * @return True if t1 has higher priority than t2, false otherwise.
			 */ 
		{
			T d = t2 - t1; // the delta between two parms
			return (d<0); 
		}
	};
};


template<typename T>
void PriorityQueue<T>::push(const T& t)
{
	MyComparator comp;
	typename std::list<T>::iterator it = lst.begin();
	while (it != lst.end() && comp( t,*it))
	{
		++it;
	}
	lst.insert(it, t);
}

template<typename T>
T PriorityQueue<T>::poll()
{
	if (lst.empty())
		throw std::runtime_error("Queue is empty");
	T tmp = lst.front();
	lst.pop_front();
	return tmp;

}



