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
	: CMyString(pString, strlen(pString))
{}

CMyString::CMyString(const char * pString, size_t length)
{
	StringCopy(pString, length);
}

CMyString::CMyString(CMyString const& other)
	: CMyString(other.m_chars, other.m_length)
{
}

CMyString::CMyString(CMyString && other)
	//: m_chars(other.m_chars)
{
	*this = std::move(other);
}

CMyString::CMyString(std::string const& stlString)
	: CMyString(stlString.c_str(), stlString.size())
{}

CMyString::~CMyString()
{
	delete[] m_chars;
	//	m_chars = nullptr;
}

size_t CMyString::GetLength() const
{
	return m_length;
}

const char* CMyString::GetStringData() const
{
	return m_chars;
}

void CMyString::StringCopy(const char * pString, size_t length)
{
	m_length = length;
	m_chars = new char[m_length + 1];
	memcpy(m_chars, pString, m_length);
	m_chars[m_length] = '\0';
}

CMyString const CMyString::SubString(size_t start, size_t length) const
{
	assert(start <= m_length);
	if (!m_chars)
	{
		return CMyString("");
	}
	else if (length > m_length)
	{
		length = m_length;
	}
	return CMyString(&m_chars[start], length);
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

//Оператор присваивания
CMyString const CMyString::operator=(CMyString && str)
{
	if (m_chars != str.m_chars)
	{
		std::swap(m_chars, str.m_chars);
		m_length = str.m_length;
		delete[] str.m_chars;
		str.m_chars = nullptr;
		str.m_length = 0;
	}
	return *this;
}

void const CMyString::operator=(CMyString const &str)
{
	if (m_chars != str.m_chars)
	{
		delete[]m_chars;
		StringCopy(str.m_chars, str.m_length);
	}
}

//Оператор конкатенации
CMyString const operator+(CMyString const &str1, CMyString const &str2)
{
	if (!str2.m_chars)
	{
		return CMyString(str1);
	}
	auto copy = str1;
	return copy += str2;
}

/*CMyString operator+ (CMyString & str1, CMyString const & str2)
{
	
}*/

//Оператор сравнения
bool const operator==(CMyString const &str1, CMyString const &str2)
{
	if (str1.m_length != str2.m_length)
	{
		return false;
	}
	for (size_t i = 0; i != str1.m_length; ++i)
	{
		if (str1.m_chars[i] != str2.m_chars[i])
		{
			return false;
		}
	}
	return true;
}

bool const operator!=(CMyString const &str1, CMyString const &str2)
{
	return !(str1 == str2);
}

//Оператор +=
CMyString & operator+=(CMyString &str1, CMyString const &str2)
{
	if (str1.m_chars)
	{
		char *temp = new char[str2.m_length + str1.GetLength() + 1];
		memcpy(temp, str1.GetStringData(), str1.m_length);
		memcpy(&temp[str1.m_length], str2.GetStringData(), str2.GetLength());

		delete[] str1.m_chars;
		str1.m_chars = temp;
		str1.m_length += str2.GetLength();
		str1.m_chars[str1.m_length] = '\0';
	}
	return str1;
}

const char &CMyString::operator[](size_t pos) const
{
	if (pos > m_length)
	{
		throw(std::out_of_range("out of range"));
	}
	return m_chars[pos];
}

char &CMyString::operator[](size_t pos)
{
	if (pos >= m_length && pos != 0)
	{
		throw std::out_of_range("Index out of range.");
	}
	else if (!m_chars)
	{
		m_chars = new char[2];
		m_chars[1] = '\0';
	}

	return m_chars[pos];
}

bool const CMyString::operator<(CMyString const &string)
{
	return m_length < string.m_length;
}

bool const CMyString::operator>(CMyString const &string)
{
	return m_length > string.m_length;
}

bool const CMyString::operator<=(CMyString const &string)
{
	return (*this < string || *this == string);
}

bool const CMyString::operator>=(CMyString const &string)
{
	return (*this > string || *this == string);
}

std::ostream& operator << (std::ostream &os, CMyString const &string)
{
	return os << string.m_chars;
}

std::istream& operator >> (std::istream &is, CMyString &string)
{
	auto pos = is.tellg();
	std::string temp;
	if (is >> temp)
	{
		string = CMyString(temp);
		return is;
	}
	is.seekg(pos);
	return is;
}