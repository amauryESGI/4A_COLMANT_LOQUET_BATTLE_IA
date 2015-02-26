#ifndef _POINT_H
#define _POINT_H
#include "stdafx.h"

class CPoint
{
public:
	CPoint();
	CPoint(const uint x, const uint y);
	CPoint(const CPoint& p);
	~CPoint();

	unsigned int	getX() const;
	unsigned int	getY() const;
	void			setX(const uint x);
	void			setY(const uint y);

	CPoint			operator+( const CPoint& p ) const;
	CPoint			operator-( const CPoint& p ) const;
	CPoint			operator*( const float f ) const;
	CPoint			operator/( const float f ) const;
	CPoint&			operator+=( const CPoint& p );
	CPoint&			operator-=( const CPoint& p );
	CPoint&			operator*=( const uint f );
	CPoint&			operator/=( const uint f );
	bool			operator<( const CPoint& p ) const;
	CPoint			operator-( ) const;

	friend ostream& operator<<( ostream& out, const CPoint& point );

	static float	distance(const CPoint &p1, const CPoint &p2);


private:
	uint m_x;
	uint m_y;
};


#endif