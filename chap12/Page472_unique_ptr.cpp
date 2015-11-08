#include <iostream>
#include <string>
#include <memory>
using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;
struct destination{
	string ip;
	unsigned short port;
	destination() = default;
	destination(const string& i, unsigned short p) : ip(i), port(p) {}
};
struct connection{
	string ip_dst;
	unsigned short port_dst = 0;
	unsigned short port_local = 0;
	connection() = default;
	connection(const string& is, unsigned short ps, unsigned short pl) : ip_dst(is), port_dst(ps), port_local(pl) {}
	connection(const destination &p, unsigned short pl) : ip_dst(p.ip), port_dst(p.port), port_local(pl) {}
};
connection connect(destination *d)
{
	return connection(*d, 6124);
}
void disconnect(connection &con)
{
	con.ip_dst.clear();
	con.port_dst = 0;
}
void end_connect(connection *p)
{
	disconnect(*p);
	cout << "connection closed." << endl;
}
void f(destination &d)
{
	connection c = connect(&d);
	// use unique_ptr to substitute shared_ptr
	unique_ptr<connection, void(*)(connection *p)> p(&c, end_connect); 
	cout << "connection between local and destination (" << d.ip << ", " << d.port <<") is setup" << endl;
}
int main()
{
	destination dst("192.168.1.102", 0);
	f(dst);
	return 0;
}