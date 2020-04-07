/*
Copyright (C) 2015-2018 Parallel Realities

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#include "common.h"

static void logic(void);
static void draw(void);

static SDL_Texture* sdl2Texture;
static SDL_Texture* shooterTexture;
static int reveal = 0;
static int timeout;

void initTitle(void)
{
	app.delegate.logic = logic;
	app.delegate.draw = draw;

	memset(app.keyboard, 0, sizeof(int) * MAX_KEYBOARD_KEYS);

	sdl2Texture = loadTexture("gfx/pizza.png");
	shooterTexture = loadTexture("gfx/pizzabackground.png");

}

static void logic(void)
{
	drawMap();


	if (reveal < SCREEN_HEIGHT)
	{
		reveal++;
	}

	if (app.keyboard[SDL_SCANCODE_LCTRL])
	{
		initStage();
	}
}

static void draw(void)
{
	drawMap();


	if (timeout % 40 < 20)
	{
		drawText(SCREEN_WIDTH / 2, 600, 255, 255, 255, TEXT_CENTER, "PRESS CTRL TO PLAY!");
	}
}


