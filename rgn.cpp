#include <iostream>
#include <cstdlib>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

/* TODO convert to tempelate to support native type(int, float ...) */
class RGN {
private:
	vector<int>::iterator _it;
	vector<int> _v;
	int _begin;
	int _end;
	int _get() {
		return rand();
	}
	int _get(int range) {
		return rand() % range;
	}
public:
	RGN() {
		srand(time(NULL));
	}
	RGN(int begin, int end, int verbose = 0):_begin(begin), _end(end) {
		srand(time(NULL));
		_init(verbose);
	}
	~RGN() {
		_v.clear();
	}
	void _init(int verbose = 0) {
		if (_end < _begin)
			return;
		for (int i = _begin; i <= _end; ++i)
			_v.push_back(i);
		if (verbose) {
			cout << "init rgn array from " << _begin << " to " << _end << endl;
			for (int i = 0; i <= _end - _begin; ++i)
				cout << _v[i] << " ";
			cout << endl;
		}
	}
	void reset(int begin, int end) {
		_begin = begin;
		_end = end;
		_v.clear();
		_init();
	}
	int get() {
		if (!_v.empty()) {
			int rgn = _get() % _v.size();
			int val = _v[rgn];
			_it = _v.begin();
			_v.erase(_it + rgn);
			return val;
		} else
			return _get();
	}
	int get(int range) {
		return _get(range);
	}
	int size() {
		return _v.size();
	}
	void test() {
		if (!_v.empty()) {
			for (int i = this->size() - 1; i >= 0; --i)
				cout << this->get() << " ";
			cout << endl;
		} else
			cout << "rgn is empty" << endl;
	}
	void test(int range) {
		cout << "test 30 times random with range " << range << ":" << endl;
		for(int i = 0; i < 30; ++i)
			cout << _get(range) << " ";
		cout << endl;
	}
	void clear() {
		_v.clear();
	}

	static vector<int> getVec(int begin, int end) {
		vector<int> __v;
		RGN _rgn(begin, end, 0);
		srand(time(NULL));
		if (end < begin)
			return __v;
		for (int i = end - begin; i >= 0; --i)
			__v.push_back(_rgn.get());
		return __v;
	}
	static void dumpVec(vector<int> v) {
		for(int i = 0; i < v.size(); ++i)
			cout << v[i] << " ";
		cout << endl;
	}
};

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
