#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <stack>

static const int STACK_SIZE = 500;

template <typename T>

class CMyStack
{
public:
	CMyStack();
	CMyStack(CMyStack const &rhs);
	CMyStack(CMyStack && rhs);
	~CMyStack();
	inline void Push(T const &value);
	inline void Pop();
	inline T Peek() const;
	inline bool IsEmpty() const;
	inline void Clear();
	void const operator =(CMyStack const &rhs);
	void const operator =(CMyStack && rhs);
private:
	T *m_pStack;
	size_t m_size;
};

template <typename T>
CMyStack<T>::CMyStack()
	: m_size(0)
	, m_pStack(new T[STACK_SIZE])
{}

template <typename T>
CMyStack<T>::CMyStack(CMyStack const &rhs)
	: m_size(rhs.m_size)
	, m_pStack(new T[STACK_SIZE])
{}
template <typename T>
CMyStack<T>::CMyStack(CMyStack && rhs)
{
	*this = std::move(rhs);
}

template <typename T>
CMyStack<T>::~CMyStack()
{
	delete[]m_pStack;
}

template <typename T>
void CMyStack<T>::Push(T const &value)
{
	if (m_size >= STACK_SIZE - 1)
	{
		throw std::exception("You can not add, stack overflow.");
	}
	m_pStack[m_size++] = value;
}

template <typename T>
void CMyStack<T>::Pop()
{
	if (m_size == 0)
	{
		throw std::exception("stack is empty.");
	}
	--m_size;
}

template <typename T>
T CMyStack<T>::Peek() const
{
	if (m_size == 0)
	{
		throw std::exception("stack is empty.");
	}
	return m_pStack[m_size - 1];
}

template <typename T>
bool CMyStack<T>::IsEmpty() const
{
	return m_size == 0 ? true : false;
}

template <typename T>
void CMyStack<T>::Clear()
{
	m_size = 0;
}

template <typename T>
void const CMyStack<T>::operator=(CMyStack const &rhs)
{
	if (m_pStack != rhs.m_pStack)
	{
		delete[]m_pStack;
		m_size = rhs.m_size;
		if (!(m_pStack = new T[STACK_SIZE]))
		{
			throw std::exception("it is impossible to allocate memory for the stack.");
		}
		memcpy(m_pStack, rhs.m_pStack, m_size);
	}
}

template <typename T>
void const CMyStack<T>::operator=(CMyStack && rhs)
{
	if (m_pStack != rhs.m_pStack)
	{
		std::swap(m_pStack, rhs.m_pStack);
		m_size = rhs.m_size;
		delete[]rhs.m_pStack;
		if (!(rhs.m_pStack = new T[STACK_SIZE]))
		{
			throw std::exception("it is impossible to allocate memory for the stack.");
		}
		rhs.m_size = 0;
	}
}


