#include <iostream>
#include <string>
#include <memory>
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
struct destination{
    string ip;
    unsigned short port;
    destination() = default;
    destination(const string& i, unsigned short p) : ip(i), port(p) {}
};
struct connection{
    string ip_dst;
    unsigned short port_dst = 0;
    connection() = default;
    connection(const string& is, unsigned short ps) : ip_dst(is), port_dst(ps) {}
};
connection connect(destination *d)
{
    return connection(d->ip, d->port);
}
void disconnect(connection &con)
{
    con.ip_dst.clear();
    con.port_dst = 0;
}
void end_connect(connection *p)
{
    disconnect(*p);
}
void f(destination &d)
{
    connection c = connect(&d);
    shared_ptr<connection> p(&c, end_connect);
    cout << "connection closed." << endl;
}
int main()
{
    destination dst("192.168.1.102", 0);
    f(dst);
    return 0;
}
