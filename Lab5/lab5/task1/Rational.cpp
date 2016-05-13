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
	return CRational(m_numerator * rat.m_denominator + rat.m_numerator * m_denominator, rat.m_denominator * m_denominator);
}

//4
CRational const CRational::operator -(CRational const &rat) const
{
	return *this + -rat;
}
//5
void const CRational::operator +=(CRational const &rat) 
{
	*this = *this + rat;
}
//6
void const CRational::operator -=(CRational const &rat)
{
	*this = *this - rat;
}

//7
CRational const operator *(CRational rat1, CRational const &rat2)
{
	return CRational(rat1.m_numerator * rat2.m_numerator, rat1.m_denominator * rat2.m_denominator);
}
//8
CRational const CRational::operator /(CRational const &rat) const
{
	return CRational(m_numerator * rat.m_denominator, m_denominator * rat.m_numerator);
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
	*this = *this / rat;
}


//11
bool const CRational::operator ==(CRational const &rat) const
{
	return (m_numerator == rat.m_numerator && m_denominator == rat.m_denominator);
}

bool const CRational::operator !=(CRational const &rat) const
{
	return !(*this == rat);
}

//12
bool const CRational::operator <(CRational const &rat) const
{
	return m_numerator * rat.m_denominator < rat.m_numerator * m_denominator;
}

bool const CRational::operator >(CRational const &rat) const
{
	return !(*this < rat) && (*this != rat);
}

bool const CRational::operator <=(CRational const &rat) const
{
	return (*this < rat) || (*this == rat);
}

bool const CRational::operator >=(CRational const &rat) const
{
	return (*this == rat) || (*this > rat);
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
	return std::make_pair<int, CRational>(std::move(value), CRational(m_numerator - m_denominator * value, m_denominator));
}