#include <memory>
using std::make_shared;
using std::shared_ptr;
using std::weak_ptr;
int main()
{
	shared_ptr<int> sp = make_shared<int>(42);
	weak_ptr<int> wp(sp);
	if(shared_ptr<int> np = wp.lock()) //true if np is not null, an artful way to use condition
	{// inside if, np shares its object with sp
		// do something
	}
	return 0;
}