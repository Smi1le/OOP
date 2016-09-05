#pragma once
#include <vector>
#include <string>
#include <iostream>

template <typename T>
struct SElement
{
	T value;
	SElement* next;
};


template <typename T>
class CMyStack
{
public:
	CMyStack();
	CMyStack(CMyStack const &other);
	CMyStack(CMyStack && other);
	~CMyStack();
	void Push(T const &value);
	void Pop();
	T Peek() const;
	bool IsEmpty() const;
	void Clear();
	size_t GetSize() const;
	void const operator =(CMyStack const &other);
	void const operator =(CMyStack && other);
private:
	SElement<T> *m_head;
	size_t m_size;
};

template <typename T>
CMyStack<T>::CMyStack()
	: m_size(0)
	, m_head(nullptr)
{
}

template <typename T>
CMyStack<T>::CMyStack(CMyStack const &other)
	: m_size(0)
	, m_head(nullptr)
{
	*this = other;
}
template <typename T>
CMyStack<T>::CMyStack(CMyStack && other)
	: m_size(0)
	, m_head(nullptr)
{
	*this = std::move(other);
}

template <typename T>
CMyStack<T>::~CMyStack()
{
	Clear();
}

template <typename T>
void CMyStack<T>::Push(T const &value)
{
	SElement<T> *temp = nullptr;
	// TODO: useless condition and if-body
	if ((temp = new SElement<T>()) == nullptr)
	{
		throw std::exception("it's impossible to allocate memory for the stack.");
	}
	// TODO: fix memory leak when value copy ctor throws exception.
	temp->value = value;
	temp->next = m_head;
	m_head = temp;
	++m_size;
}

template <typename T>
void CMyStack<T>::Pop()
{
	if (m_size == 0)
	{
		// TODO: use `runtime_error`,`invalid_argument`, `logic_error`, `out_of_range` or something else
		throw std::exception("stack is empty.");
	}
	auto temp = m_head->next;
	delete m_head;
	m_head = temp;
	--m_size;
}

template <typename T>
T CMyStack<T>::Peek() const
{
	// TODO: use `runtime_error`,`invalid_argument`, `logic_error`, `out_of_range` or something else
	if (m_size == 0)
	{
		throw std::exception("stack is empty.");
	}
	return m_head->value;
}

template <typename T>
bool CMyStack<T>::IsEmpty() const
{
	return m_size == 0;
}

template <typename T>
void CMyStack<T>::Clear()
{
	while (m_head != nullptr)
	{
		Pop();
	}
	m_size = 0;
}

template <typename T>
void const CMyStack<T>::operator=(CMyStack const &other)
{
	if (m_head != other.m_head)
	{
		Clear();
		auto temp = other.m_head;
		// TODO:don't allocate memory twice
		CMyStack<T> bufStack;
		for (size_t i = 0; i != other.m_size; ++i)
		{
			bufStack.Push(temp->value);
			auto pointer = temp->Next;
			temp = pointer;
		}
		auto pointer = bufStack.m_head;
		for (size_t i = 0; i != other.m_size; ++i)
		{
			Push(pointer->value);
			auto ptr = pointer->Next;
			pointer = ptr;
		}
	}

}

template <typename T>
void const CMyStack<T>::operator=(CMyStack && other)
{
	if (m_head != other.m_head)
	{
		// TODO: move ctor should only move data without new allocations
		Clear();
		*this = other;
		other.Clear();
	}
}

template <typename T>
size_t CMyStack<T>::GetSize() const
{
	return m_size;
}
