#include <iostream>
#include "Exer15_11_Quote.h"
#include "Exer15_11_Bulk_quote.h"
#include "Exer15_11_Limit_quote.h"
using std::cout;
int main()
{
    Quote item1("978-7-121-20038-0", 128.0);
    Bulk_quote item2("978-7-121-20038-0", 128.0, 6, 0.05);
    Limit_quote item3("978-7-121-20038-0", 128.0, 2, 0.05);
    Quote &item_r1 = item1;
    item_r1.debug(); // calls Quote::net_price
    item_r1 = item2; // assign item1 with the subobject of item2, rather than binds item_r1 to item2
    item_r1.debug(); // calls Quote::net_price
    item_r1 = item3; // assign item1 with the subobject of item3, rather than binds item_r1 to item3
    item_r1.debug(); // calls Quote::net_price
    Quote &item_r2 = item2;
    item_r2.debug(); // calls Bulk_quote::net_price
    Quote &item_r3 = item3;
    item_r3.debug(); // calls Limit_quote::net_price
    Quote *item_p = &item1;
    item_p->debug(); // calls Quote::net_price
    item_p = &item2;
    item_p->debug(); // calls Bulk_quote::net_price
    item_p = &item3;
    item_p->debug(); // calls Limit_quote::net_price
    return 0;
}
// Note: remember that THERE IS NO WAY to rebind a reference to a different
// object(see page 50, chapter 2)!
// Thus if we initialize a reference to a base type with an object of base type,
// the reference is ALWAYS referring to the original base-type object. After we
// assign this reference with an object of derived type, the subobject of that
// derived type object is assigned to the original object. Then if we call a
// virtual function on the reference, because the dynamic type of that reference
// is base type, base version of the virtual function is called. This is a little
// long-winded, but make sure you make it out.
// On the other hand, because we can make a (nonconst) pointer point to a different
// object, each time after we assign a pointer with an object of different derived
// type, the dynamic type of the pointer is the derived type. Thus when we call
// a virtual function, the derived version is called.
// In a word, once we define and initialize an reference of base type, the dynamic
// type of that reference cannot change; if we define a (nonconst) pointer of base
// type, we can make the pointer point to different derived types.
