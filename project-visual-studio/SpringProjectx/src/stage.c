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
static void drawHud(void);
static void drawSupport(void);

static void messageboxC(void);


void initStage(void)
{
	initFonts();
	initSounds();
	loadMusic("music/one_0.mp3");
	playMusic(1);
	app.delegate.logic = logic;
	app.delegate.draw = draw;
	memset(&stage, 0, sizeof(Stage));

	stage.entityTail = &stage.entityHead;
	initEntities();
	initPlayer();
	initMap();
}



static void logic(void)
{
	doPlayer();
	doEntities();
	doCamera();

	if (app.keyboard[SDL_SCANCODE_C]) {
		messageboxC();
	}
}

static void draw(void)
{
	SDL_SetRenderDrawColor(app.renderer, 128, 192, 255, 255);
	SDL_RenderFillRect(app.renderer, NULL);

	drawMap();
	drawEntities();
	drawHud();

	drawSupport();

}

static void drawHud(void)
{
	SDL_Rect r;

	r.x = 0;
	r.y = 0;
	r.w = SCREEN_WIDTH;
	r.h = 35;

	SDL_SetRenderDrawBlendMode(app.renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 196);
	SDL_RenderFillRect(app.renderer, &r);
	SDL_SetRenderDrawBlendMode(app.renderer, SDL_BLENDMODE_NONE);

	drawText(SCREEN_WIDTH - 5, 5, 255, 255, 255, TEXT_RIGHT, "PIZZA %d/%d", stage.pizzaFound, stage.pizzaTotal);
}

static void drawSupport(void)
{

	
drawText(SCREEN_WIDTH -670 , 5, 255, 255, 255, TEXT_RIGHT, "PRESS R:RESET, Q:QUIT, C:CONTROLS");

}


void messageboxC(void) {
	// referenced from https://wiki.libsdl.org/SDL_ShowMessageBox#Version

	const SDL_MessageBoxButtonData buttons[] = {
	{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 0, "OK" },
	};

	const SDL_MessageBoxData messageboxdata = {
		SDL_MESSAGEBOX_INFORMATION,NULL,"Controls","Left: LEFT Key or A, Right : RIGHT Key, Jump : SPACE or W, Reset : R, Quit : Q.",SDL_arraysize(buttons),buttons };
	int buttonid;
	if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
		SDL_Log("error displaying message box");
		return 1;
	}
	if (buttonid == 0) {
		return;
	}


}