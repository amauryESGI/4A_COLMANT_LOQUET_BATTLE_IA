#include "stdafx.h"


CActionShoot::CActionShoot(CUnit *unit1, CUnit *unit2) :  CAction(unit1),
															m_target(unit2)
{}

CActionShoot::~CActionShoot()
{}

/**
 * Execute actionShoot
 */
void CActionShoot::execute()
{	
	m_unit->shoot();
	m_target->takeDamage(m_unit->getDamage().getValue());
	cout << "Unite " 
		 << m_unit->getId() 
		 << " (Armee " 
		 << m_unit->getArmyName() 
		 << ")" 
		 << " attaque Unite " 
		 << m_target->getId() 
		 << " (Armee " 
		 << m_target->getArmyName() 
		 << ")" 
		 <<  " qui n'a plus que  " 
		 << m_target->getHealthPoint().getValue() 
		 << " HP" 
		 << endl;
}