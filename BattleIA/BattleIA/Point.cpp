#include "stdafx.h"
#include "Point.h"

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