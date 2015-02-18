#include "stdafx.h"

CPoint::CPoint() {
	m_x = 0;
	m_y = 0;
}

CPoint::CPoint(const unsigned int x, const unsigned int y) :  m_x(x)
															, m_y(y)
{}

// TODO: Check Error .h
CPoint::CPoint(const CPoint& p) : m_x(p.m_x)
								, m_y(p.m_y)
{}

CPoint::~CPoint() {
}

unsigned int CPoint::getX() const {
	return m_x;
}

unsigned int CPoint::getY() const {
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
CPoint& CPoint::operator*=( const float f )
{
	this->m_x *= f;
	this->m_y *= f;
	return *this;
}
CPoint& CPoint::operator/=( const float f )
{
	this->m_x /= f;
	this->m_y /= f;
	return *this;
}
bool CPoint::operator<( const CPoint& p )
{
	return ( this->m_x < p.getX() && this->m_y < p.getY() );
}

float CPoint::distance(CPoint p1, CPoint p2)
{
	return ( pow(sqrt(p2.getX() - p1.getX()), 2) + pow(sqrt(p2.getY() - p1.getY()), 2) );
}

CPoint& CPoint::getEscapePoint(const CPoint &p, const CPoint &enemy) 
{
	if (std::rand() % 1 == 0) //TODO : c'est dégueulasseuh
		if (enemy.m_x < p.m_x) //prendre en compte la vitesse (mettre en param ?!)
			return CPoint(p.m_x + 1, p.m_y);
		else
			return CPoint(p.m_x - 1, p.m_y);
	else
		if (enemy.m_y < p.m_y)
			return CPoint(p.m_x, p.m_y + 1);
		else
			return CPoint(p.m_x, p.m_y - 1);

}

std::ostream& operator<<(std::ostream& out, const CPoint* point)
{
	return out << "(" << point->getX() << ", " << point->getY() << ")";
}