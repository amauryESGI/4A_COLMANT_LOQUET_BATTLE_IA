#ifndef _POINT_H
#define _POINT_H
#include "stdafx.h"

class CPoint {
public:
	CPoint();
	CPoint(const unsigned int x, const unsigned int y);
	CPoint(const CPoint& p);
	~CPoint();

	unsigned int getX() const;
	unsigned int getY() const;

	CPoint			operator+( const CPoint& p ) const;
	CPoint			operator-( const CPoint& p ) const;
	CPoint			operator*( const float f ) const;
	CPoint			operator/( const float f ) const;
	CPoint&			operator+=( const CPoint& p );
	CPoint&			operator-=( const CPoint& p );
	CPoint&			operator*=( const float f );
	CPoint&			operator/=( const float f );
	bool			operator<( const CPoint& p );
	CPoint			operator-( );

	static float	distance(CPoint p1, CPoint p2);

private:
	unsigned int m_x;
	unsigned int m_y;
};

#endif