/*   __  __       __      __       _    _
**  |  \/  |_  _  \ \    / /__ _ _| |__| |
**  | |\/| | || |  \ \/\/ / _ \ '_| / _` |
**  |_|  |_|\_, |   \_/\_/\___/_| |_\__,_|
**          |__/
**
** A CSFML world terraforming tool.
** Made by Robin Mercier © Lord Estropié, 2020
*/

#ifndef APPLICATION_H
	#define APPLICATION_H

    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <math.h>

    #define UNUSED __attribute__((unused))

    #define MAP_SIZE    64
    #define TILE_SIZE   50
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

    void malloc_terrain();
    void load_terrain();
    sfVector2f project_vertex(float x, float y, float z);
    void project_terrain();
    void draw_line(sfRenderWindow *window, sfVector2f point1, sfVector2f point2);
    void render_terrain(sfRenderWindow *window);
    void manage_events(sfRenderWindow *window, sfEvent event);
    void manage_keys();

#endif /* APPLICATION_H */
