#ifndef _UNIT_H_
#define _UNIT_H_

#include "stdafx.h"

enum IACODE { LD // ennemi le plus proche
			, HD // ennemi le plus loin
			, L0 // ennemi qui a le moins de vitesse
			, H0 // ennemi qui a le plus de vitesse
			, L1 // ennemi qui a le moins de point de vie
			, H1 // ennemi qui a le plus de point de vie
			, L2 // ennemi qui a le moins de point d'armure
			, H2 // ennemi qui a le plus de point d'armure
			, L3 // ennemi qui a le moins de point de vie regeneré par tour
			, H3 // ennemi qui a le plus de point de vie regeneré par tour
			, L4 // ennemi qui a le moins de dommage
			, H4 // ennemi qui a le plus de dommage
			, L5 // ennemi qui a le moins de portée
			, H5 // ennemi qui a le plus de portée
			, L6 // ennemi qui a le moins de cooldown
			, H6 // ennemi qui a le plus de cooldown
			};

class CUnit
{
public:
	CUnit(int level);
	CUnit(IACODE codeIA, int speed, int health, int armor, int regeneration, int damage, int scope, int weaponSpeed);
	~CUnit();

	int		getId() const;
	int		getLevel() const;
	CPoint	getPos() const;
	IACODE	getIACode() const;
	void	refresh();
	void	setPos(CPoint pos);
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
			throw "Error index out of range ... How did you do that O_O";

		return *m_capacities[id];
	}

private:
	static int	m_id;
	int			m_level;
	CPoint		m_pos;
	CCapacity	*m_capacities[7];
	IACODE		m_codeIA;
};

#endif
