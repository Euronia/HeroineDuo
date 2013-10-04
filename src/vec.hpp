#ifndef VEC_HPP
#define VEC_HPP


template<typename T>
struct T_Vector
{
	T x;
	T y;

	T_Vector() { x = 0; y = 0; }
	T_Vector(int a, int b) { x = a; y = b; }
	T_Vector operator+(T other) { return T(x+other.x, y+other.y); }
	T_Vector operator-(T other) { return T(x-other.x, y-other.y); }
};

typedef T_Vector<int> T_Vec;
typedef T_Vector<float> T_VecF;


#endif
