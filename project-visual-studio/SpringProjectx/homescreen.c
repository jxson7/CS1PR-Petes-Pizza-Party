/* Author: Jason Jay Dookarun
With the inspiration of parrallel realities concept of a homescreen, the following file consists of a homepage creation that will be 
displayed to the user upon running the program. 
*/

#include "common.h"

static void logic(void);
static void draw(void);
static void messagebox(void);
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
		initStage();
	}
	if (app.keyboard[SDL_SCANCODE_H]) {
		messagebox();
	}
	if (app.keyboard[SDL_SCANCODE_Q]) {
		exit(3);
		return 3;
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
	drawText(SCREEN_WIDTH / 2, 520, 255, 255, 255, TEXT_CENTER, "PRESS H FOR CONTROLS AND HELP");
}

void initTitle(void)
{
	app.delegate.logic = logic;
	app.delegate.draw = draw;
	background = loadTexture("gfx/backgroundNew.png");
	logo = loadTexture("gfx/logo.png");
}

void messagebox(void) {
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Welcome!" ,"Hi and welcome To Pete's Pizza Hunt. The aim of the game is to collect all pizzas scattered across the map. Controls: Left: LEFT Key or A, Right : RIGHT Key, Jump: SPACE or W, Reset: R, Quit: Q.", NULL);
}