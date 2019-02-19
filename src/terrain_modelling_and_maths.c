/*
** EPITECH PROJECT, 2018
** bootstrap
** File description:
** terrain_modelling_and_maths.c
*/

//#include "attribute.h"
#include "terrain.h"

void    malloc_terrains()
{
	terrain_3d = malloc(sizeof(float *) * MAP_SIZE);
	terrain_2d = malloc(sizeof(sfVector2f *) * MAP_SIZE);

    for (int i = 0; i < MAP_SIZE; i += 1) {
		terrain_3d[i] = malloc(sizeof(float) * MAP_SIZE);
		terrain_2d[i] = malloc(sizeof(sfVector2f) * MAP_SIZE);
	}
}

void    load_terrain()
{
	float x = 0;
	float y = 0;

	for (int i = 0; i < MAP_SIZE; i += 1) {
		for (int j = 0; j < MAP_SIZE; j += 1) {
			x = (((j * 1.0f / (MAP_SIZE - (section_scale + section_x))) * (2 * section_scale)) - (section_scale + section_x));
			y = (((i * 1.0f / (MAP_SIZE - (section_scale + section_y))) * (2 * section_scale)) - (section_scale + section_y));
			terrain_3d[i][j] = cos(x) * cos(y);
			//terrain_3d[i][j] = sin(x) * sin(y) / 4;
			//terrain_3d[i][j] = pow(pow(x, 3) + pow(y, 3), 5);
        }
	}
}

sfVector2f  project_vertex(float x, float y, float z)
{
	sfVector2f pos;
	float a = 0;
	float b = 0;
	float c = 0;
	float tmp = 0;
	float rot = (rotation) * (PI / 180);
	float view = (view_angle + 180) * (PI / 180);

	a = cos(rot) * (x) - (sin(rot) * (z));
	c = sin(rot) * (x) + (cos(rot) * (z));
	tmp = y * cos(view) - c * sin(view);
	c = b * sin(view) + c * cos(view);
	b = tmp;
	pos = (sfVector2f) {a + (1280 / 2), b + (720 / 2)};

	return (pos);
}

void    project_terrain()
{
	float x = 0;
	float y = 0;
	float z = 0;
	
	for (int i = 0; i < MAP_SIZE; i += 1) {
		for (int j = 0; j < MAP_SIZE; j += 1) {
			if (MAP_SIZE % 2 == 0)
				x = (j - (MAP_SIZE / 2 - 0.5) + x_offset) * 50 * scale;
			else
				x = (j - (MAP_SIZE / 2) + x_offset) * 50 * scale;
			y = ((terrain_3d[i][j] + y_offset) * MAP_SIZE * MAP_SIZE * scale / 6);
			if (MAP_SIZE % 2 == 0)
				z = (i - (MAP_SIZE / 2 - 0.5) + z_offset) * 50 * scale;
			else
				z = (i - (MAP_SIZE / 2) + z_offset) * 50 * scale;
			terrain_2d[i][j] = project_vertex(x, y, z);
		}
	}
}
