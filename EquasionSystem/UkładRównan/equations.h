#pragma once
#include "matrix.h"
#include <iostream>

class EquationSystem {
private:
	matrix mtrx;
	vector vecA;
	double x, y, z;
	vector error;
	bool ifConclusive;
public:
	void solveEquation();
	void loadEquation(std::fstream &file);
	void showSolution() const;
};