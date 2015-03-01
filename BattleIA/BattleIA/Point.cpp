#include "stdafx.h"
/**
 * Default constructor of CPoint
 */
CPoint::CPoint() {
	m_x = 0;
	m_y = 0;
}
/**
 * constructor of CPoint
 * @param const uint x - the x coord of the point
 * @param const uint y - the y coord of the point
 */
CPoint::CPoint(const uint x, const uint y) :  m_x(x)
											, m_y(y)
{}
/**
 * constructor of CPoint
 * @param const CPoint& p - the point
 */
CPoint::CPoint(const CPoint& p) : m_x(p.m_x)
								, m_y(p.m_y)
{}

CPoint::~CPoint() {
}
/**
 * Get the x coord of the point
 * @return unsigned int - the x coord
 */
uint CPoint::getX() const {
	return m_x;
}
/**
 * Get the y coord of the point
 * @return unsigned int - the y coord
 */
uint CPoint::getY() const {
	return m_y;
}
/**
 * Set the x coord of the point
 * @param const unsigned int - the x coord
 */
void CPoint::setX(const uint x)
{
	 m_x = x;
}
/**
 * Set the y coord of the point
 * @param const unsigned int - the y coord
 */
void CPoint::setY(const uint y)
{
	m_y = y;
}
/**
 * operator+ to add two points
 * @param const CPoint& p - the point to add
 * @return CPoint - the two points added
 */
CPoint CPoint::operator+( const CPoint& p ) const
{
	return CPoint(this->getX() + p.getX(), this->getY() + p.getY());
}
/**
 * operator- to substract two points
 * @param const CPoint& p - the point to substract
 * @return CPoint - the two points substracted
 */
CPoint CPoint::operator-( const CPoint& p ) const
{
	return CPoint(this->getX() - p.getX(), this->getY() - p.getY());
}
/**
 * operator* to multiply two points
 * @param const unsigned int - the factor to multiply
 * @return CPoint - the point mutiplied with the facor
 */
CPoint CPoint::operator*( const uint i ) const
{
	return CPoint(this->getX() * i, this->getY() * i);
}
/**
 * operator/ to divide two points
 * @param const unsigned int - the factor to divid
 * @return CPoint - the point divided with the facor
 */
CPoint CPoint::operator/( const uint i ) const
{
	return CPoint(this->getX() / i, this->getY() / i);
}
/**
 * operator+= to add a point to the current point
 * @param const CPoint& p - the point to add
 * @return CPoint - the point added to the current point
 */
CPoint& CPoint::operator+=( const CPoint& p )
{
	this->m_x += p.getX();
	this->m_y += p.getY();
	return *this;
}
/**
 * operator-= to substract a point to the current point
 * @param const CPoint& p - the point to substract
 * @return CPoint - the point substracteds to the current point
 */
CPoint& CPoint::operator-=( const CPoint& p )
{
	this->m_x -= p.getX();
	this->m_y -= p.getY();
	return *this;
}
/**
 * operator*= to multiply a point to the current point
 * @param const CPoint& p - the point to multiply
 * @return CPoint - the point multiplied to the current point
 */
CPoint& CPoint::operator*=( const uint i )
{
	this->m_x *= i;
	this->m_y *= i;
	return *this;
}
/**
 * operator/= to divide a point to the current point
 * @param const CPoint& p - the point to divide
 * @return CPoint - the point divided to the current point
 */
CPoint& CPoint::operator/=( const uint i )
{
	this->m_x /= i;
	this->m_y /= i;
	return *this;
}
/**
 * Check if a point is smaller than an other
 * @param CPoint& p - reference to the other point
 * @return bool true / false - true if the current point is smaller than the other; false in the other case
 */
bool CPoint::operator<( const CPoint& p ) const
{
	return ( this->m_x < p.getX() && this->m_y < p.getY() );
}
/**
 * Get the distance between two point
 * @param CPoint &p1 - the first point
 * @param CPoint &p2 - the other point
 * @return float - the distance between the two points
 */
float CPoint::distance(const CPoint &p1, const CPoint &p2)
{
	return sqrt( pow(p2.getX() - p1.getX(), 2) + pow(p2.getY()- p1.getY(), 2));
}
/**
 * operator<< to print a point
 * @param ostream& out - the flow
 * @param const CPoint& point - the point to print
 * @return ostream& - the modified flow
 */
ostream& operator<<(ostream& out, const CPoint& point)
{
	return out << "(" << point.getX() << ", " << point.getY() << ")";
}