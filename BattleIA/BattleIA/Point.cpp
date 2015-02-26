#include "stdafx.h"

CPoint::CPoint() {
	m_x = 0;
	m_y = 0;
}

CPoint::CPoint(const uint x, const uint y) :  m_x(x)
											, m_y(y)
{}

// TODO: Check Error .h
CPoint::CPoint(const CPoint& p) : m_x(p.m_x)
								, m_y(p.m_y)
{}

CPoint::~CPoint() {
}

uint CPoint::getX() const {
	return m_x;
}

uint CPoint::getY() const {
	return m_y;
}

CPoint CPoint::operator+( const CPoint& p ) const
{
	return CPoint(this->getX() + p.getX(), this->getY() + p.getY());
}
CPoint CPoint::operator-( const CPoint& p ) const
{
	return CPoint(this->getX() - p.getX(), this->getY() - p.getY());
}
CPoint CPoint::operator*( const float f ) const
{
	return CPoint(this->getX() * f, this->getY() * f);
}
CPoint CPoint::operator/( const float f ) const
{
	return CPoint(this->getX() / f, this->getY() / f);
}
CPoint& CPoint::operator+=( const CPoint& p )
{
	this->m_x += p.getX();
	this->m_y += p.getY();
	return *this;
}
CPoint& CPoint::operator-=( const CPoint& p )
{
	this->m_x -= p.getX();
	this->m_y -= p.getY();
	return *this;
}
CPoint& CPoint::operator*=( const uint f )
{
	this->m_x *= f;
	this->m_y *= f;
	return *this;
}
CPoint& CPoint::operator/=( const uint f )
{
	this->m_x /= f;
	this->m_y /= f;
	return *this;
}
bool CPoint::operator<( const CPoint& p ) const
{
	return ( this->m_x < p.getX() && this->m_y < p.getY() );
}

float CPoint::distance(const CPoint &p1, const CPoint &p2)
{
	return ( sqrt( pow(p2.getX() - p1.getX(), 2) + pow(p2.getX()- p1.getX(), 2)));
}

ostream& operator<<(ostream& out, const CPoint& point)
{
	return out << "(" << point.getX() << ", " << point.getY() << ")";
}