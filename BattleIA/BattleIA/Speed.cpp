#include "stdafx.h"
#include "Speed.h"


CSpeed::CSpeed()
{}


CSpeed::~CSpeed()
{}

void CSpeed::computeValue() {
	m_value = m_level + 1;
}