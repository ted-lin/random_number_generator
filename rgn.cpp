#include "rgn.h"

int RGN::_get()
{
	return rand();
}

int RGN::_get(int range)
{
	return rand() % range;
}

RGN::RGN()
{
	srand(time(NULL));
}

RGN::RGN(int begin, int end, int verbose):_begin(begin), _end(end)
{
	srand(time(NULL));
	_init(verbose);
}

RGN::~RGN()
{
	_v.clear();
}

void RGN::_init(int verbose)
{
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

void RGN::reset(int begin, int end)
{
	_begin = begin;
	_end = end;
	_v.clear();
	_init();
}

int RGN::get()
{
	if (!_v.empty()) {
		int rgn = _get() % _v.size();
		int val = _v[rgn];
		_it = _v.begin();
		_v.erase(_it + rgn);
		return val;
	} else
		return _get();
}

int RGN::get(int range)
{
	return _get(range);
}

int RGN::size()
{
	return _v.size();
}

void RGN::test()
{
	if (!_v.empty()) {
		for (int i = this->size() - 1; i >= 0; --i)
			cout << this->get() << " ";
		cout << endl;
	} else
		cout << "rgn is empty" << endl;
}

void RGN::test(int range)
{
	cout << "test 30 times random with range " << range << ":" << endl;
	for(int i = 0; i < 30; ++i)
		cout << _get(range) << " ";
	cout << endl;
}

void RGN::clear()
{
	_v.clear();
}
