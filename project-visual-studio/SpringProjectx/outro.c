/* Author: Jason Jay Dookarun
Date of Creation: 09.04.2020

The following section has been designed as a modification to the existing software
designed by Parallel Realities. This addition introduces exit screen to. Similar to the homescreen
panel, similar methods are implemented with alternative commands added such as a replay method or exit. 


*/

#include "common.h"
// The following declarations interlink with common.h and apply the logic and draw standards followed by 
// SDL2 libraries. 
static void logic(void);
static void draw(void);
//implements exit message box
static void messageboxYesNo(void);

static SDL_Texture* bckgrndTexture;
static SDL_Texture* logo;
static SDL_Texture* space;
static int reveal = 0;
static int timeout;
static int existingBackground;
static SDL_Texture* background;
static int existingBackground = 0;

// initiates the loading of the graphics and plays the background audio,

void initOutro(void)
{
	Mix_HaltChannel(-1);
	app.delegate.logic = logic;
	app.delegate.draw = draw;
	background = loadTexture("gfx/outro.png");
	logo = loadTexture("gfx/missionaccomplished.png");
	// Music from : https://www.bensound.com
	loadMusic("music/bensound-erf.mp3");
	playMusic(1);
}

// this section implements the reveal of the contents that are to be displayed on the screen, and controls that are to be entered by the user

static void logic(void)
{
	if (--existingBackground < -SCREEN_WIDTH) {
		existingBackground = 0;
	}

	if (reveal < SCREEN_HEIGHT) {
		reveal++;
	}
	// restarts the game by transferring the client to the introductory splash screen 
	if (app.keyboard[SDL_SCANCODE_P]) {
		initTitle();
	}
	// similar to homescreen.c, allows the user to meet the exit message box to confirm their decision. 
	if (app.keyboard[SDL_SCANCODE_Q]) {
		messageboxYesNo();
	}

}

/* This draw mechanism has been referenced from homescreen.c, map.c and Parallel Realities (link above). This method allows the
projection of the main splash screen by drawing the screne via app renders. Once the wallpaper has been rendered, the
user is then projected the logo, as well as instructions/controls.
*/
static void draw(void)
{
	SDL_Rect screen;
	int x;

	for (x = existingBackground; x < SCREEN_WIDTH; x += SCREEN_WIDTH) {
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
	// projected onto wallpaper as a visible instruction

	drawText(SCREEN_WIDTH / 2, 450, 255, 255, 255, TEXT_CENTER, "PRESS P TO PLAY AGAIN!");
	drawText(SCREEN_WIDTH / 2, 500, 255, 255, 255, TEXT_CENTER, "PRESS Q FOR QUIT");
	

}

/* messageBoxYesNo implements an exit strategy to exit the game for the client without a forceful termination.
*/
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
