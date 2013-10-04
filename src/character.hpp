#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "vec.hpp"


enum T_Dir
{
	DIR_UP=0,
	DIR_LEFT,
	DIR_DOWN,
	DIR_RIGHT,
	NUM_DIRS
};

typedef int T_AnimSet[NUM_DIRS];

class T_Character
{
private:
	class T_Map *map;
	T_Vec hitboxSize;
	T_Vec pos;
	T_Dir dir;
	T_AnimState animState;
	T_AnimSet walkAnim;

public:
	T_Character(class T_Map *map, T_Vec hitboxSize, T_Vec startPos, T_Dir startDir);
	void setWalkAnim(T_AnimSet walkAnim);
	void turn(T_Dir newDir);
	void walk(T_Dir primaryDir, T_Dir secondaryDir);
	void teleport(T_Vec dest);
	void render();
	virtual void tick() {}
};


#endif
