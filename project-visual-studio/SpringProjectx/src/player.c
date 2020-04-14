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
#include <windows.h>


static SDL_Texture* pete[2];
static void messageboxYesNo(void);


void initPlayer(void)
{
	player = malloc(sizeof(Entity));
	memset(player, 0, sizeof(Entity));
	stage.entityTail->next = player;
	stage.entityTail = player;

	player->health = 1;

	pete[0] = loadTexture("gfx/pete01.png");
	pete[1] = loadTexture("gfx/pete02.png");

	player->texture = pete[0];

	SDL_QueryTexture(player->texture, NULL, NULL, &player->w, &player->h);
}

/* the section below implements the new commands for controlling the entity with appropriate control gestures such as WASD or UpDownLeftRight and SPACE
*/
void doPlayer(void)
{
	player->dx = 0;

	if (app.keyboard[SDL_SCANCODE_A])
	{
		player->dx = -PLAYER_MOVE_SPEED;

		player->texture = pete[1];
	}

	if (app.keyboard[SDL_SCANCODE_D])
	{
		player->dx = PLAYER_MOVE_SPEED;

		player->texture = pete[0];
	}

	if (app.keyboard[SDL_SCANCODE_W] && player->isOnGround)
	{
		player->riding = NULL;

		player->dy = -20;

		playSound(SND_JUMP, CH_PLAYER);
	}

	if (app.keyboard[SDL_SCANCODE_R])
	{
		player->x = player->y = 0;

		app.keyboard[SDL_SCANCODE_R] = 0;
	}

	// new code

	if (app.keyboard[SDL_SCANCODE_LEFT])
	{
		player->dx = -PLAYER_MOVE_SPEED;

		player->texture = pete[1];
	}

	if (app.keyboard[SDL_SCANCODE_RIGHT])
	{
		player->dx = PLAYER_MOVE_SPEED;

		player->texture = pete[0];
	}

	if (app.keyboard[SDL_SCANCODE_SPACE] && player->isOnGround)
	{
		player->riding = NULL;

		player->dy = -20;

		playSound(SND_JUMP, CH_PLAYER);
	}

	if (app.keyboard[SDL_SCANCODE_R])
	{
		player->x = player->y = 0;

		app.keyboard[SDL_SCANCODE_R] = 0;
	}

	if (app.keyboard[SDL_SCANCODE_Q]) {
		messageboxYesNo();
		}
	}

void messageboxYesNo(void) {
	// referenced from https://wiki.libsdl.org/SDL_ShowMessageBox#Version

	const SDL_MessageBoxButtonData buttons[] = {
	{ SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 1, "Yes" },

	{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 2, "No" },
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


