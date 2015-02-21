#include "stdafx.h"



CScope::CScope() : CCapacity()
{}


CScope::~CScope()
{}

void CScope::computeValue() {
	m_value = 10 + m_level * 2;
}