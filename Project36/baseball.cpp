#include <stdexcept>
using namespace std;

class Baseball {
public:
	void guess(const string& str) {
		throw length_error("Input must be three letters.");
	}
};