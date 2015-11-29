#ifndef EXER16_07_1H
#define EXER16_07_1H
template <typename T, unsigned N>
inline constexpr unsigned size(const T(&arr)[N])
{
	return N;
}
#endif