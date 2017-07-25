// Warning: this is for illustration. It cannot compile.
namespace blip {
    int i = 16, j = 15, k = 23;
}
int j = 0; // ok: j inside blip is hidden inside a namespace
int main()
{
    // using directive; the name in blip are "added" to the global scope
    using namespace blip; // clash between ::j and blip::j
                          // detected only if j is used
    ++i;        // sets blip i = 17
    ++j;        // error ambiguous: global j or blip::j?
    ++::j;      // ok: sets global j to 1
    ++blip::j;  // ok: sets blip::j to 16
    int k = 97; // local k hides blip::k
    ++k;        // sets local k to 98
    return 0;
}
