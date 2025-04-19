#include <sys/ioctl.h>
#include <unistd.h>
#include "include/constants.hpp"
#include "include/colors.hpp"


void play_startup_animation(int term_width, int term_height) {
	int center_x = term_width / 2;
	int center_y = term_height / 2;

	action::clear();
	action::home();
	action::hide_cursor();
	action::go_to(center_y, center_x - 7);
	action::bold();
	action::set_blinking();

	action::color(ForegroundColor::BRIGHT_YELLOW, BackgroundColor::DEFAULT);
	action::flush(object::CURSOR, 1000);

	action::write_char("f", object::CURSOR, 200);
	action::write_char("i", object::CURSOR, 200);
	action::write_char("s", object::CURSOR, 200);
	action::write_char("h", object::CURSOR, 200);
	action::write_char(" ", object::CURSOR, 1000);

	action::italic();
	action::color(ForegroundColor::BRIGHT_WHITE, BackgroundColor::BLUE);

	action::write_char(" ", object::CURSOR, 200);
	action::write_char("t", object::CURSOR, 200);
	action::write_char("e", object::CURSOR, 200);
	action::write_char("r", object::CURSOR, 200);
	action::write_char("m", object::CURSOR, 200);
	action::write_char("i", object::CURSOR, 200);
	action::write_char("n", object::CURSOR, 200);
	action::write_char("a", object::CURSOR, 200);
	action::write_char("l", object::CURSOR, 500);

	action::backspace();
	action::reset_style();
	action::unset_blinking();
	action::color(ForegroundColor::BRIGHT_BLUE, BackgroundColor::DEFAULT);

	action::flush(" ", 100);
	action::flush(object::R, 100);
	action::flush(object::R, 100);
	action::flush(object::R, 100);
	action::flush(object::RD, 100);
	action::flush(object::RLOWER, 100);
	action::flush(object::RLOWER, 100);
	action::flush(object::RLOWER, 100);
	action::flush(object::UR, 100);
	action::flush(object::R, 100);
	action::flush(object::R, 100);
	action::flush(object::R, 100);
	action::flush(object::RU, 100);
	action::up(1);
	action::flush(object::RLOWER, 100);
	action::flush(object::RLOWER, 100);
	action::flush(object::RLOWER, 100);
	action::down(1);
	action::flush(object::DR, 100);
	action::flush(object::R, 100);
	action::flush(object::R, 100);
	action::flush(object::R, 3000);

	action::show_cursor();
	action::clear();
	action::home();
}


int main() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	int width = static_cast<int>(w.ws_col);
	int height = static_cast<int>(w.ws_row);
	play_startup_animation(width, height);
}

