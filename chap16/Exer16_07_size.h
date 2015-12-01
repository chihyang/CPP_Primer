#ifndef EXER16_07_SIZE_H
#define EXER16_07_SIZE_H
template <typename T, unsigned N>
inline constexpr unsigned size(const T(&arr)[N])
{
	return N;
}
#endif