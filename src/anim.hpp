#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "vec.hpp"


enum
{
	ANIM_INVALID=-1,
#define DEFINE_ANIM(code) code,
#define ADD_ANIM_FRAME(bitmap, length)
#include "anims.hpp"
	NUM_ANIMS
};

struct T_AnimFrame
{
	int bitmap;
	int length;
	T_AnimFrame() { bmp = BITMAP_INVALID; length = 0; }
	T_AnimFrame(int bmp, int len) { bitmap = bmp; length = len; }
};

struct T_Anim
{
	enum
	{
		MAX_FRAMES=16
	};

	T_AnimFrame frames[MAX_FRAMES];
	int numFrames;

	void addFrame(const T_AnimFrame &frame);
};

extern T_Anim anims[NUM_ANIMS];

void definedAnims();


class T_AnimState
{
private:
	class CGraphics *graphics;
	T_Anim *anim;
	bool started;
	int currentFrame;
	int frameStartTime;

public:
	T_AnimState(class CGraphics *graphics);
	void setAnim(int animId);
	void play();
	void stop();
	void render(T_Vec pos);
};


#endif
