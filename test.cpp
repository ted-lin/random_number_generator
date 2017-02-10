#include "rgn.h"

int main () {
	cout << "Random Number Generator (rgn):" << endl;
	RGN rgn(1, 10);
	rgn.test();
	rgn.reset(-10, 10);
	rgn.test();
	rgn.clear();
	rgn.test();
	rgn.test(10);
	vector<int> v = RGN::getVec(1, 10);
	RGN::dumpVec(v);
	RGN::dumpVec(RGN::getVec(-5, 5));
	return 0;
}
