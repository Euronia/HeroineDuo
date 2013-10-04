#include <stdio.h>

#include "anim.hpp"


void T_Anim::addFrame(const T_AnimFrame &frame)
{
	if(numFrames < MAX_FRAMES)
		frames[numFrames++] = frame;
}

T_Anim anims[NUM_ANIMS];

void definedAnims()
{
	T_Anim *anim = 0;
#define DEFINE_ANIM(code) anim = &anims[code];
#define ADD_ANIM_FRAME(bitmap, length) pAnim->addFrame(CAnimFrame(bitmap, length));
#include "animations.hpp"
}


T_AnimState::T_AnimState()
{
	anim = 0;
	started = false;
}

void T_AnimState::setAnim(int animId)
{
	anim = &anims[animId];
}

void T_AnimState::play()
{
	started = true;
	currentFrame = 0;
	frameStartTime = GetTime();
}

void T_AnimState::stop()
{
	started = false;
}

void T_AnimState::render(CVec pos)
{
	if(!anim || !started)
		return;

	int currentTime = getTime();
	while(1)
	{
		int frameLength = anim->frames[currentFrame].length;
		int frameEndTime = frameStartTime + frameLength;
		if(currentTime >= frameEndTime)
			break;
		currentFrame++;
		frameStartTime = frameEndTime;
		if(currentFrame >= anim->numFrames)
		{
			started = false;
			return;
		}
	}

	int bitmap = anim->frames[currentFrame].bitmap;
	graphics->renderBitmap(bitmap, pos, size);
}
