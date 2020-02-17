/*   __  __       __      __       _    _
**  |  \/  |_  _  \ \    / /__ _ _| |__| |
**  | |\/| | || |  \ \/\/ / _ \ '_| / _` |
**  |_|  |_|\_, |   \_/\_/\___/_| |_\__,_|
**          |__/
**
** A CSFML world terraforming tool.
** Made by Robin Mercier © Lord Estropié, 2020
*/

#include "application.h"

float **terrain_3d;
sfVector2f **terrain_2d;

int rotation = 0;
int view_angle = 45;
float scale = 1.0f;

float section_x = 0;
float section_y = 0;
float section_scale = 1;

float x_offset = 0;
float y_offset = 0;
float z_offset = 0;

int main(UNUSED int ac, UNUSED char *av[], UNUSED char *env[])
{
    malloc_terrain();
    load_terrain();

    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode = (sfVideoMode) {1280, 720, 64};
    sfWindowStyle style = {sfTitlebar | sfClose | sfResize};
    window = sfRenderWindow_create(mode, "Application (c) Robin Mercier, 2020", style, 0);

    sfRenderWindow_setFramerateLimit(window, 32);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            manage_events(window, event);
        manage_keys();
        project_terrain();
        sfRenderWindow_clear(window, sfBlack);
        render_terrain(window);
        sfRenderWindow_display(window);
    }
    return (0);
}
