#pragma once

#include <string>
#include <sstream>
#include <iostream>

/**
 * @brief      This class describes a game object.
 */
class GameObj
{
public:
	GameObj(std::string id);
	/**
	 * @brief      Prints an information about object.
	 *
	 * @param      stream
	 */
	virtual void printInfo() const = 0;
	/**
	 * @brief      return ID
	 *
	 * @return     id
	 */
	inline std::string id() const;
	/**
	 * @brief      Destroys the object.
	 */
	virtual ~GameObj() = default;
protected:
	std::string _ID;
};

std::ostream& operator<<(std::ostream& stream, const GameObj& gameObj);

inline std::string GameObj::id() const
{
	return _ID;
}

/**
 * @brief      This class describes a healt points.
 */
class HP
{
public:
	HP(unsigned hp);

	inline unsigned getHP() const;
	inline void setHP(unsigned hp);

private:
	unsigned _hp;
};

inline unsigned HP::getHP() const
{
	return _hp;
}

inline void HP::setHP(unsigned hp)
{
	_hp = hp;
}


class Character : public virtual GameObj
{
public:
	Character(HP hp, std::string name, std::string id);

	virtual void printInfo() const override;
	inline std::string hp() const;

protected:
	HP _hp;
	std::string _name;
};

inline std::string Character::hp() const
{
	return "[" + std::to_string(_hp.getHP()) + " HP]";
}

class Hurting : public virtual GameObj
{
public:
	Hurting(HP hurtHP, std::string id);

	virtual void printInfo() const override;
	inline std::string hp() const;

protected:
	HP _hurtHP;
};

inline std::string Hurting::hp() const
{
	return "[" + std::to_string(_hurtHP.getHP()) + " HP]";
}

class Player : public Character
{
public:
	Player(HP hp, std::string name, std::string id);

	virtual void printInfo() const override;
};

class Bomb : public Hurting
{
public:
	Bomb(HP hurtHP, std::string id);
};

class Boss : public Character, public Hurting
{
public:
	Boss(HP hp, std::string name, HP hurtingHP, std::string id);

	virtual void printInfo() const override;
};