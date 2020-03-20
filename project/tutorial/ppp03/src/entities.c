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

#include "entities.h"

static void move(Entity *e);
static void moveToWorld(Entity *e, float dx, float dy);

void initEntities(void)
{
}

void doEntities(void)
{
	Entity *e;
	
	for (e = stage.entityHead.next ; e != NULL ; e = e->next)
	{
		self = e;
		
		move(e);
	}
}

static void move(Entity *e)
{
	e->dy += 1.5;
	
	e->dy = MAX(MIN(e->dy, 18), -999);
	
	e->isOnGround = 0;
	
	moveToWorld(e, e->dx, 0);
	
	moveToWorld(e, 0, e->dy);
	
	e->x = MIN(MAX(e->x, 0), MAP_WIDTH * TILE_SIZE);
	e->y = MIN(MAX(e->y, 0), MAP_HEIGHT * TILE_SIZE);
}

static void moveToWorld(Entity *e, float dx, float dy)
{
	int mx, my, hit, adj;
	
	if (dx != 0)
	{
		e->x += dx;
		
		mx = dx > 0 ? (e->x + e->w) : e->x;
		mx /= TILE_SIZE;
		
		my = (e->y / TILE_SIZE);
		
		hit = 0;
		
		if (!isInsideMap(mx, my) || stage.map[mx][my] != 0)
		{
			hit = 1;
		}
		
		my = (e->y + e->h - 1) / TILE_SIZE;
		
		if (!isInsideMap(mx, my) || stage.map[mx][my] != 0)
		{
			hit = 1;
		}
		
		if (hit)
		{
			adj = dx > 0 ? -e->w : TILE_SIZE;
			
			e->x = (mx * TILE_SIZE) + adj;
			
			e->dx = 0;
		}
	}
	
	if (dy != 0)
	{
		e->y += dy;
		
		my = dy > 0 ? (e->y + e->h) : e->y;
		my /= TILE_SIZE;
		
		mx = e->x / TILE_SIZE;
		
		hit = 0;
		
		if (!isInsideMap(mx, my) || stage.map[mx][my] != 0)
		{
			hit = 1;
		}
		
		mx = (e->x + e->w - 1) / TILE_SIZE;
		
		if (!isInsideMap(mx, my) || stage.map[mx][my] != 0)
		{
			hit = 1;
		}
		
		if (hit)
		{
			adj = dy > 0 ? -e->h : TILE_SIZE;
			
			e->y = (my * TILE_SIZE) + adj;
			
			e->dy = 0;
			
			e->isOnGround = dy > 0;
		}
	}
}

void drawEntities(void)
{
	Entity *e;
	
	for (e = stage.entityHead.next ; e != NULL ; e = e->next)
	{
		blit(e->texture, e->x - stage.camera.x, e->y - stage.camera.y, 0);
	}
}
