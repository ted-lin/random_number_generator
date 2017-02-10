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
	int _get();
	int _get(int range);
public:
	RGN();
	RGN(int begin, int end, int verbose = 0);
	~RGN();
	void _init(int verbose = 0);
	void reset(int begin, int end);
	int get();
	int get(int range);
	int size();
	void test();
	void test(int range);
	void clear();
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
