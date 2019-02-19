/*
** EPITECH PROJECT, 2018
** bootstrap
** File description:
** terrain.h
*/

#ifndef TERRAIN_H
	#define TERRAIN_H

    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <math.h>

    #define MAP_SIZE    128
    #define PI          3.1415926535
    
    float **terrain_3d;
    sfVector2f **terrain_2d;
    int rotation;
    int view_angle;
    float scale;
    float section_x;
    float section_y;
    float section_scale;
    float x_offset;
    float y_offset;
    float z_offset;

    void    malloc_terrains();
    void    load_terrain();
    sfVector2f  project_vertex(float x, float y, float z);
    void    project_terrain();
    void	draw_line(sfRenderWindow *window, sfVector2f point1, sfVector2f point2);
    void    render_terrain(sfRenderWindow *window);
    void    manage_events(sfRenderWindow *window, sfEvent event);
    void    manage_keys();

#endif /* TERRAIN_H */
