/*
** EPITECH PROJECT, 2018
** bootstrap
** File description:
** terrain_rendering.c
*/

#include "terrain.h"

void	draw_line(sfRenderWindow *window, sfVector2f point1, sfVector2f point2)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = point1, .color = sfWhite};
	sfVertex vertex2 = {.position = point2, .color = sfWhite};

	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);

	sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
	sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
	sfVertexArray_destroy(vertex_array);
}

void    render_terrain(sfRenderWindow *window)
{
	for (int i = 0; i + 1 < MAP_SIZE; i += 1) {
		for (int j = 0; j + 1 < MAP_SIZE; j += 1) {
			draw_line(window, terrain_2d[i][j], terrain_2d[i + 1][j]);
			draw_line(window, terrain_2d[i][j], terrain_2d[i][j + 1]);
			draw_line(window, terrain_2d[i + 1][j], terrain_2d[i + 1][j + 1]);
			draw_line(window, terrain_2d[i][j + 1], terrain_2d[i + 1][j + 1]);
		}
	}
}
