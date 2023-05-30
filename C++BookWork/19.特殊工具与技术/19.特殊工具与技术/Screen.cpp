#include "Screen.h"


Screen::Action2 Screen::Menu[] =
{
	&Screen::home,
	&Screen::forward,
	&Screen::back,
	&Screen::up,
	&Screen::down,
};

Screen::Screen(): cursor(0), height(0), width(0)
{
}


Screen::~Screen()
{
}
