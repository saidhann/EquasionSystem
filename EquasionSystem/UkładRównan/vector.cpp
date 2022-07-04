#include "Vector.h"

vector::vector(double first, double second, double third) {
	(*this)[0] = first;
	(*this)[1] = second;
	(*this)[2] = third;
}
vector::vector() {
	(*this)[0] = 0;
	(*this)[1] = 0;
	(*this)[2] = 0;
}
double &vector::operator [](int index) {
	return { value[index] };
}
const double& vector::operator [](int index) const {
	return { value[index] };
}
double vector::operator * (vector const& second) const{
	return {value[0]*second.value[0]+ value[1] * second.value[1] + value[2] * second.value[2]};
}
vector vector::operator = (vector const& second) {
	value[0] = second.value[0];
	value[1] = second.value[1];
	value[2] = second.value[2];
	return *this;
}
vector vector::operator - (vector const& second) const {
	return { (*this)[0] - second[0],(*this)[1] - second[1], (*this)[2] - second[2] };
}
std::istream& operator >>(std::istream& strm, vector& vec) {
	for (int i = 0; i < 3; i++) strm >> vec[i];
	return strm;
}