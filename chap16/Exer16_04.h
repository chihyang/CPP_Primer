#ifndef EXER16_04_H
#define EXER16_04_H
template <typename TI, typename TV>
TI find(TI begin, TI end, const TV &val)
{
	while(begin != end)
	{
		if(*begin == val)
			return begin;
		++begin;
	}
	return end;
}
#endif