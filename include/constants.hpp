#pragma once
#include <thread>
#include <chrono>
#include <string_view>
#include <iostream>
#include "colors.hpp"


namespace object {
	inline constexpr std::string_view FISH = "\x1B[1;44;37m fish \x1B[0m";
	inline constexpr const char* CURSOR = "\u2588";
}

namespace action {
	inline constexpr auto clear = []() {
		std::cout << "\x1B[2J\x1B[H"; 
	};

	inline constexpr auto reset_style = []() {
		std::cout << "\x1B[0m"; 
	};

	inline constexpr auto bold = []() {
		std::cout << "\x1B[1m"; 
	};

	inline constexpr auto italic = []() {
		std::cout << "\x1B[3m"; 
	};

	inline constexpr auto color = []( ForegroundColor fgcolor, BackgroundColor bgcolor) {
		std::cout << "\x1B[" << static_cast<int>(fgcolor) << ";" << static_cast<int>(bgcolor) << "m"; 
	};

	inline constexpr auto go_to = [](int row, int col) {
		std::cout << "\x1B[" << row << ";" << col << "H";
	};

	inline constexpr auto sleep = [](int ms) {
		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	};

	inline constexpr auto flush = [](const char* text, int sleep_ms) {
		std::cout << text << std::flush; sleep(sleep_ms);
	};

	inline constexpr auto hide_cursor = []() {
		std::cout << "\x1B[?25l";
	};

	inline constexpr auto show_cursor = []() {
		std::cout << "\x1B[?25h";
	};

	inline constexpr auto set_blinking = []() {
		std::cout << "\x1B[5m";
	};

	inline constexpr auto unset_blinking = []() {
		std::cout << "\x1B[25m";
	};

	inline constexpr auto backspace = []() {
		std::cout << "\x08";
	};

	inline constexpr auto write_char = [](const char* c, const char* cursor, int sleep_ms) {
		unset_blinking();
		std::cout << "\x08" << c;
		set_blinking();
		flush(cursor, sleep_ms);
	};
}

