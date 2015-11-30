template <typename T> class Pal; // forward declaration of template class Pal
// A_P is a plain class
class A_P {
	friend class B_P; // B_P is a non-template class, needn't forward declaration
	friend class Pal<A_P>; // Pal is a template class, its instantiation Pal<A_P> is a friend, need forward declaration
	template <typename T> friend class Pal2; // Pal2 is a template class, all of its instantiations are friends of A_P, needn't forward declaration
};
// A_T is a template class
template <typename T> class A_T {
	friend class B_P; // B_P is a template class, needn't forward declaration
	friend class Pal<T>; // Pal is a template class, its instantiation Pal<T> is a friend, need forward declaration
	template <typename X> friend class Pal2; // Pal2 is a template class, all of its instantiations are friends of A_T, needn't forward declaration
};
int main()
{
	return 0;
}
// Note: if a specific instantiation of a template class wants to be a friend, 
// the declaration of that template must be declared. If all of the instantiations
// of a template class want to be friends, forward declaration is not needed.