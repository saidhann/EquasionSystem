#include "equations.h"


std::fstream commandlineArguments(char *FileName) {
	std::fstream file;
	file.open(FileName, std::ios::in);

	return file;
}
int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Missing the commandline argument with the file name\n";
	}
	std::fstream file = commandlineArguments(argv[1]);
	if (!file.is_open()) {
		std::cout << "Failed to open the file\n";
		return 0;
	}
	EquationSystem newEquation;
	newEquation.loadEquation(file);
	if (file.fail()) {
		std::cout << "Failed to load the equasion\n";
		return 0;
	}
	newEquation.solveEquation();
	newEquation.showSolution();
	return 0;
}