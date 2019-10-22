#include <memory>

using std::shared_ptr;

struct destination {};

struct connection {};

connection connect(destination *) {
	return connection();
}

void disconnect(connection) {}

void f(destination &d) {
	connection c = connect(&d);
        shared_ptr<connection> p(&c, [](connection *p) { disconnect(*p); });
}
