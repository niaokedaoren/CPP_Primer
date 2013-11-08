#ifndef SMART_POINTER_H
#define SMART_POINTER_H

#include <iostream>
#include <string>

template <typename T> class SmartPtr;

class SPtrCounter
{
	template <typename T> friend class SmartPtr;

	int counter; // reference counter

	SPtrCounter(int n = 1): counter(n) {}
	void incRef() { counter++; }
	void decRef() { counter--; }
	int refNum() { return counter; }
};

// std::cout is only for test
template <typename T>
class SmartPtr
{
public:
	SmartPtr(T *objPtr): 
		objPtr(objPtr), counter(new SPtrCounter()) 
	{
		print("Constructor");
	}

	SmartPtr(const SmartPtr<T> &origin): 
		objPtr(origin.objPtr), counter(origin.counter)
	{
		counter->incRef();
		print("Copy Constructor");
	}

	~SmartPtr()
	{
		counter->decRef();
		print("Deconstructor");
		if (counter->refNum() == 0)
		{
			delete counter;
			delete objPtr;
			std::cout << "Released memory: " << objPtr << std::endl;
		}
	}

	SmartPtr<T>& operator=(const SmartPtr<T> &rhs);

	T& operator*();
	T* operator->();
	const T& operator*() const;
	const T* operator->() const;

private:
	// for test only
	void print(const std::string &msg) const
	{
		std::cout << msg << ": " << objPtr;
		std::cout << ", refNum: " << counter->refNum();
		std::cout << std::endl;
	}

	T *objPtr;
	SPtrCounter *counter;
};

template<typename T>
T& SmartPtr<T>::operator*()
{
	return *objPtr;
}

template<typename T>
const T& SmartPtr<T>::operator*() const
{
	return *objPtr;
}

template<typename T>
T* SmartPtr<T>::operator->()
{
	return objPtr;
}

template<typename T>
const T* SmartPtr<T>::operator->() const
{
	return objPtr;
}

template<typename T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T> &rhs)
{
	print("Before assignment");
	rhs.counter->incRef();
	counter->decRef();
	if (counter->refNum() == 0)
	{
		delete counter;
		delete objPtr;
		std::cout << "Released memory: " << objPtr << std::endl;
	}

	objPtr = rhs.objPtr;
	counter = rhs.counter;
	print("After assignment");
}

#endif // SMART_POINTER_H
