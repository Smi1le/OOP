#pragma once
#include <vector>
#include <string>
#include <iostream>

template <typename T>

class CMyStack
{
public:
	CMyStack(int size = 0, T const &value = T());
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
	std::vector<T> m_stack;
	size_t m_size;
};


template <typename T>
CMyStack<T>::CMyStack(int size, T const &value)
	: m_size(size)
{
	m_stack.resize(size, value);
}

template <typename T>
CMyStack<T>::CMyStack(CMyStack const &rhs)
	: m_size(rhs.m_size)
	, m_stack(rhs.m_stack)
{}

template <typename T>
CMyStack<T>::CMyStack(CMyStack && rhs)
{
	*this = std::move(rhs);
}

template <typename T>
CMyStack<T>::~CMyStack()
{
	m_stack.clear();
}

template <typename T>
void CMyStack<T>::Push(T const &value)
{
	m_stack.push_back(value);
	++m_size;
}

template <typename T>
void CMyStack<T>::Pop()
{
	--m_size;
	m_stack.pop_back();
}

template <typename T>
T CMyStack<T>::Peek() const
{
	return m_stack.at(m_size - 1);
}

template <typename T>
bool CMyStack<T>::IsEmpty() const
{
	return m_size == 0 ? true : false;
}

template <typename T>
void CMyStack<T>::Clear()
{
	m_stack.clear();
	m_size = 0;
}

template <typename T>
void const CMyStack<T>::operator=(CMyStack const &rhs)
{
	m_stack = rhs;
	m_size = rhs.m_size;
}

template <typename T>
void const CMyStack<T>::operator=(CMyStack && rhs)
{
	m_stack = rhs.m_stack;
	m_size = rhs.m_size;
	rhs.m_size = 0;
	rhs.m_stack.clear();
}






