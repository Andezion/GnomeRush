#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "handler_of_screen.h"

const int screen_width = 1000;
const int screen_height = 600;

int begin_place_x = 500;
int begin_place_y = 400;

typedef enum
{
    MENU,
    WIKI,
    PICK,
    GAME,
    TEST,
    OVER
} GameState;

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("Knight", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_RESIZABLE);
    if (window == NULL)
    {
        printf("Error in creating window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        printf("Error in creating renderer: %s\n", SDL_GetError());

        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    }

    if (TTF_Init() == -1)
    {
        printf("Error initializing TTF: %s\n", TTF_GetError());

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    }

    TTF_Font* font = TTF_OpenFont("font.ttf", 40);
    if (font == NULL)
    {
        printf("Error loading font: %s\n", TTF_GetError());

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();

        return 1;
    }

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    Mix_Music *start_screen = Mix_LoadMUS("start_menu.mp3");
    Mix_Music *game_screen = Mix_LoadMUS("game_music.mp3");
    Mix_Music *pick_screen = Mix_LoadMUS("pick_music.mp3");

    Mix_Music *hit2_knight = Mix_LoadMUS("sword2.mp3");
    Mix_Music *magic_hit = Mix_LoadMUS("magic.mp3");

    SDL_Surface *zelie1 = SDL_LoadBMP("zel_dur.bmp");
    SDL_Texture *zel1 = SDL_CreateTextureFromSurface(renderer, zelie1);

    SDL_Surface *zelie2 = SDL_LoadBMP("zel_heal.bmp");
    SDL_Texture *zel2 = SDL_CreateTextureFromSurface(renderer, zelie2);

    SDL_Surface *zelie3 = SDL_LoadBMP("zel_mana.bmp");
    SDL_Texture *zel3 = SDL_CreateTextureFromSurface(renderer, zelie3);

    SDL_Surface *zelie4 = SDL_LoadBMP("zel_rage.bmp");
    SDL_Texture *zel4 = SDL_CreateTextureFromSurface(renderer, zelie4);

    SDL_Surface *zelie5 = SDL_LoadBMP("zel_what.bmp");
    SDL_Texture *zel5 = SDL_CreateTextureFromSurface(renderer, zelie5);

    SDL_Texture *hitting_type1[7];
    const char *hitting_type_1[7] = {"hit2.bmp","hit3.bmp","hit4.bmp","hit5.bmp","hit6.bmp","hit7.bmp","hit8.bmp"};

    SDL_Texture *hitting_type2[7];
    const char *hitting_type_2[7] = {"hit2_1.bmp","hit3_1.bmp","hit4_1.bmp","hit5_1.bmp","hit6_1.bmp","hit7_1.bmp","hit8_1.bmp"};

    SDL_Texture *standing_knight_type1[7];
    const char *standing_knight_type_1[7] = {"asset_knight1_stand1.bmp","asset_knight1_stand2.bmp","asset_knight1_stand3.bmp","asset_knight1_stand4.bmp","asset_knight1_stand3.bmp","asset_knight1_stand2.bmp","asset_knight1_stand1.bmp"};

    SDL_Texture *standing_knight_type2[7];
    const char *standing_knight_type_2[7] = {"asset_knight1_stand_1.bmp","asset_knight1_stand_2.bmp","asset_knight1_stand_3.bmp","asset_knight1_stand_4.bmp","asset_knight1_stand_3.bmp","asset_knight1_stand_2.bmp","asset_knight1_stand_1.bmp"};

    SDL_Texture *knight_def1[7];
    const char *knight_def_1[7] = {"asset_knight1_def1.bmp","asset_knight1_def2.bmp","asset_knight1_def3.bmp","asset_knight1_def4.bmp","asset_knight1_def3.bmp","asset_knight1_def2.bmp","asset_knight1_def1.bmp"};

    SDL_Texture *knight_def2[7];
    const char *knight_def_2[7] = {"asset_knight1_def_1.bmp","asset_knight1_def_2.bmp","asset_knight1_def_3.bmp","asset_knight1_def_4.bmp","asset_knight1_def_3.bmp","asset_knight1_def_2.bmp","asset_knight1_def_1.bmp"};

    SDL_Texture *knight_run1[8];
    const char *knight_run_1[8] = {"run1.bmp","run2.bmp","run3.bmp","run4.bmp","run5.bmp","run6.bmp","run7.bmp","run8.bmp"};

    SDL_Texture *knight_run2[8];
    const char *knight_run_2[8] = {"run1_1.bmp","run2_1.bmp","run3_1.bmp","run4_1.bmp","run5_1.bmp","run6_1.bmp","run7_1.bmp","run8_1.bmp"};

    SDL_Texture *wizard1[6];
    const char *wizard_1[6] = {"mag1.bmp","mag2.bmp","mag3.bmp","mag4.bmp","mag5.bmp","mag6.bmp"};
    SDL_Texture *wizard2[6];
    const char *wizard_2[6] = {"mag1_1.bmp","mag2_1.bmp","mag3_1.bmp","mag4_1.bmp","mag5_1.bmp","mag6_1.bmp"};

    SDL_Texture *hit_wiz1[6];
    const char *hit_wiz_1[6] = {"2hit2.bmp","2hit3.bmp","2hit4.bmp","2hit5.bmp","2hit4.bmp","2hit3.bmp"};

    SDL_Texture *hit_wiz2[6];
    const char *hit_wiz_2[6] = {"2hit2_1.bmp","2hit3_1.bmp","2hit4_1.bmp","2hit5_1.bmp","2hit4_1.bmp","2hit3_1.bmp"};

    SDL_Texture *walk_wiz1[7];
    const char *walk_wiz_1[7] = {"walk1.bmp","walk2.bmp","walk3.bmp","walk4.bmp","walk5.bmp","walk6.bmp","walk7.bmp"};

    SDL_Texture *walk_wiz2[7];
    const char *walk_wiz_2[7] = {"2walk1.bmp","2walk2.bmp","2walk3.bmp","2walk4.bmp","2walk5.bmp","2walk6.bmp","2walk7.bmp"};

    if(loadTextureArray(renderer, hitting_type_1, 7, hitting_type1) != 0)
    {
        printf("Error in loading textures!");

        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    }
    if(loadTextureArray(renderer, hitting_type_2, 7, hitting_type2) != 0)
    {
        printf("Error in loading textures!");

        SDL_DestroyWindow(window);
        SDL_Quit();

        for(int i = 0; i < 7; i++)
        {
            SDL_DestroyTexture(hitting_type1[i]);
        }

        return 1;
    }
    if(loadTextureArray(renderer, standing_knight_type_1, 7, standing_knight_type1) != 0)
    {
        printf("Error in loading textures!");

        SDL_DestroyWindow(window);
        SDL_Quit();

        for(int i = 0; i < 7; i++)
        {
            SDL_DestroyTexture(hitting_type1[i]);
            SDL_DestroyTexture(hitting_type2[i]);
        }

        return 1;
    }
    if(loadTextureArray(renderer, standing_knight_type_2, 7, standing_knight_type2) != 0)
    {
        printf("Error in loading textures!");

        for(int i = 0; i < 7; i++)
        {
            SDL_DestroyTexture(hitting_type1[i]);
            SDL_DestroyTexture(hitting_type2[i]);

            SDL_DestroyTexture(standing_knight_type1[i]);
        }

        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    }
    if(loadTextureArray(renderer, knight_def_1, 7, knight_def1) != 0)
    {
        printf("Error in loading textures!");

        for(int i = 0; i < 7; i++)
        {
            SDL_DestroyTexture(hitting_type1[i]);
            SDL_DestroyTexture(hitting_type2[i]);

            SDL_DestroyTexture(standing_knight_type1[i]);
            SDL_DestroyTexture(standing_knight_type2[i]);
        }

        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    }
    if(loadTextureArray(renderer, knight_def_2, 7, knight_def2) != 0)
    {
        printf("Error in loading textures!");

        for(int i = 0; i < 7; i++)
        {
            SDL_DestroyTexture(hitting_type1[i]);
            SDL_DestroyTexture(hitting_type2[i]);

            SDL_DestroyTexture(standing_knight_type1[i]);
            SDL_DestroyTexture(standing_knight_type2[i]);
            SDL_DestroyTexture(knight_def1[i]);
        }

        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    }
    if(loadTextureArray(renderer, knight_run_1, 8, knight_run1) != 0)
    {
        printf("Error in loading textures!");

        for(int i = 0; i < 7; i++)
        {
            SDL_DestroyTexture(hitting_type1[i]);
            SDL_DestroyTexture(hitting_type2[i]);

            SDL_DestroyTexture(standing_knight_type1[i]);
            SDL_DestroyTexture(standing_knight_type2[i]);
            SDL_DestroyTexture(knight_def1[i]);
            SDL_DestroyTexture(knight_def2[i]);
        }

        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    }
    if(loadTextureArray(renderer, knight_run_2, 8, knight_run2) != 0)
    {
        printf("Error in loading textures!");

        for(int i = 0; i < 7; i++)
        {
            SDL_DestroyTexture(hitting_type1[i]);
            SDL_DestroyTexture(hitting_type2[i]);

            SDL_DestroyTexture(standing_knight_type1[i]);
            SDL_DestroyTexture(standing_knight_type2[i]);
            SDL_DestroyTexture(knight_def1[i]);
            SDL_DestroyTexture(knight_def2[i]);
        }
        for(int i = 0; i < 8; i++)
        {
            SDL_DestroyTexture(knight_run1[i]);
        }

        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    }
    if(loadTextureArray(renderer, wizard_1, 6, wizard1) != 0)
    {
        printf("Error in loading textures!");

        for(int i = 0; i < 7; i++)
        {
            SDL_DestroyTexture(hitting_type1[i]);
            SDL_DestroyTexture(hitting_type2[i]);

            SDL_DestroyTexture(standing_knight_type1[i]);
            SDL_DestroyTexture(standing_knight_type2[i]);
            SDL_DestroyTexture(knight_def1[i]);
            SDL_DestroyTexture(knight_def2[i]);
        }
        for(int i = 0; i < 8; i++)
        {
            SDL_DestroyTexture(knight_run1[i]);
            SDL_DestroyTexture(knight_run2[i]);
        }

        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    }
    if(loadTextureArray(renderer, wizard_2, 6, wizard2) != 0)
    {
        printf("Error in loading textures!");

        for(int i = 0; i < 6; i++)
        {
            SDL_DestroyTexture(wizard1[i]);
        }
        for(int i = 0; i < 7; i++)
        {
            SDL_DestroyTexture(hitting_type1[i]);
            SDL_DestroyTexture(hitting_type2[i]);

            SDL_DestroyTexture(standing_knight_type1[i]);
            SDL_DestroyTexture(standing_knight_type2[i]);
            SDL_DestroyTexture(knight_def1[i]);
            SDL_DestroyTexture(knight_def2[i]);
        }
        for(int i = 0; i < 8; i++)
        {
            SDL_DestroyTexture(knight_run1[i]);
            SDL_DestroyTexture(knight_run2[i]);
        }

        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    }
    if(loadTextureArray(renderer, hit_wiz_1, 6, hit_wiz1) != 0)
    {
        printf("Error in loading textures!");

        for(int i = 0; i < 6; i++)
        {
            SDL_DestroyTexture(wizard1[i]);
            SDL_DestroyTexture(wizard2[i]);
        }
        for(int i = 0; i < 7; i++)
        {
            SDL_DestroyTexture(hitting_type1[i]);
            SDL_DestroyTexture(hitting_type2[i]);

            SDL_DestroyTexture(standing_knight_type1[i]);
            SDL_DestroyTexture(standing_knight_type2[i]);
            SDL_DestroyTexture(knight_def1[i]);
            SDL_DestroyTexture(knight_def2[i]);
        }
        for(int i = 0; i < 8; i++)
        {
            SDL_DestroyTexture(knight_run1[i]);
            SDL_DestroyTexture(knight_run2[i]);
        }

        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    }
    if(loadTextureArray(renderer, hit_wiz_2, 6, hit_wiz2) != 0)
    {
        printf("Error in loading textures!");

        for(int i = 0; i < 6; i++)
        {
            SDL_DestroyTexture(wizard1[i]);
            SDL_DestroyTexture(wizard2[i]);
            SDL_DestroyTexture(hit_wiz1[i]);
        }
        for(int i = 0; i < 7; i++)
        {
            SDL_DestroyTexture(hitting_type1[i]);
            SDL_DestroyTexture(hitting_type2[i]);

            SDL_DestroyTexture(standing_knight_type1[i]);
            SDL_DestroyTexture(standing_knight_type2[i]);
            SDL_DestroyTexture(knight_def1[i]);
            SDL_DestroyTexture(knight_def2[i]);
        }
        for(int i = 0; i < 8; i++)
        {
            SDL_DestroyTexture(knight_run1[i]);
            SDL_DestroyTexture(knight_run2[i]);
        }

        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    }
    if(loadTextureArray(renderer, walk_wiz_1, 7, walk_wiz1) != 0)
    {
        printf("Error in loading textures!");

        for(int i = 0; i < 6; i++)
        {
            SDL_DestroyTexture(wizard1[i]);
            SDL_DestroyTexture(wizard2[i]);
            SDL_DestroyTexture(hit_wiz1[i]);
            SDL_DestroyTexture(hit_wiz2[i]);
        }
        for(int i = 0; i < 7; i++)
        {
            SDL_DestroyTexture(hitting_type1[i]);
            SDL_DestroyTexture(hitting_type2[i]);

            SDL_DestroyTexture(standing_knight_type1[i]);
            SDL_DestroyTexture(standing_knight_type2[i]);
            SDL_DestroyTexture(knight_def1[i]);
            SDL_DestroyTexture(knight_def2[i]);
        }
        for(int i = 0; i < 8; i++)
        {
            SDL_DestroyTexture(knight_run1[i]);
            SDL_DestroyTexture(knight_run2[i]);
        }

        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    }
    if(loadTextureArray(renderer, walk_wiz_2, 7, walk_wiz2) != 0)
    {
        printf("Error in loading textures!");

        for(int i = 0; i < 6; i++)
        {
            SDL_DestroyTexture(wizard1[i]);
            SDL_DestroyTexture(wizard2[i]);
            SDL_DestroyTexture(hit_wiz1[i]);
            SDL_DestroyTexture(hit_wiz2[i]);
        }
        for(int i = 0; i < 7; i++)
        {
            SDL_DestroyTexture(walk_wiz1[i]);

            SDL_DestroyTexture(hitting_type1[i]);
            SDL_DestroyTexture(hitting_type2[i]);

            SDL_DestroyTexture(standing_knight_type1[i]);
            SDL_DestroyTexture(standing_knight_type2[i]);
            SDL_DestroyTexture(knight_def1[i]);
            SDL_DestroyTexture(knight_def2[i]);
        }
        for(int i = 0; i < 8; i++)
        {
            SDL_DestroyTexture(knight_run1[i]);
            SDL_DestroyTexture(knight_run2[i]);
        }

        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    }

    int body_fps = 0;

    int fps_for_mage = 0;
    int run_wizard = 0;

    int custom_fps = 0;
    int custom_def = 0;
    int custom_run = 0;
    int custom_hit = 0;

    int what_part = 0;

    int is_walking_knight = 0;
    int is_defence_knight = 0;
    int is_hitting_knight = 0;

    int helper_for_hitting_knight = 0;
    int helper_for_hitting_wizard = 0;

    int is_hitting_wizard = 0;
    int is_walking_wizard = 0;

    int is_play = 1;
    SDL_Event event;

    int pick = 0;

    int max_height = 40 + rand() % 10;

    begin_place_y = max_height * 10 - 80;

    int table[100][60] = { 0 };

    for(int i = 0; i < 100; i += 4)
    {
        int temp = -2 + rand() % 4;
        int effective_height = max_height + temp;
        for(int j = 0; j < 60; j += 4)
        {
            int value = 1 + rand() % 4;

            for (int bi = 0; bi < 4 && i + bi < 100; bi++)
            {
                for (int bj = 0; bj < 4 && j + bj < 60; bj++)
                {
                    if (j + bj < effective_height)
                    {
                        table[i + bi][j + bj] = 0;
                    }
                    else
                    {
                        table[i + bi][j + bj] = value;
                    }
                }
            }
        }
    }

    int table1[50][30];
    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 30; j++)
        {
            int temp = rand() % 4;
            table1[i][j] = temp;
        }
    }

    SDL_Texture *body[4];
    const char *name_body[4] = {"hitter1.bmp","hitter2.bmp","hitter3.bmp","hitter4.bmp"};
    if(loadTextureArray(renderer, name_body, 4, body) != 0)
    {
        SDL_Quit();
        return 1;
    }

    SDL_Texture *hit[1];
    const char *name_hit[1] = {"hitter1.bmp"};
    if(loadTextureArray(renderer, name_hit, 1, hit) != 0)
    {
        SDL_Quit();
        return 1;
    }

    SDL_Surface *hitter = SDL_LoadBMP("mage_hit.bmp");
    SDL_Texture *hitter_mage = SDL_CreateTextureFromSurface(renderer, hitter);

    SDL_Surface *text = SDL_LoadBMP("letter.bmp");
    SDL_Texture *main_text = SDL_CreateTextureFromSurface(renderer, text);

    GameState state = MENU;
    Mix_PlayMusic(start_screen, -1);

    SDL_Color textColor = {255, 255, 255, 255};

    int point1 = 100;
    int point2 = 100;
    int point3 = 100;

    int library_begin = 100;
    int krok_of_library = 0;

    SDL_Rect zel_for1 = {800, 10, 25, 25};
    SDL_Rect zel_for2 = {830, 10, 25, 25};
    SDL_Rect zel_for3 = {860, 10, 25, 25};
    SDL_Rect zel_for4 = {890, 10, 25, 25};
    SDL_Rect zel_for5 = {920, 10, 25, 25};

    while(is_play)
    {
        SDL_Rect health = {20, 30, point1, 10};
        SDL_Rect mana = {20, 45, point2, 10};
        SDL_Rect stamina = {20, 45, point3, 10};

        SDL_Rect rectangle = {begin_place_x, begin_place_y, 100, 100};
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_q) // окончить игру
            {
                is_play = 0;
            }
            else if(event.key.keysym.sym == SDLK_g) // начать игру
            {
                Mix_PlayMusic(pick_screen, -1);
                state = PICK;
            }
            else if(event.key.keysym.sym == SDLK_h) // тут экран когда проиграли, добавить счёт и персонажа за которого играли
            {
                state = OVER;
            }
            else if(event.key.keysym.sym == SDLK_j) // написать википедию персонажей
            {
                Mix_PlayMusic(start_screen, -1);
                state = WIKI;
            }
            else if(event.key.keysym.sym == SDLK_l) // пауза
            {
                Mix_PlayMusic(start_screen, -1);
                state = MENU;
            }
            else if(state == PICK && event.key.keysym.sym == SDLK_n)
            {
                Mix_PlayMusic(game_screen, -1);
                state = TEST;
            }
            else if(state == PICK && event.key.keysym.sym == SDLK_m)
            {
                Mix_PlayMusic(game_screen, -1);
                state = GAME;
            }
            else if(event.key.keysym.sym == SDLK_RIGHT)
            {
                is_walking_knight = 1;

                what_part = 0;
            }

            if(pick == 0)
            {
                if(event.button.button == SDL_BUTTON_LEFT || event.key.keysym.sym == SDLK_b)
                {
                    if(point2 > 10)
                    {
                        helper_for_hitting_wizard = 1;
                        is_hitting_wizard = 1;
                        is_walking_wizard = 0;

                        point2 = point2 - 10;

                        if(what_part == 0)
                        {
                            SDL_Rect rectangle1 = {begin_place_x, begin_place_y - 40, 160, 140};
                            SDL_RenderCopy(renderer, hit_wiz1[fps_for_mage % 6], NULL, &rectangle1);

                            fps_for_mage = (fps_for_mage + 1) % 6;
                        }
                        else
                        {
                            SDL_Rect rectangle1 = {begin_place_x - 60, begin_place_y - 40, 160, 140};
                            SDL_RenderCopy(renderer, hit_wiz2[custom_hit % 6], NULL, &rectangle1);

                            fps_for_mage = (fps_for_mage + 1) % 6;
                        }
                    }
                }
                else if(event.key.keysym.sym == SDLK_d)
                {
                    helper_for_hitting_wizard = 0;
                    is_walking_wizard = 1;
                    is_hitting_wizard = 0;
                    what_part = 0;

                    SDL_Rect rectangle1 = {begin_place_x, begin_place_y, 140, 100};
                    SDL_RenderCopy(renderer, walk_wiz1[run_wizard % 7], NULL, &rectangle1);

                    run_wizard = (run_wizard + 1) % 7;
                    begin_place_x = begin_place_x + 10;
                }
                else if(event.key.keysym.sym == SDLK_a)
                {
                    helper_for_hitting_wizard = 0;
                    is_walking_wizard = 1;
                    is_hitting_wizard = 0;
                    what_part = 1;

                    SDL_Rect rectangle1 = {begin_place_x - 40, begin_place_y, 140, 100};
                    SDL_RenderCopy(renderer, walk_wiz2[run_wizard % 7], NULL, &rectangle1);

                    run_wizard = (run_wizard + 1) % 7;
                    begin_place_x = begin_place_x - 10;
                }
            }
            else
            {
                if(event.key.keysym.sym == SDLK_d)
                {
                    helper_for_hitting_knight = 0;
                    is_walking_knight = 1;
                    is_defence_knight = 0;
                    is_hitting_knight = 0;
                    what_part = 0;

                    SDL_RenderCopy(renderer, knight_run1[custom_run % 8], NULL, &rectangle);

                    custom_run = (custom_run + 1) % 8;
                    begin_place_x = begin_place_x + 10;
                }
                else if(event.key.keysym.sym == SDLK_a)
                {
                    helper_for_hitting_knight = 0;
                    is_walking_knight = 1;
                    is_defence_knight = 0;
                    is_hitting_knight = 0;
                    what_part = 1;

                    SDL_RenderCopy(renderer, knight_run2[custom_run % 8], NULL, &rectangle);

                    custom_run = (custom_run + 1) % 8;
                    begin_place_x = begin_place_x - 10;
                }
                else if(event.button.button == SDL_BUTTON_LEFT || event.key.keysym.sym == SDLK_b)
                {
                    if(point3 > 10)
                    {
                        helper_for_hitting_knight = 1;
                        is_walking_knight = 0;
                        is_defence_knight = 0;
                        is_hitting_knight = 1;

                        point3 = point3 - 10;

                        if(what_part == 0)
                        {
                            SDL_Rect rectangle1 = {begin_place_x, begin_place_y - 40, 160, 140};
                            SDL_RenderCopy(renderer, hitting_type1[custom_hit % 7], NULL, &rectangle1);

                            custom_hit = (custom_hit + 1) % 7;
                        }
                        else
                        {
                            SDL_Rect rectangle1 = {begin_place_x - 60, begin_place_y - 40, 160, 140};
                            SDL_RenderCopy(renderer, hitting_type2[custom_hit % 7], NULL, &rectangle1);

                            custom_hit = (custom_hit + 1) % 7;
                        }
                    }
                }
                else if(event.key.keysym.sym == SDLK_r)
                {
                    helper_for_hitting_knight = 0;
                    is_defence_knight = 1;
                    is_walking_knight = 0;
                    is_hitting_knight = 0;

                    point3 = point3 - 10;

                    if(what_part == 0)
                    {
                        SDL_RenderCopy(renderer, knight_def1[custom_def % 7], NULL, &rectangle);

                        custom_def = (custom_def + 1) % 7;
                    }
                    else
                    {
                        SDL_RenderCopy(renderer, knight_def2[custom_def % 7], NULL, &rectangle);

                        custom_def = (custom_def + 1) % 7;
                    }
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        int where = -1;
        switch (state)
        {
            case MENU:
                draw_menu(renderer, font, table1);
                break;
            case PICK:
                if(event.key.keysym.sym == SDLK_LEFT)
                {
                    pick = 0;
                }
                else if(event.key.keysym.sym == SDLK_RIGHT)
                {
                    pick = 1;
                }
                draw_pick(renderer, font, table1, pick);
                break;
            case WIKI:
                draw_wiki(renderer, font, table1, where);
                draw_text(renderer, "There you can read about game!", font, textColor, 210, 60);

                if(event.key.keysym.sym == SDLK_DOWN)
                {
                    if(library_begin + krok_of_library < 100)
                    {
                        krok_of_library = krok_of_library + 10;
                    }
                }
                if(event.key.keysym.sym == SDLK_UP)
                {
                    if(library_begin + krok_of_library + 1000 > 550)
                    {
                        krok_of_library = krok_of_library - 10;
                    }
                }

                SDL_Rect frame_for_main_text = {75, library_begin + krok_of_library, 850, 1000};
                SDL_RenderCopy(renderer, main_text, NULL, &frame_for_main_text);

                break;
            case TEST:
                set_background(renderer, table);

                if(pick == 0)
                {
                    draw_text(renderer, "Wizard!", font, textColor, 450, 60);
                }
                else
                {
                    draw_text(renderer, "Knight!", font, textColor, 450, 60);
                }

                if(pick == 1)
                {
                    if(is_walking_knight)
                    {
                        if(what_part == 0)
                        {
                            SDL_RenderCopy(renderer, knight_run1[custom_run % 8], NULL, &rectangle);
                        }
                        else
                        {
                            SDL_RenderCopy(renderer, knight_run2[custom_run % 8], NULL, &rectangle);
                        }
                        is_walking_knight = 0;
                    }
                    else if(is_defence_knight)
                    {
                        if(what_part == 0)
                        {
                            SDL_RenderCopy(renderer, knight_def1[custom_def % 7], NULL, &rectangle);
                        }
                        else
                        {
                            SDL_RenderCopy(renderer, knight_def2[custom_def % 7], NULL, &rectangle);
                        }
                    }
                    else if(is_hitting_knight)
                    {
                        Mix_PlayMusic(hit2_knight, 0);

                        if(what_part == 0)
                        {
                            SDL_Rect rectangle1 = {begin_place_x, begin_place_y - 40, 160, 140};
                            SDL_RenderCopy(renderer, hitting_type1[custom_hit % 7], NULL, &rectangle1);
                        }
                        else
                        {
                            SDL_Rect rectangle1 = {begin_place_x - 60, begin_place_y - 40, 160, 140};
                            SDL_RenderCopy(renderer, hitting_type2[custom_hit % 7], NULL, &rectangle1);
                        }

                        is_hitting_knight = 0;
                    }
                    else
                    {
                        if(point3 < 100)
                        {
                            point3++;
                        }

                        if(what_part == 0)
                        {
                            SDL_RenderCopy(renderer, standing_knight_type1[custom_fps % 7], NULL, &rectangle);
                        }
                        else
                        {
                            SDL_RenderCopy(renderer, standing_knight_type2[custom_fps % 7], NULL, &rectangle);
                        }
                    }
                }
                else
                {
                    if(is_walking_wizard)
                    {
                        if(what_part == 0)
                        {
                            SDL_Rect rectangle1 = {begin_place_x, begin_place_y, 140, 100};
                            SDL_RenderCopy(renderer, walk_wiz1[run_wizard % 7], NULL, &rectangle1);
                        }
                        else
                        {
                            SDL_Rect rectangle1 = {begin_place_x - 40, begin_place_y, 140, 100};
                            SDL_RenderCopy(renderer, walk_wiz2[run_wizard % 7], NULL, &rectangle1);
                        }
                        is_walking_wizard = 0;
                    }
                    else if(is_hitting_wizard)
                    {
                        Mix_PlayMusic(magic_hit, 1);

                        if(what_part == 0)
                        {
                            SDL_Rect rectangle1 = {begin_place_x, begin_place_y - 40, 160, 140};
                            SDL_RenderCopy(renderer, hit_wiz1[fps_for_mage % 6], NULL, &rectangle1);
                        }
                        else
                        {
                            SDL_Rect rectangle1 = {begin_place_x - 60, begin_place_y - 40, 160, 140};
                            SDL_RenderCopy(renderer, hit_wiz2[fps_for_mage % 6], NULL, &rectangle1);
                        }

                        is_hitting_wizard = 0;
                    }
                    else
                    {
                        if(point2 < 100)
                        {
                            point2 = point2 + 1;
                        }

                        if(what_part == 0)
                        {
                            SDL_RenderCopy(renderer, wizard1[fps_for_mage % 6], NULL, &rectangle);
                        }
                        else
                        {
                            SDL_RenderCopy(renderer, wizard2[fps_for_mage % 6], NULL, &rectangle);
                        }
                    }
                }

                SDL_Rect rect = {600, begin_place_y, 100, 100};
                if(pick == 0 && helper_for_hitting_wizard == 1 && ((rectangle.x > 600 && what_part == 1) || (rectangle.x <= 600 && what_part == 0)))
                {
                    SDL_RenderCopy(renderer, body[body_fps % 4], NULL, &rect);
                }
                else if(pick == 1 && helper_for_hitting_knight == 1)
                {
                    if(is_intersects(rect, rectangle, what_part) == 1)
                    {
                        SDL_RenderCopy(renderer, body[body_fps % 4], NULL, &rect);
                    }
                    else
                    {
                        SDL_RenderCopy(renderer, hit[0], NULL, &rect);
                    }
                }
                else
                {
                    SDL_RenderCopy(renderer, hit[0], NULL, &rect);
                }

                SDL_RenderCopy(renderer, zel1, NULL, &zel_for1);
                SDL_RenderCopy(renderer, zel2, NULL, &zel_for2);
                SDL_RenderCopy(renderer, zel3, NULL, &zel_for3);
                SDL_RenderCopy(renderer, zel4, NULL, &zel_for4);
                SDL_RenderCopy(renderer, zel5, NULL, &zel_for5);

                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderFillRect(renderer, &health);

                if(pick == 0)
                {
                    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
                    SDL_RenderFillRect(renderer, &mana);
                }
                else
                {
                    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                    SDL_RenderFillRect(renderer, &stamina);
                }

                body_fps = (body_fps + 1) % 4;

                fps_for_mage = (fps_for_mage + 1) % 6;
                run_wizard = (run_wizard + 1) % 7;

                custom_fps = (custom_fps + 1) % 7;
                custom_def = (custom_def + 1) % 7;
                custom_run = (custom_run + 1) % 8;
                custom_hit = (custom_hit + 1) % 7;

                break;
            case GAME:
                set_background(renderer, table);

                if(pick == 1)
                {
                    if(is_walking_knight)
                    {
                        if(what_part == 0)
                        {
                            SDL_RenderCopy(renderer, knight_run1[custom_run % 8], NULL, &rectangle);
                        }
                        else
                        {
                            SDL_RenderCopy(renderer, knight_run2[custom_run % 8], NULL, &rectangle);
                        }
                        is_walking_knight = 0;
                    }
                    else if(is_defence_knight)
                    {
                        if(what_part == 0)
                        {
                            SDL_RenderCopy(renderer, knight_def1[custom_def % 7], NULL, &rectangle);
                        }
                        else
                        {
                            SDL_RenderCopy(renderer, knight_def2[custom_def % 7], NULL, &rectangle);
                        }
                    }
                    else if(is_hitting_knight)
                    {
                        if(what_part == 0)
                        {
                            SDL_Rect rectangle1 = {begin_place_x, begin_place_y - 40, 160, 140};
                            SDL_RenderCopy(renderer, hitting_type1[custom_hit % 7], NULL, &rectangle1);
                        }
                        else
                        {
                            SDL_Rect rectangle1 = {begin_place_x - 60, begin_place_y - 40, 160, 140};
                            SDL_RenderCopy(renderer, hitting_type2[custom_hit % 7], NULL, &rectangle1);
                        }
                    }
                    else
                    {
                        if(what_part == 0)
                        {
                            SDL_RenderCopy(renderer, standing_knight_type1[custom_fps % 7], NULL, &rectangle);
                        }
                        else
                        {
                            SDL_RenderCopy(renderer, standing_knight_type2[custom_fps % 7], NULL, &rectangle);
                        }
                    }
                }
                else
                {
                    if(is_walking_wizard)
                    {
                        if(what_part == 0)
                        {
                            SDL_Rect rectangle1 = {begin_place_x, begin_place_y, 140, 100};
                            SDL_RenderCopy(renderer, walk_wiz1[run_wizard % 7], NULL, &rectangle1);
                        }
                        else
                        {
                            SDL_Rect rectangle1 = {begin_place_x - 40, begin_place_y, 140, 100};
                            SDL_RenderCopy(renderer, walk_wiz2[run_wizard % 7], NULL, &rectangle1);
                        }
                        is_walking_wizard = 0;
                    }
                    else if(is_hitting_wizard)
                    {
                        if(what_part == 0)
                        {
                            SDL_Rect rectangle1 = {begin_place_x, begin_place_y - 40, 160, 140};
                            SDL_RenderCopy(renderer, hit_wiz1[fps_for_mage % 6], NULL, &rectangle1);
                        }
                        else
                        {
                            SDL_Rect rectangle1 = {begin_place_x - 60, begin_place_y - 40, 160, 140};
                            SDL_RenderCopy(renderer, hit_wiz2[fps_for_mage % 6], NULL, &rectangle1);
                        }
                    }
                    else
                    {
                        if(what_part == 0)
                        {
                            SDL_RenderCopy(renderer, wizard1[fps_for_mage % 6], NULL, &rectangle);
                        }
                        else
                        {
                            SDL_RenderCopy(renderer, wizard2[fps_for_mage % 6], NULL, &rectangle);
                        }
                    }
                }

                fps_for_mage = (fps_for_mage + 1) % 6;
                run_wizard = (run_wizard + 1) % 7;

                custom_fps = (custom_fps + 1) % 7;
                custom_def = (custom_def + 1) % 7;
                custom_run = (custom_run + 1) % 8;
                custom_hit = (custom_hit + 1) % 7;

                break;
            default:
                draw_lose(renderer, font, table1);
                break;
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }

    for(int i = 0; i < 6; i++)
    {
        SDL_DestroyTexture(wizard1[i]);
        SDL_DestroyTexture(wizard2[i]);
        SDL_DestroyTexture(hit_wiz1[i]);
        SDL_DestroyTexture(hit_wiz2[i]);
    }
    for(int i = 0; i < 7; i++)
    {
        SDL_DestroyTexture(walk_wiz1[i]);
        SDL_DestroyTexture(walk_wiz2[i]);

        SDL_DestroyTexture(hitting_type1[i]);
        SDL_DestroyTexture(hitting_type2[i]);

        SDL_DestroyTexture(standing_knight_type1[i]);
        SDL_DestroyTexture(standing_knight_type2[i]);
        SDL_DestroyTexture(knight_def1[i]);
        SDL_DestroyTexture(knight_def2[i]);
    }
    for(int i = 0; i < 8; i++)
    {
        SDL_DestroyTexture(knight_run1[i]);
        SDL_DestroyTexture(knight_run2[i]);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    SDL_Quit();
    TTF_Quit();
    Mix_Quit();

    return 0;
}
