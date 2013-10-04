#include <stdio.h>

#include "character.hpp"
#include "map.hpp"


T_Character::T_Character(T_Map *map, T_Vec hitboxSize, T_Vec startPos, T_Dir startDir)
{
	this->map = map;
	this->hitboxSize = hitboxSize;
	this->pos = startPos;
	this->dir = startDir;
}

void T_Character::setWalkAnim(T_AnimSet walkAnim)
{
	this->walkAnim = walkAnim;
}

void T_Character::turn(T_Dir newDir)
{
	dir = newDir;
}

void T_Character::walk(T_Dir primaryDir, T_Dir secondaryDir)
{
	dir = primaryDir;

	T_Vec newPos = pos;
	if(primaryDir == DIR_UP || secondaryDir == DIR_UP)
		newPos.y -= 1;
	if(primaryDir == DIR_LEFT || secondaryDir == DIR_LEFT)
		newPos.x -= 1;
	if(primaryDir == DIR_DOWN || secondaryDir == DIR_DOWN)
		newPos.y += 1;
	if(primaryDir == DIR_RIGHT || secondaryDir == DIR_RIGHT)
		newPos.x += 1;

	if(!map->checkCollision(newPos))
	{
		pos = newPos;
		animState->setAnim(walkAnim[primaryDir]);
		animState->play();
	}
}

void T_Character::teleport(T_Vec dest)
{
}
