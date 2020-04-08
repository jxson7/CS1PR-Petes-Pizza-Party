#include "common.h"

static void logic(void);
static void draw(void);
static void drawLogo(void);


static SDL_Texture* sdl2Texture;
static SDL_Texture* shooterTexture;
static int reveal = 0;
static int timeout;
static int backgroundX;
static SDL_Texture* background;


void doBackground(void)
{
	if (--backgroundX < -SCREEN_WIDTH)
	{
		backgroundX = 0;
	}
}

void drawBackground(void)
{
	SDL_Rect dest;
	int x;

	for (x = backgroundX; x < SCREEN_WIDTH; x += SCREEN_WIDTH)
	{
		dest.x = x;
		dest.y = 0;
		dest.w = SCREEN_WIDTH;
		dest.h = SCREEN_HEIGHT;

		SDL_RenderCopy(app.renderer, background, NULL, &dest);
	}
}

void initTitle(void)
{
	app.delegate.logic = logic;
	app.delegate.draw = draw;

	memset(app.keyboard, 0, sizeof(int) * MAX_KEYBOARD_KEYS);

	background = loadTexture("gfx/backgroundNew.png");
	backgroundX = 0;
	sdl2Texture = loadTexture("gfx/sdl2.png");
	shooterTexture = loadTexture("gfx/pixelpete.png");

}

static void logic(void)
{
	doBackground();

	drawMap();


	if (reveal < SCREEN_HEIGHT)
	{
		reveal++;
	}

	if (app.keyboard[SDL_SCANCODE_SPACE])
	{
		initStage();
	}
}

static void draw(void)
{
	drawBackground();

	drawMap();

	drawLogo();

	if (timeout % 40 < 20)
	{
		drawText(SCREEN_WIDTH / 2, 600, 255, 255, 255, TEXT_CENTER, "PRESS SPACE TO PLAY!");
	}
}

static void drawLogo(void)
{
	SDL_Rect r;

	r.x = 0;
	r.y = 0;

	SDL_QueryTexture(sdl2Texture, NULL, NULL, &r.w, &r.h);

	r.h = MIN(reveal, r.h);

	blitRect(sdl2Texture, &r, (SCREEN_WIDTH / 2) - (r.w / 2), 100);

	SDL_QueryTexture(shooterTexture, NULL, NULL, &r.w, &r.h);

	r.h = MIN(reveal, r.h);

	blitRect(shooterTexture, &r, (SCREEN_WIDTH / 2) - (r.w / 2), 250);
}