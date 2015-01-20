#include "stdafx.h"
#include "HealthPoint.h"


CHealthPoint::CHealthPoint()
{}


CHealthPoint::~CHealthPoint()
{}

void CHealthPoint::computeValue() {
	m_value = (m_level + 1) * 10;
}
