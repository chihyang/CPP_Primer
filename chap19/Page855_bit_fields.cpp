// Warning: this is for verification. Class definitions should be put into header file.
#include <iostream>
using std::cout;
using std::endl;
typedef unsigned int Bit;
class File {
    Bit mode: 2;       // mode has 2 bits
    Bit modified: 1;   // modified has 1 bit
    Bit prot_owner: 3; // prot_owner has 3 bits
    Bit prot_group: 3; // prot_group has 3 bits
    Bit prot_world: 3; // prot_world has 3 bits
public:
    // file modes specified as octal literals
    enum modes { READ = 01, WRITE = 02, EXECUTE = 03 };
    File& open(modes);
    void close();
    void write();
    bool isRead() const;
    bool isWrite() const;
    bool isExecute() const;
    void setRead();
    void setWrite();
    void setExecute();
};
void File::write()
{
    modified = 1;
    // other operations for writing
}
void File::close()
{
    if(modified)
    {} // ...save contents
}
File& File::open(File::modes m)
{
    mode |= READ; // set the READ bit by default
    // other processing
    if (m & WRITE) // if opening READ and WRITE
    {} // processing to open the file in read/write mode
    return *this;
}
// define inline member to test and set the value of bit-field
inline bool File::isRead() const { return mode & READ; }
inline bool File::isWrite() const { return mode & WRITE; }
inline bool File::isExecute() const { return mode & EXECUTE; }
inline void File::setRead() { mode |= READ; }
inline void File::setWrite() { mode |= WRITE; }
inline void File::setExecute() { mode |= EXECUTE; }
int main()
{
    File f;
    f.setWrite();
    f.setRead();
    f.setExecute();
    cout << f.isRead() << endl;
    cout << f.isWrite() << endl;
    cout << f.isExecute() << endl;
    return 0;
}
