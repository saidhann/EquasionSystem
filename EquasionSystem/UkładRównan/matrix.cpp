#include "matrix.h"

double matrix::calculateDeterminant() const {
	return { vct[0][0]*vct[1][1]*vct[2][2] + vct[1][0]*vct[2][1]*vct[0][2] + vct[2][0]*vct[0][1]*vct[1][2] - vct[2][0]*vct[1][1]*vct[0][2] - vct[2][2]*vct[0][1]*vct[1][0] - vct[0][0]*vct[1][2]*vct[2][1] };
}
void matrix::transposeMatrix() {
	matrix TempMtx;
	TempMtx = *this;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) vct[i][j] = TempMtx[j][i];
}
vector matrix::operator* (vector const& vec) {
	return { (*this)[0] * vec,(*this)[1] * vec ,(*this)[2] * vec };
}
vector &matrix::operator[](int Index) {
	return { vct[Index] };
}
std::istream& operator >>(std::istream& strm, matrix mtx) {
	for (int i = 0; i < 3; i++) strm >> mtx[i];
	return strm;
}