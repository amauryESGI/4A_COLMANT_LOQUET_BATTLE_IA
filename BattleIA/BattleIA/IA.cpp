#include "stdafx.h"

/**
 * operator() - get the action to do with the enemy from the ia code of the unit
 * @param CUnit* - the current unit
 * @param const CArmy& - the army of the current unit
 * @param const CArmy& - the enemy army
 * @return Caction* - the action to do
 */
CAction* CIA::operator()(CUnit *unit, const CArmy &army1, const CArmy &army2) const
{
	CUnit *enemy;
	switch (unit->getIACode())
	{
	case LD: // ennemi le plus proche
		enemy = &army2.getNearestUnit(unit->getPos());
		break;
	case HD: // ennemi le plus loin
		enemy = &army2.getFurtherUnit(unit->getPos());
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
	default:
		throw "code ia not found";
	}

	if (CPoint::distance(unit->getPos(), enemy->getPos()) <= unit->getScope().getValue()
		&& unit->getWeaponSpeed().getCoolDown() == 0)
		return new CActionShoot(unit, enemy);
	else if (unit->getWeaponSpeed().getCoolDown() == 0
			 && CPoint::distance(unit->getPos(), enemy->getPos()) > unit->getScope().getValue())
	{
		CPoint targetPos = unit->getPos();
		for (int i = 0; i < unit->getSpeed().getValue(); ++i)
		{
			if (targetPos.getX() != enemy->getPos().getX())
			{
				if (targetPos.getX() < enemy->getPos().getX())
					targetPos.setX(targetPos.getX() + 1);
				else if (targetPos.getX() > enemy->getPos().getX())
					targetPos.setX(targetPos.getX() - 1);
			}
			if (targetPos.getY() != enemy->getPos().getY())
			{
				if (targetPos.getY() < enemy->getPos().getY())
					targetPos.setY(targetPos.getY() + 1);
				else if (targetPos.getY() > enemy->getPos().getY())
					targetPos.setY(targetPos.getY() - 1);
			}			
		}
		return new CActionMove(unit, targetPos);
	}
	else if (unit->getWeaponSpeed().getCoolDown() > 0)
	{
		CPoint targetPos = unit->getPos();
		for (int i = 0; i < unit->getSpeed().getValue(); ++i)
		{
			if (unit->getPos().getX() < enemy->getPos().getX())
				targetPos.setX(targetPos.getX() == 0 ? 0 : targetPos.getX() - 1);
			else if (unit->getPos().getX() > enemy->getPos().getX())
				targetPos.setX(targetPos.getX() + 1);
			else
			{
				targetPos.setX(rand() % 1 == 0 ? targetPos.getX() + 1 : targetPos.getX() == 0 ? 0 : targetPos.getX() - 1);
			}
			if (unit->getPos().getY() < enemy->getPos().getY())
				targetPos.setY(targetPos.getY() == 0 ? 0 : targetPos.getY() - 1);
			else if (unit->getPos().getY() > enemy->getPos().getY())
				targetPos.setY(targetPos.getY() + 1);
			else
				targetPos.setY(rand() % 1 == 0 ? targetPos.getY() + 1 : targetPos.getY() == 0 ? 0 : targetPos.getY() - 1);

		}
		return new CActionMove(unit, targetPos);
	}
}