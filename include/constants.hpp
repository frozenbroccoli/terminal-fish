#pragma once
#include <string_view>
#include <iostream>


namespace object {
	inline constexpr std::string_view FISH = "\x1B[1;44;37m fish \x1B[0m";
}

namespace action {
	inline constexpr auto clear = []() {
		std::cout << "\x1B[2J\x1B[H"; 
	};

	inline constexpr auto bold = []() {
		std::cout << "\x1B[0;1m"; 
	};

	inline constexpr auto go_to = [](int row, int col) {
		std::cout << "\x1B[" << row << ";" << col << "H";
	};
}

