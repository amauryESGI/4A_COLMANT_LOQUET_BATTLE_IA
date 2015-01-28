#ifndef _UNIT_H
#define _UNIT_H

#include "Capacity.h"
#include "Armor.h"
#include "Damage.h"
#include "HealthPoint.h"
#include "Regeneration.h"
#include "Scope.h"
#include "Speed.h"
#include "WeaponSpeed.h"
#include "Point.h"

class CUnit {
public:
	CUnit(int level);
	// TODO : CONSTRUCTEUR IA
	~CUnit();

	int		getId() const;
	int		getLevel() const;
	CPoint	getPos() const;
	void	refresh();
	void	setPos();
	bool	shoot() const;
	void	takeDamage(float value);
	bool	isAlive() const;


	CArmor&			getArmor();
	CDamage&		getDamage();
	CHealthPoint&	getHealthPoint();
	CRegeneration&	getRegeneration();
	CScope&			getScope();
	CSpeed&			getSpeed();
	CWeaponSpeed&	getWeaponSpeed();

	CCapacity& operator[](const unsigned int id)
	{
		if (id > 6)
			throw "Error index out of range";

		return *m_capacities[id];
	}

private:
	int			m_id;
	int			m_level;
	CPoint		m_pos;
	CCapacity	*m_capacities[7];
};

#endif

