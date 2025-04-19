#include <iostream>
#include <chrono>
#include <thread>
#include <sys/ioctl.h>
#include <unistd.h>
#include "include/constants.hpp"


void play_startup_animation(int term_width, int term_height) {
	int center_x = term_width / 2;
	int center_y = term_height / 2;

	action::clear();
	action::go_to(center_y, center_x);
	std::cout << "\x1B[1;37m";

	constexpr auto sleep = [](int ms) {
		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	};

	constexpr auto flush = [sleep](const char* text, int ms) {
		std::cout << text << std::flush; sleep(ms);
	};

	flush("f", 200);
	flush("i", 200);
	flush("s", 200);
	flush("h", 200);
	flush(" ", 500);

	std::cout << "\x1B[3;37;44m";

	flush("t", 200);
	flush("e", 200);
	flush("r", 200);
	flush("m", 200);
	flush("i", 200);
	flush("n", 200);
	flush("a", 200);
	flush("l", 200);

	std::cout << "\x1B[0m" << std::endl;
	action::clear();
}


int main() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	int width = static_cast<int>(w.ws_col);
	int height = static_cast<int>(w.ws_row);
	play_startup_animation(width, height);
}

