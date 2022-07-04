#include "equations.h"
#include <assert.h>


void EquationSystem::solveEquation() {
	ifConclusive = false;
	matrix MatX, MatY, MatZ;
	double DET, detX, detY, detZ;
	MatX = MatY = MatZ = mtrx;
	MatX[0] = vecA;
	MatY[1] = vecA;
	MatZ[2] = vecA;
	DET = mtrx.calculateDeterminant();
	if (!DET) return;
	detX = MatX.calculateDeterminant();
	detY = MatY.calculateDeterminant();
	detZ = MatZ.calculateDeterminant();
	x = detX / DET;
	y = detY / DET;
	z = detZ / DET;
	vector VecXYZ;
	VecXYZ[0] = x;
	VecXYZ[1] = y;
	VecXYZ[2] = z;
	error = mtrx * VecXYZ - vecA;
	ifConclusive = true;
}
void EquationSystem::loadEquation(std::fstream &file) {
	file >> mtrx;
	file >> vecA;
	if (file.fail()) return;
	mtrx.transposeMatrix();
}
void EquationSystem::showSolution() const {
	std::ostream& c = std::cout;
	if (!ifConclusive) {
		c << "Equasion does not have conclusive solution\n";
		return;
	}
	c << "Equasion system solucion:" << "\n";
	c << "x = " << x <<"\n";
	c << "y = " << y <<"\n";
	c << "z = " << z <<"\n";
	c << "Error values:" << "\n";
	c << "error(x) "<< error[0] << "\n";
	c << "error(y) " << error[1] << "\n";
	c << "error(z) " << error[2] << "\n";
}