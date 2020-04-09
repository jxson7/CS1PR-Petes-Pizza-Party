/* Author: Jason Jay Dookarun
Date of Creation: 09.04.2020

The following section has been designed as a modification to the existing software
designed by Parallel Realities. This addition introduces a home "splash" screen to 
greet the user to prior to their experiences of the game. Prompts and key shortcuts 
are introduced to the user to 1) commence the game in a correct manner, and 2) to 
provide the user with further details on the objective of the game as well as how to 
play the game via a provided control panel. 

*/

#include "common.h"

static void logic(void);
static void draw(void);
static void messageboxC(void);
static void messageboxYesNo(void);

static void messageboxH(void);
static SDL_Texture* sdl2Texture;
static SDL_Texture* logo;
static SDL_Texture* space;
static int reveal = 0;
static int timeout;
static int backgroundX;
static SDL_Texture* background;
static int backgroundX = 0;


static void logic(void)
{
	if (--backgroundX < -SCREEN_WIDTH){
		backgroundX = 0;
	}

	if (reveal < SCREEN_HEIGHT){
		reveal++;
	}

	if (app.keyboard[SDL_SCANCODE_SPACE]){
		Mix_HaltChannel(-1);

		initStage();
	}
	if (app.keyboard[SDL_SCANCODE_H]) {
		messageboxH();
	}
	if (app.keyboard[SDL_SCANCODE_C]) {
		messageboxC();
	}
	if (app.keyboard[SDL_SCANCODE_Q]) {
		messageboxYesNo();
	}

}


static void draw(void)
{
	SDL_Rect screen;
	int x;

	for (x = backgroundX; x < SCREEN_WIDTH; x += SCREEN_WIDTH){
		screen.x = x;
		screen.y = 0;
		screen.w = SCREEN_WIDTH;
		screen.h = SCREEN_HEIGHT;
		SDL_RenderCopy(app.renderer, background, NULL, &screen);
	}
	SDL_Rect r;
	r.x = 0;
	r.y = 0;

	SDL_QueryTexture(logo, NULL, NULL, &r.w, &r.h);
	r.h = MIN(reveal, r.h);
	loadText(logo, &r, (SCREEN_WIDTH / 2) - (r.w / 2), 250);
	drawText(SCREEN_WIDTH / 2, 450, 255, 255, 255, TEXT_CENTER, "PRESS SPACE TO PLAY!");
	drawText(SCREEN_WIDTH / 2, 500, 255, 255, 255, TEXT_CENTER, "PRESS C FOR CONTROLS");
	drawText(SCREEN_WIDTH / 2, 550, 255, 255, 255, TEXT_CENTER, "PRESS H FOR HELP");
	
}

void initTitle(void)
{
	app.delegate.logic = logic;
	app.delegate.draw = draw;
	background = loadTexture("gfx/backgroundNew.png");
	logo = loadTexture("gfx/logo.png");
	loadMusic("music/kr.mp3");
	playMusic(1);
}

void messageboxH(void) {
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Welcome!" ,"Hi and welcome To Pete's Pizza Hunt! We have lost 11 slices of pizza and your mission is to find them! To check your progress, look at the HUD on top right-hand side. Good luck!", NULL);
}

void messageboxC(void) {
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Controls", " Left: LEFT Key or A, Right : RIGHT Key, Jump: SPACE or W, Reset: R, Quit: Q.", NULL);

}

void messageboxYesNo(void) {
	// referenced from https://wiki.libsdl.org/SDL_ShowMessageBox#Version

	const SDL_MessageBoxButtonData buttons[] = {
	{ SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 0, "No" },
	{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Yes" },
	};

	const SDL_MessageBoxData messageboxdata = {
		SDL_MESSAGEBOX_INFORMATION,NULL,"Exit Game","Do you wish to exit the game?",SDL_arraysize(buttons),buttons };
	int buttonid;
	if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
		SDL_Log("error displaying message box");
		return 1;
	}
	if (buttonid == 1) {
		exit(0);
	}
	else {
		return;

	}
}
