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
	CUnit(const int level);
	CUnit(const IACODE codeIA, const int speed, const int health, const int armor, const int regeneration, const int damage, const int scope, const int weaponSpeed);
	~CUnit();

	int		getId() const;
	int		getLevel() const;
	CPoint	getPos() const;
	IACODE	getIACode() const;
	void	refresh() const;
	void	setPos(const CPoint &pos);
	bool	shoot() const;
	void	takeDamage(const float value);
	bool	isAlive() const;


	CArmor&			getArmor() const;
	CDamage&		getDamage() const;
	CHealthPoint&	getHealthPoint() const;
	CRegeneration&	getRegeneration() const;
	CScope&			getScope() const;
	CSpeed&			getSpeed() const;
	CWeaponSpeed&	getWeaponSpeed() const;

	CCapacity& operator[](const unsigned int id) const
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
