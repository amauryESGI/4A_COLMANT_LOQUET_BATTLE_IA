#include "stdafx.h"



CScope::CScope()
{}


CScope::~CScope()
{}

void CScope::computeValue() {
	m_value = 10 + m_level * 2;
}