/*
** EPITECH PROJECT, 2018
** bootstrap
** File description:
** terrain_rendering.c
*/

#include "terrain.h"

void    manage_keys()
{
	if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
		if (sfKeyboard_isKeyPressed(sfKeyLControl) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRControl) == sfTrue) {
			rotation += 5;
			if (rotation > 359)
				rotation -= 360;
		} else if (sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRShift) == sfTrue) {
			section_x -= 0.05f;
			load_terrain();
		} else if (sfKeyboard_isKeyPressed(sfKeyLAlt) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRAlt) == sfTrue) {
			x_offset -= 1;
		} else {
			rotation += 1;
			if (rotation > 359)
				rotation -= 360;
		}
	}
	if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
		if (sfKeyboard_isKeyPressed(sfKeyLControl) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRControl) == sfTrue) {
			rotation -= 5;
			if (rotation < 0)
				rotation += 360;
		} else if (sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRShift) == sfTrue) {
			section_x -= 0.05f;
			load_terrain();
		} else if (sfKeyboard_isKeyPressed(sfKeyLAlt) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRAlt) == sfTrue) {
			x_offset += 1;
		} else {
			rotation -= 1;
			if (rotation < 0)
				rotation += 360;
		}
	}
	if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
		if (sfKeyboard_isKeyPressed(sfKeyLControl) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRControl) == sfTrue) {
			if (view_angle - 5 >= 0)
				view_angle -= 5;
			else
				view_angle = 0;
		} else if (sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRShift) == sfTrue) {
			section_y += 0.05f;
			load_terrain();
		} else if (sfKeyboard_isKeyPressed(sfKeyLAlt) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRAlt) == sfTrue) {
			z_offset -= 1;
		} else {
			if (view_angle - 1 >= 0)
				view_angle -= 1;
		}
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
		if (sfKeyboard_isKeyPressed(sfKeyLControl) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRControl) == sfTrue) {
			if (view_angle + 5 <= 90)
				view_angle += 5;
			else
				view_angle = 90;
		} else if (sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRShift) == sfTrue) {
			section_y -= 0.05f;
			load_terrain();
		} else if (sfKeyboard_isKeyPressed(sfKeyLAlt) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRAlt) == sfTrue) {
			z_offset += 1;
		} else {
			if (view_angle + 1 <= 90)
				view_angle += 1;
		}
	}
	if (sfKeyboard_isKeyPressed(sfKeyPageUp) == sfTrue) {
		if (sfKeyboard_isKeyPressed(sfKeyLControl) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRControl) == sfTrue) {
			if (scale - 0.2f > 0.01f)
				scale -= 0.2f;
			else
				scale = 0.01f;
		} else if (sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRShift) == sfTrue) {
			section_scale += 0.05f;
			load_terrain();
		} else if (sfKeyboard_isKeyPressed(sfKeyLAlt) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRAlt) == sfTrue) {
			y_offset += 0.1f;
		} else {
			if (scale - 0.01f > 0.01f)
				scale -= 0.01f;
		}
	}
	if (sfKeyboard_isKeyPressed(sfKeyPageDown) == sfTrue) {
		if (sfKeyboard_isKeyPressed(sfKeyLControl) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRControl) == sfTrue) {
			if (scale + 0.2f <= 50)
				scale += 0.2f;
			else
				scale = 50.0f;
		} else if (sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRShift) == sfTrue) {
			section_scale -= 0.05f;
			load_terrain();
		} else if (sfKeyboard_isKeyPressed(sfKeyLAlt) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRAlt) == sfTrue) {
			y_offset -= 0.1f;
		} else {
			if (scale + 0.01f <= 50)
				scale += 0.01f;
		}
	}
	if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) {
		rotation = 0;
		view_angle = 45;
		scale = 1.0f;
		section_x = 0;
		section_y = 0;
		section_scale = 1;
		x_offset = 0;
		y_offset = 0;
		z_offset = 0;
		load_terrain();
	}
	if (sfKeyboard_isKeyPressed(sfKeyR) == sfTrue)
		rotation = 0;
	if (sfKeyboard_isKeyPressed(sfKeyV) == sfTrue)
		view_angle = 45;
	if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue)
		scale = 1.0f;
	if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue) {
		section_x = 0;
		section_y = 0;
		section_scale = 1;
		load_terrain();
	}
	if (sfKeyboard_isKeyPressed(sfKeyC) == sfTrue) {
		x_offset = 0;
		y_offset = 0;
		z_offset = 0;
	}
}

void    manage_events(sfRenderWindow *window, sfEvent event)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(window);
}
