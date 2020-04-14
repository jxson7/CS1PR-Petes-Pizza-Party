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
// The following declarations interlink with common.h and apply the logic and draw standards followed by 
// SDL2 libraries. 
static void logic(void);
static void draw(void);
// represents message boxes that will be utilised for controls and game exit mechanisms. 
static void messageboxC(void);
static void messageboxYesNo(void);
static void messageboxH(void);

// the following declarations have been utilised and implemented from Parallel Realities. Link: {https://www.parallelrealities.co.uk/tutorials/shooter/shooter15.php} 
static SDL_Texture* bckgrndTexture;
static SDL_Texture* logo;
static SDL_Texture* space;
static int reveal = 0;
static int timeout;
static int existingBackground = 0;
static SDL_Texture* background;



// this section implements the reveal of the contents that are to be displayed on the screen, and controls that are to be entered by the user
static void logic(void)
{
	// this implements the rear wallpaper screen movement if the dimensions of the wallpaper do not the match the one used. 
	if (--existingBackground < -SCREEN_WIDTH) {
		existingBackground = 0;
	}
	// this counter implements the reveal of the logo that has been utilised 
	if (reveal < SCREEN_HEIGHT) {
		reveal++;
	}

	if (app.keyboard[SDL_SCANCODE_SPACE]){
		// stops existing audio from playing and allows the main stage (i.e. existing gameplay to load) 
		Mix_HaltChannel(-1);
		initStage();
	}
	if (app.keyboard[SDL_SCANCODE_H]) {
		// references to messageboxH to show help menu
		messageboxH();
	}
	if (app.keyboard[SDL_SCANCODE_C]) {
		// references to show controls menu via a message box 
		messageboxC();
	}
	if (app.keyboard[SDL_SCANCODE_Q]) {
		// references to the quit menu via message box prompt(s) 
		messageboxYesNo();
	}

}

/* This draw mechanism has been referenced from map.c and Parallel Realities (link above). This method allows the 
projection of the main splash screen by drawing the screne via app renders. Once the wallpaper has been rendered, the 
user is then projected the logo, as well as instructions/controls. 
*/
static void draw(void)
{
	SDL_Rect screen;
	int x;

	// implements the drawing of the wallpaper onto the screen
	for (x = existingBackground; x < SCREEN_WIDTH; x += SCREEN_WIDTH){
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
	drawText(SCREEN_WIDTH / 2, 450, 255, 255, 255, TEXT_CENTER, "PRESS SPACE TO PLAY!");
	drawText(SCREEN_WIDTH / 2, 500, 255, 255, 255, TEXT_CENTER, "PRESS C FOR CONTROLS");
	drawText(SCREEN_WIDTH / 2, 550, 255, 255, 255, TEXT_CENTER, "PRESS H FOR HELP");
	
}

// initiates the loading of the graphics and plays the background audio,
void initTitle(void)
{
	app.delegate.logic = logic;
	app.delegate.draw = draw;
	// this allows the background wallpaper to be uploaded and displayed for the user. 
	background = loadTexture("gfx/backgroundNew.png");
	logo = loadTexture("gfx/logo.png");
	// the music score utilised in the introduction package is an adaptation of Stu Phillips' Knight Rider Theme, covered by 
	// Jason Jay Dookarun and recorded. 
	loadMusic("music/kr.mp3");
	playMusic(1);
}

/* MessageBoxH implements a welcome messsagebox, explaining to the user how the game functions in an appropriate manner
*/
void messageboxH(void) {

	// referenced from https://wiki.libsdl.org/SDL_ShowMessageBox#Version

	const SDL_MessageBoxButtonData buttons[] = {
	{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 0, "OK" },
	};

	const SDL_MessageBoxData messageboxdata = {
		SDL_MESSAGEBOX_INFORMATION,NULL,"Welcome!","Hi and welcome To Pete's Pizza Hunt! We have lost 11 slices of pizza and your mission is to find them! To check your progress, look at the HUD on top right-hand side. Good luck!",SDL_arraysize(buttons),buttons };
	int buttonid;
	if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
		SDL_Log("error displaying message box");
		return 1;
	}
	if (buttonid == 0) {
		return;
	}

}

/* messageBox C implements a control method message box to notify the user how to play the game 
*/
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
