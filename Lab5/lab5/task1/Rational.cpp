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

//1
double CRational::ToDouble()const
{
	return static_cast<double>(m_numerator) / static_cast<double>(m_denominator);
}

//2
CRational const CRational::operator-() const
{
	return CRational(-m_numerator, m_denominator);
}

CRational const CRational::operator+() const
{
	return *this;
}


//3
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

//4
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
//5
void const CRational::operator +=(CRational const &rat) 
{
	auto res = CRational(m_numerator, m_denominator) + rat;
	m_numerator = res.m_numerator;
	m_denominator = res.m_denominator;
}
//6
void const CRational::operator -=(CRational const &rat)
{
	auto res = CRational(m_numerator, m_denominator) - rat;
	m_numerator = res.m_numerator;
	m_denominator = res.m_denominator;
}

//7
CRational const operator *(CRational const &rat1, CRational const &rat2)
{
	auto copyRightVal = rat1;
	//auto copyLeftVal = std::pair<int, int>(m_numerator, m_denominator);
	copyRightVal.m_numerator *= rat2.m_numerator;
	copyRightVal.m_denominator *= rat2.m_denominator;
	auto mostLarDiv = GCD(copyRightVal.m_numerator, copyRightVal.m_denominator);
	return CRational(copyRightVal.m_numerator / int(mostLarDiv), copyRightVal.m_denominator / int(mostLarDiv));
}
//8
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
//9
void const CRational::operator *=(CRational const &rat)
{
	*this = *this * rat;
}

//10
void const CRational::operator /=(CRational const &rat)
{
	auto res = CRational(m_numerator, m_denominator) / rat;
	m_numerator = res.m_numerator;
	m_denominator = res.m_denominator;
}


//11
bool const CRational::operator ==(CRational const &rat) const
{
	return (m_numerator == rat.m_numerator && m_denominator == rat.m_denominator);
}

bool const CRational::operator !=(CRational const &rat) const
{
	return (m_numerator != rat.m_numerator || m_denominator != rat.m_denominator);
}

//12
bool const CRational::operator <(CRational const &rat) const
{
	auto copyRightVal = rat;
	auto copyLeftVal = std::pair<int, int>(m_numerator, m_denominator);
	copyRightVal.m_numerator *= m_denominator;
	copyRightVal.m_denominator *= m_denominator;
	copyLeftVal.first *= copyRightVal.m_denominator / copyLeftVal.second;
	copyLeftVal.second *= copyRightVal.m_denominator / copyLeftVal.second;
	return copyLeftVal.first < copyRightVal.m_numerator;
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
//13
std::ostream& operator << (std::ostream &os, CRational const &rat)
{
	return os << rat.GetNumerator() << "/" << rat.GetDenominator();
}

//14
std::istream & operator >> (std::istream & strm, CRational & rational)
{
	std::streamoff startPos = strm.tellg();
	int numerator;
	int denominator;
	if ((strm >> numerator) && (strm.get() == '/') && (strm >> denominator))
	{
		rational = CRational(numerator, denominator);
		return strm;
	}
	strm.seekg(startPos);
	return strm;
}

std::pair<int, CRational> CRational::ToCompoundFraction()const
{
	int value = static_cast<int>(ToDouble());
	int numerator = m_numerator - m_denominator * value;
	return std::make_pair<int, CRational>(std::move(value), CRational(numerator, m_denominator));
}