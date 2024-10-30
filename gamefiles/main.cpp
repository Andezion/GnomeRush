#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

int main()
{
    al_init();
    al_install_keyboard();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_init_image_addon();

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();

    ALLEGRO_BITMAP* image = al_load_bitmap("C:\\Users\\vdoro\\OneDrive\\Рабочий стол\\photos\\tanchik.png");

    ALLEGRO_DISPLAY* disp = al_create_display(800, 600);
    ALLEGRO_FONT* font = al_create_builtin_font();

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);

    float pos_tank_x = 100;
    float pos_tank_y = 100;

    auto origin_width = (float) al_get_bitmap_width(image);
    auto origin_height = (float) al_get_bitmap_height(image);

    while(true)
    {
        al_wait_for_event(queue, &event);
        if(event.type == ALLEGRO_EVENT_TIMER)
        {
            redraw = true;
        }
        else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || event.keyboard.keycode == ALLEGRO_KEY_Q)
        {
            break;
        }

        if(event.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if(event.keyboard.keycode == ALLEGRO_KEY_W)
            {
                pos_tank_y = pos_tank_y - 5;
            }
            else if(event.keyboard.keycode == ALLEGRO_KEY_S)
            {
                pos_tank_y = pos_tank_y + 5;
            }
            else if(event.keyboard.keycode == ALLEGRO_KEY_A)
            {
                pos_tank_x = pos_tank_x - 5;
            }
            else if(event.keyboard.keycode == ALLEGRO_KEY_D)
            {
                al_draw_rotated_bitmap(image, origin_width, origin_height, pos_tank_x, pos_tank_y, 15, 0);
                pos_tank_x = pos_tank_x + 5;
            }
        }


        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));

            al_draw_scaled_bitmap(image, 0, 0, origin_width, origin_height, pos_tank_x, pos_tank_y, origin_width / 8, origin_height / 8, 0);

            al_draw_text(font, al_map_rgb(255, 255, 255), 300, 300, 0, "Hello world!");

            al_flip_display();

            redraw = false;
        }
    }

    al_destroy_bitmap(image);
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}