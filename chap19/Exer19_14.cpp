#include "Exer19_12_Screen.h"
int main()
{
	auto pmf = &Screen::get_cursor;
	pmf = &Screen::get; // ok: one version of get has the same type as get_cursor
	return 0;
}