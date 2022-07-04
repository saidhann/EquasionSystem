#pragma once
#include <istream>
#define MATRIXSIZE 3

class vector {
private:
	double value[MATRIXSIZE];
public:
	vector (double first, double second, double third);
	vector();
	double &operator [](int index);
	const double& operator [](int index) const;
	double operator * (vector const& second) const;
	vector operator = (vector const& second);
	vector operator - (vector const& second) const;
};
std::istream& operator >>(std::istream& strm, vector& vec);