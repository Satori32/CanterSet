#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <random>
#include <tuple>
#include <cmath>

typedef std::vector<std::uint16_t> DType;

DType SepDigit(double N, std::uintmax_t R, std::uintmax_t K=16) {

	if (N >= 1) { return {}; }

	DType V;

	for (std::uintmax_t i = 0; N && (i < K); i++) {
	
		V.push_back(std::floor(N*R));
		N *=R;
		N -= (std::floor(N));

	}
	return V;
}

bool IsCanter(const DType& V) {
	auto it = std::find(V.begin(), V.end(), 1);
	return it == V.end();
}

int main() {

	std::vector<std::tuple<DType, double>> D;
	std::uintmax_t L = 1024;
	std::uintmax_t Dz = 12;

	std::random_device rd;
	std::mt19937 mt(0);
	std::uniform_real_distribution<double> UI(0, 1);

	double Z = 0;
	for (std::size_t i = 0; i < 8; i++) {
		Z += 2;
		Z /= 3;
	}

	auto T = SepDigit(Z, 3,Dz);
	if (IsCanter(T)) { D.push_back({ T,Z }); }
	else {
		std::cout << "Miss The " << Z << std::endl;
		for (auto& o : T) {
			std::cout << o << ",";
		}
		std::cout << std::endl;
	}

	for (std::uintmax_t i = 0; i < L; i++) {
		auto Y = UI(mt);
		auto X = SepDigit(Y, 3,Dz);
		if (IsCanter(X)) { D.push_back({ X,Y }); }
		else {
			std::cout << "Miss The " << Y << std::endl;
			for (auto& o : X) {
				std::cout << o << ",";
			}
			std::cout << std::endl;
		}
	}



	for (auto& oo : D) {
		std::cout << "Safe The " << std::get<1>(oo) << std::endl;
		for (auto& o : std::get<0>(oo)) {
			std::cout << o << ",";
		}
		std::cout << std::endl;
	}
	return 0;

}