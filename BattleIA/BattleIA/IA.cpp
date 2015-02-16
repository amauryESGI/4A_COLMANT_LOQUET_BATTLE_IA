#include "stdafx.h"

CAction& CIA::operator()(CUnit unit, CArmy army1, CArmy army2)
{
	CUnit *enemy;
	switch (unit.getIACode())
	{
	case LD: // ennemi le plus proche
		enemy = &army2.getNearestUnit(unit.getPos());
		break;
	case HD: // ennemi le plus loin
		enemy = &army2.getFurtherUnit(unit.getPos());
		break;
	case L0: // ennemi qui a le moins de vitesse
		enemy = &army2.getLowestUnit(ECapacities::Speed);
		break;
	case H0: // ennemi qui a le plus de vitesse
		enemy = &army2.getHighestUnit(ECapacities::Speed);
		break;
	case L1: // ennemi qui a le moins de point de vie
		enemy = &army2.getLowestUnit(ECapacities::HealthPoint);
		break;
	case H1: // ennemi qui a le plus de point de vie
		enemy = &army2.getHighestUnit(ECapacities::HealthPoint);
		break;
	case L2: // ennemi qui a le moins de point d'armure
		enemy = &army2.getLowestUnit(ECapacities::Armor);
		break;
	case H2: // ennemi qui a le plus de point d'armure
		enemy = &army2.getHighestUnit(ECapacities::Armor);
		break;
	case L3: // ennemi qui a le moins de point de vie regeneré par tour
		enemy = &army2.getLowestUnit(ECapacities::Regeneration);
		break;
	case H3: // ennemi qui a le plus de point de vie regeneré par tour
		enemy = &army2.getHighestUnit(ECapacities::Regeneration);
		break;
	case L4: // ennemi qui a le moins de dommage
		enemy = &army2.getLowestUnit(ECapacities::Damage);
		break;
	case H4: // ennemi qui a le plus de dommage
		enemy = &army2.getHighestUnit(ECapacities::Damage);
		break;
	case L5: // ennemi qui a le moins de portée
		enemy = &army2.getLowestUnit(ECapacities::Scope);
		break;
	case H5: // ennemi qui a le plus de portée
		enemy = &army2.getHighestUnit(ECapacities::Scope);
		break;
	case L6: // ennemi qui a le moins de cooldown
		enemy = &army2.getLowestUnit(ECapacities::WeaponSpeed);
		break;
	case H6: // ennemi qui a le plus de cooldown
		enemy = &army2.getHighestUnit(ECapacities::WeaponSpeed);
		break;
	default :
		throw "code ia not found";
	}

	if (CPoint::distance(unit.getPos(), enemy->getPos()) < unit.getScope().getValue()
		&& unit.getWeaponSpeed().getValue() == 0)
	{
		return CActionShoot(unit, *enemy);
	}
	//return CAction(unit);
}