#include "stdafx.h"



CSpeed::CSpeed(): CCapacity()
{}


CSpeed::~CSpeed()
{}

void CSpeed::computeValue() {
	m_value = m_level + 1;
}