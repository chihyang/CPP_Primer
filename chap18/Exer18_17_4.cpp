// Warning: this is for verification. It cannot compile.
// The problem lie in line 14.
namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
int ivar = 0;
int main()
{
	using namespace Exercise; // Exercise::ivar conflicts with ::ivar, but won't be detected until using
	double dvar = 3.1416; // hides Exercise::dvar
	int iobj = limit + 1; // uses Exercise::limit
	++ivar;   // conflict: Exercise::ivar or ::ivar?
	++::ivar; // uses ::ivar
	return 0;
}
// ******compile info of g++******
// Exer18_17_4.cpp: In function 'int main()':
// Exer18_17_4.cpp:14:4: error: reference to 'ivar' is ambiguous
//   ++ivar;   // conflict: Exercise::ivar or ::ivar?
//     ^
// Exer18_17_4.cpp:8:5: note: candidates are: int ivar
//  int ivar = 0;
//      ^
// Exer18_17_4.cpp:4:6: note:                 int Exercise::ivar
//   int ivar = 0;
//       ^