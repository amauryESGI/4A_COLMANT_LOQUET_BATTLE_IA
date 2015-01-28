#ifndef _CAPACITY_H
#define _CAPACITY_H

enum ECapacities : unsigned int {
	Speed,
	HealthPoint,
	Armor,
	Regeneration,
	Damage,
	Scope,
	WeaponSpeed
};

class CCapacity
{
public:
	CCapacity();
	~CCapacity();

	void	upgrade();
	void	downgrade();
	size_t	getLevel();
	float	getValue();

private:
	size_t	m_level;
	float	m_value;

	void virtual	computeValue() = 0;
};

#endif