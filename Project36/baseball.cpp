#include <stdexcept>
using namespace std;

class Baseball {
public:
	void guess(const string& str) {
		if (str.length() != 3) {
			throw length_error("Input must be three letters.");
		}
		for (char c : str) {
			if (c < '0' || c > '9') {
				throw invalid_argument("Input must be number.");
			}
		}
	}
};