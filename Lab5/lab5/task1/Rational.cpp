#include "stdafx.h"
#include "Rational.h"
#include <utility>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
//////////////////////////////////////////////////////////////////////////

CRational const CRational::operator-() const
{
	return CRational(-m_numerator, m_denominator);
}

CRational const CRational::operator+() const
{
	return *this;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 3. Реализовать бинарный +
//////////////////////////////////////////////////////////////////////////

CRational const CRational::operator +(CRational const &rat) const
{
	auto copyRightVal = rat;
	auto copyLeftVal = std::pair<int, int>(m_numerator, m_denominator);
	copyRightVal.m_numerator *= m_denominator;
	copyRightVal.m_denominator *= m_denominator;
	copyLeftVal.first *= copyRightVal.m_denominator / copyLeftVal.second;
	copyLeftVal.second *= copyRightVal.m_denominator / copyLeftVal.second;
	copyLeftVal.first += copyRightVal.m_numerator;
	auto mostLarDiv = GCD(copyLeftVal.first, copyLeftVal.second);
	return{ copyLeftVal.first / int(mostLarDiv), copyLeftVal.second / int(mostLarDiv) };
}


//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
//////////////////////////////////////////////////////////////////////////
CRational const CRational::operator -(CRational const &rat) const
{
	auto copyRightVal = rat;
	auto copyLeftVal = std::pair<int, int>(m_numerator, m_denominator);
	copyRightVal.m_numerator *= m_denominator;
	copyRightVal.m_denominator *= m_denominator;
	copyLeftVal.first *= copyRightVal.m_denominator / copyLeftVal.second;
	copyLeftVal.second *= copyRightVal.m_denominator / copyLeftVal.second;
	copyLeftVal.first -= copyRightVal.m_numerator;
	auto mostLarDiv = GCD(copyLeftVal.first, copyLeftVal.second);
	return { copyLeftVal.first / int(mostLarDiv), copyLeftVal.second / int(mostLarDiv) };
}


//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
//////////////////////////////////////////////////////////////////////////

void const CRational::operator +=(CRational const &rat) 
{
	auto res = CRational(m_numerator, m_denominator) + rat;
	m_numerator = res.m_numerator;
	m_denominator = res.m_denominator;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
//////////////////////////////////////////////////////////////////////////

void const CRational::operator -=(CRational const &rat)
{
	auto res = CRational(m_numerator, m_denominator) - rat;
	m_numerator = res.m_numerator;
	m_denominator = res.m_denominator;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
//////////////////////////////////////////////////////////////////////////

CRational const operator *(CRational const &rat1, CRational const &rat2)
{
	auto copyRightVal = rat1;
	//auto copyLeftVal = std::pair<int, int>(m_numerator, m_denominator);
	copyRightVal.m_numerator *= rat2.m_numerator;
	copyRightVal.m_denominator *= rat2.m_denominator;
	auto mostLarDiv = GCD(copyRightVal.m_numerator, copyRightVal.m_denominator);
	return CRational(copyRightVal.m_numerator / int(mostLarDiv), copyRightVal.m_denominator / int(mostLarDiv));
}

//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
//////////////////////////////////////////////////////////////////////////


CRational const CRational::operator /(CRational const &rat) const
{
	auto copy = std::pair<int, int>(m_numerator, m_denominator);
	copy.first *= rat.m_denominator;
	copy.second *= rat.m_numerator;
	auto mostLarDiv = GCD(copy.first, copy.second);
	return CRational(copy.first / int(mostLarDiv), copy.second / int(mostLarDiv));
}

CRational const operator /(int t, CRational const &rat)
{
	return CRational(rat.m_denominator * t, rat.m_numerator);
}

CRational const operator /(CRational const &rat, int t)
{
	return CRational(rat.m_numerator, rat.m_denominator * t);
}


//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
//////////////////////////////////////////////////////////////////////////

void const CRational::operator *=(CRational const &rat)
{
	auto res = CRational(m_numerator, m_denominator) * rat;
	m_numerator = res.m_numerator;
	m_denominator = res.m_denominator;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
//////////////////////////////////////////////////////////////////////////

void const CRational::operator /=(CRational const &rat)
{
	auto res = CRational(m_numerator, m_denominator) / rat;
	m_numerator = res.m_numerator;
	m_denominator = res.m_denominator;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
//////////////////////////////////////////////////////////////////////////
bool const CRational::operator ==(CRational const &rat) const
{
	return (m_numerator == rat.m_numerator && m_denominator == rat.m_denominator);
}

bool const CRational::operator !=(CRational const &rat) const
{
	return (m_numerator != rat.m_numerator || m_denominator != rat.m_denominator);
}


//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
//////////////////////////////////////////////////////////////////////////
bool const CRational::operator <(CRational const &rat) const
{
	auto copyRightVal = rat;
	auto copyLeftVal = *this;//std::pair<int, int>(m_numerator, m_denominator);
	copyRightVal.m_numerator *= m_denominator;
	copyRightVal.m_denominator *= m_denominator;
	copyLeftVal.m_numerator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;
	copyLeftVal.m_denominator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;
	return copyLeftVal.m_numerator < copyRightVal.m_numerator;
}

bool const CRational::operator >(CRational const &rat) const
{
	auto copyRightVal = rat;
	auto copyLeftVal = std::pair<int, int>(m_numerator, m_denominator);
	copyRightVal.m_numerator *= m_denominator;
	copyRightVal.m_denominator *= m_denominator;
	copyLeftVal.first *= copyRightVal.m_denominator / copyLeftVal.second;
	copyLeftVal.second *= copyRightVal.m_denominator / copyLeftVal.second;
	return copyLeftVal.first > copyRightVal.m_numerator;
}

bool const CRational::operator <=(CRational const &rat) const
{
	auto copyRightVal = rat;
	auto copyLeftVal = std::pair<int, int>(m_numerator, m_denominator);
	copyRightVal.m_numerator *= m_denominator;
	copyRightVal.m_denominator *= m_denominator;
	copyLeftVal.first *= copyRightVal.m_denominator / copyLeftVal.second;
	copyLeftVal.second *= copyRightVal.m_denominator / copyLeftVal.second;
	return copyLeftVal.first <= copyRightVal.m_numerator;
}

bool const CRational::operator >=(CRational const &rat) const
{
	auto copyRightVal = rat;
	auto copyLeftVal = std::pair<int, int>(m_numerator, m_denominator);
	copyRightVal.m_numerator *= m_denominator;
	copyRightVal.m_denominator *= m_denominator;
	copyLeftVal.first *= copyRightVal.m_denominator / copyLeftVal.second;
	copyLeftVal.second *= copyRightVal.m_denominator / copyLeftVal.second;
	return copyLeftVal.first >= copyRightVal.m_numerator;
}
//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//////////////////////////////////////////////////////////////////////////


std::ostream& operator << (std::ostream &os, CRational const &rat)
{
	return os << rat.m_numerator << "/" << rat.m_denominator;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//////////////////////////////////////////////////////////////////////////


/*std::istream& operator >> (std::istream &is, CRational &rat)
{
	std::string str;
	is >> str;
	std::vector<std::string> vec;
	boost::split(vec, str, boost::is_any_of("/"));
	rat.m_numerator = atoi(vec[0].c_str());
	rat.m_denominator = atoi(vec[1].c_str());
	return is;
}*/