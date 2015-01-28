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
	CPoint	getPos()const;
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

	// TODO: Float or Obj ?
	float operator[](const unsigned int id) {
		switch (id) {
		case Speed:
			return m_speed.getValue();
		case HealthPoint:
			return m_healthPoint.getValue();
		case Armor:
			return m_armor.getValue();
		case Regeneration:
			return m_regeneration.getValue();
		case Damage:
			return m_damage.getValue();
		case Scope:
			return m_scope.getValue();
		case WeaponSpeed:
			return m_weaponSpeed.getValue();
		default:
			return 0;
		}
	}

private:
	int				m_id;
	int				m_level;
	CPoint			m_pos;
	CArmor			m_armor;
	CDamage			m_damage;
	CHealthPoint	m_healthPoint;
	CRegeneration	m_regeneration;
	CScope			m_scope;
	CSpeed			m_speed;
	CWeaponSpeed	m_weaponSpeed;
};

#endif

