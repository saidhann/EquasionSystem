#pragma once
#include "Vector.h"
#include <fstream>


class matrix {
private:
	vector vct[MATRIXSIZE];
public:
	vector &operator [](int Index);
	double calculateDeterminant() const;
	void transposeMatrix();
	vector operator* (vector const& vec);
};
std::istream& operator >>(std::istream& Stream, matrix mtx);