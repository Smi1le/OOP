#include "stdafx.h"
#include "MyString.h"
#include <iostream>


CMyString::CMyString()
	: m_length(0)
	, m_chars(new char(1))
{
	m_chars[0] = '\0';
}

CMyString::CMyString(const char * pString)
	: m_length(strlen(pString) + 1)
	, m_chars(new char(m_length))
{
	memcpy(m_chars, pString, m_length);
	m_chars[m_length - 1] = '\0';
	--m_length;
}

CMyString::CMyString(const char * pString, size_t length)
	: m_length(length + 1)
	, m_chars(new char(m_length))
{
	memcpy(m_chars, pString, m_length);
	m_chars[m_length - 1] = '\0';
	--m_length;
}

CMyString::CMyString(CMyString const& other)
	: m_length(other.m_length + 1)
	, m_chars(new char(m_length))
{
	memcpy(m_chars, other.m_chars, m_length);
	m_chars[m_length - 1] = '\0';
	--m_length;
}

CMyString::CMyString(CMyString && other)
	: m_length(other.m_length)
	, m_chars(other.m_chars)
{
	other.m_length = 0;
	other.m_chars = nullptr;
}

CMyString::CMyString(std::string const& stlString)
	: m_length(stlString.size() + 1)
	, m_chars(new char(m_length))
{
	memcpy(m_chars, stlString.c_str(), m_length);
	m_chars[m_length - 1] = '\0';
	--m_length;
}

CMyString::~CMyString()
{
	delete[] m_chars;
	m_chars = nullptr;
}

size_t CMyString::GetLength() const
{
	return m_length;
}

const char* CMyString::GetStringData() const
{
	return m_chars;
}

CMyString const CMyString::SubString(size_t start, size_t length = SIZE_MAX) const
{
	if (m_length > 0 && start < m_length && start < length && length <= m_length)
	{
		return CMyString(&m_chars[start], length);
	}
	return CMyString();
}

void CMyString::Clear()
{
	delete[]m_chars;
	m_chars = new char(1);
	m_chars[0] = '\0';
	m_length = 0;
}

void CMyString::Display() const
{
	std::cout << "string = " << m_chars << std::endl;
}