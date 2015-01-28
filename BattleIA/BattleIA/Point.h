#ifndef _POINT_H
#define _POINT_H

class CPoint {
public:
	CPoint();
	CPoint(const unsigned int x, const unsigned int y);
	CPoint(const CPoint& p);
	~CPoint();

	unsigned int getX() const;
	unsigned int getY() const;

private:
	unsigned int m_x;
	unsigned int m_y;
};

#endif