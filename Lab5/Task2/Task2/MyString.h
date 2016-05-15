#pragma once
#include <string>



class CMyString
{
public:
	// конструктор по умолчанию
	CMyString();
	CMyString(const char * pString);
	CMyString(const char * pString, size_t length);
	CMyString(CMyString const& other);
	CMyString(CMyString && other);
	CMyString(std::string const& stlString);
	~CMyString();

	size_t GetLength()const;

	const char* GetStringData()const;

	CMyString const SubString(size_t start, size_t length = SIZE_MAX)const;

	void Clear();

	void Display() const;

	void StringCopy(const char * pString, size_t length);

	CMyString const operator=(CMyString && str);
	void const operator=(CMyString const &str);

	friend CMyString const operator+(CMyString const &str1, CMyString const &str2);

	friend bool const operator==(CMyString const &str1, CMyString const &str2);
	friend bool const operator!=(CMyString const &str1, CMyString const &str2);

	friend CMyString & operator+=(CMyString &str1, CMyString const &str2);
	const char &operator[](size_t pos) const;
	char &operator[](size_t pos);

	bool const operator<(CMyString const &string);
	bool const operator>(CMyString const &string);
	bool const operator<=(CMyString const &string);
	bool const operator>=(CMyString const &string);

	friend std::ostream& operator<<(std::ostream &os, CMyString const &string);
	friend std::istream& operator>>(std::istream &is, CMyString &string);

private:
	size_t m_length;
	char *m_chars;
};
