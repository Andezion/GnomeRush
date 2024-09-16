#include "handler_of_screen.h"

void draw_back(SDL_Renderer *renderer, int table[50][30], int type)
{
    int cell_size = 20;

    SDL_Rect cell;
    cell.w = cell_size;
    cell.h = cell_size;

    if(type == 1)
    {
        for(int i = 0; i < 50; i++)
        {
            for(int j = 0; j < 30; j++)
            {
                cell.x = i * cell_size;
                cell.y = j * cell_size;

                if(table[i][j] == 0)
                {
                    SDL_SetRenderDrawColor(renderer, 42, 34, 49, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
                else if(table[i][j] == 1)
                {
                    SDL_SetRenderDrawColor(renderer, 41, 33, 48, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
                else if(table[i][j] == 2)
                {
                    SDL_SetRenderDrawColor(renderer, 44, 33, 49, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
                else if(table[i][j] == 3)
                {
                    SDL_SetRenderDrawColor(renderer, 41, 33, 46, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
                else
                {
                    SDL_SetRenderDrawColor(renderer, 40, 32, 47, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
            }
        }
    }
    else if(type == 2)
    {
        for(int i = 0; i < 50; i++)
        {
            for(int j = 0; j < 30; j++)
            {
                cell.x = i * cell_size;
                cell.y = j * cell_size;

                if(table[i][j] == 0)
                {
                    SDL_SetRenderDrawColor(renderer, 255, 228, 181, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
                else if(table[i][j] == 1)
                {
                    SDL_SetRenderDrawColor(renderer, 255, 218, 185, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
                else if(table[i][j] == 2)
                {
                    SDL_SetRenderDrawColor(renderer, 238, 232, 170, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
                else if(table[i][j] == 3)
                {
                    SDL_SetRenderDrawColor(renderer, 240, 230, 140, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
                else
                {
                    SDL_SetRenderDrawColor(renderer, 189, 183, 107, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
            }
        }
    }
    else if(type == 3)
    {
        for(int i = 0; i < 50; i++)
        {
            for(int j = 0; j < 30; j++)
            {
                cell.x = i * cell_size;
                cell.y = j * cell_size;

                if(table[i][j] == 0)
                {
                    SDL_SetRenderDrawColor(renderer, 253, 245, 230, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
                else if(table[i][j] == 1)
                {
                    SDL_SetRenderDrawColor(renderer, 250, 235, 215, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
                else if(table[i][j] == 2)
                {
                    SDL_SetRenderDrawColor(renderer, 245, 245, 220, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
                else if(table[i][j] == 3)
                {
                    SDL_SetRenderDrawColor(renderer, 220, 220, 220, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
                else
                {
                    SDL_SetRenderDrawColor(renderer, 255, 239, 213, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < 50; i++)
        {
            for(int j = 0; j < 30; j++)
            {
                cell.x = i * cell_size;
                cell.y = j * cell_size;

                if(table[i][j] == 0)
                {
                    SDL_SetRenderDrawColor(renderer, 112, 128, 144, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
                else if(table[i][j] == 1)
                {
                    SDL_SetRenderDrawColor(renderer, 119, 136, 153, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
                else if(table[i][j] == 2)
                {
                    SDL_SetRenderDrawColor(renderer, 105, 105, 105, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
                else if(table[i][j] == 3)
                {
                    SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
                else
                {
                    SDL_SetRenderDrawColor(renderer, 169, 169, 169, 255);
                    SDL_RenderFillRect(renderer, &cell);
                }
            }
        }
    }
}

int loadTextureArray(SDL_Renderer* renderer, const char** fileNames, int arraySize, SDL_Texture** textureArray)
{
    for(int i = 0; i < arraySize; i++)
    {
        SDL_Surface* surface = SDL_LoadBMP(fileNames[i]);
        if (surface == NULL)
        {
            printf("Error loading image %d: %s\n", i, SDL_GetError());
            SDL_DestroyRenderer(renderer);
            return 1;
        }
        textureArray[i] = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        if (textureArray[i] == NULL)
        {
            printf("Error creating texture for image %d: %s\n", i, SDL_GetError());
            SDL_DestroyRenderer(renderer);
            return 1;
        }
    }
    return 0;
}

void draw_text(SDL_Renderer* renderer, const char* text, TTF_Font* font, SDL_Color color, int x, int y)
{
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, color);
    if (textSurface == NULL)
    {
        return;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textTexture == NULL)
    {
        SDL_FreeSurface(textSurface);
        return;
    }

    SDL_Rect renderQuad = {x, y, textSurface->w, textSurface->h};
    SDL_RenderCopy(renderer, textTexture, NULL, &renderQuad);

    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
}

int var_tor1 = 0;

void draw_menu(SDL_Renderer* renderer, TTF_Font* font, int table[50][30])
{
    SDL_Color textColor = {255, 255, 255, 255};

    SDL_Texture *torch1[8];
    const char *torch_1[8] = {"tor1.bmp",
                              "tor2.bmp",
                              "tor3.bmp",
                              "tor4.bmp",
                              "tor5.bmp",
                              "tor6.bmp",
                              "tor7.bmp",
                              "tor8.bmp"};

    if(loadTextureArray(renderer, torch_1, 8, torch1) != 0)
    {
        printf("Error in loading textures!");

        return;
    }

    SDL_Surface *surface = SDL_LoadBMP("Image1.bmp");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    if (TTF_Init() == -1)
    {
        printf("Error initializing TTF: %s\n", TTF_GetError());

        SDL_DestroyRenderer(renderer);
        SDL_Quit();

        return;
    }

    TTF_Font* font1 = TTF_OpenFont("font.ttf", 20);
    if (font == NULL)
    {
        printf("Error loading font: %s\n", TTF_GetError());

        SDL_DestroyRenderer(renderer);
        TTF_Quit();
        SDL_Quit();

        return;
    }

    draw_back(renderer, table, 1);

    SDL_Rect podstavka1 = {131, 210, 200, 200};
    SDL_RenderCopy(renderer, texture, NULL, &podstavka1);

    SDL_Rect podstavka2 = {681, 210, 200, 200};
    SDL_RenderCopy(renderer, texture, NULL, &podstavka2);

    SDL_Rect rect1 = {200, 250, 60, 140};
    SDL_RenderCopy(renderer, torch1[var_tor1 % 8], NULL, &rect1);

    SDL_Rect rect2 = {750, 250, 60, 140};
    SDL_RenderCopy(renderer, torch1[var_tor1 % 8], NULL, &rect2);

    var_tor1 = (var_tor1 + 1) % 8;

    SDL_Delay(100);

    draw_text(renderer, "Gnome Rush", font, textColor, 380, 300);
    draw_text(renderer, "If you want to start press - G", font1, textColor, 350, 360);
    draw_text(renderer, "If you want to pause game - L", font1, textColor, 355, 400);
    draw_text(renderer, "If you want to lose game - H", font1, textColor, 360, 440);
    draw_text(renderer, "If you want to read some info - J", font1, textColor, 335, 480);
}

int set_background(SDL_Renderer *renderer, int table[100][60])
{
    int cell_size = 10;

    SDL_Rect cell;
    cell.w = cell_size;
    cell.h = cell_size;

    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 60; j++)
        {
            cell.x = i * cell_size;
            cell.y = j * cell_size;

            if(table[i][j] == 0)
            {
                SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
                SDL_RenderFillRect(renderer, &cell);
            }
            else if(table[i][j] == 1)
            {
                SDL_SetRenderDrawColor(renderer, 0, 100, 0, 255);
                SDL_RenderFillRect(renderer, &cell);
            }
            else if(table[i][j] == 2)
            {
                SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255);
                SDL_RenderFillRect(renderer, &cell);
            }
            else if(table[i][j] == 3)
            {
                SDL_SetRenderDrawColor(renderer, 34, 139, 34, 255);
                SDL_RenderFillRect(renderer, &cell);
            }
            else
            {
                SDL_SetRenderDrawColor(renderer, 50, 205, 50, 255);
                SDL_RenderFillRect(renderer, &cell);
            }
        }
    }

    return 1;
}

void draw_lose(SDL_Renderer *renderer, TTF_Font *font, int table[50][30])
{
    SDL_Color textColor = {0, 0, 0, 255};

    draw_back(renderer, table, 2);

    draw_text(renderer, "You lose!", font, textColor, 420, 280);
}

int move_pers1 = 0;
int move_pers2 = 0;

void draw_pick(SDL_Renderer *renderer, TTF_Font *font, int table[50][30], int pick)
{
    SDL_Color textColor = {0, 0, 0, 255};

    draw_back(renderer, table, 3);

    SDL_Surface *surface1 = SDL_LoadBMP("prev.bmp");
    SDL_Texture *texture1 = SDL_CreateTextureFromSurface(renderer, surface1);

    SDL_Surface *surface2 = SDL_LoadBMP("next.bmp");
    SDL_Texture *texture2 = SDL_CreateTextureFromSurface(renderer, surface2);

    SDL_Rect rect1 = {100, 300, 100, 100};
    SDL_RenderCopy(renderer, texture1, NULL, &rect1);

    SDL_Rect rect2 = {800, 300, 100, 100};
    SDL_RenderCopy(renderer, texture2, NULL, &rect2);

    SDL_Surface *surface3 = SDL_LoadBMP("write.bmp");
    SDL_Texture *texture3 = SDL_CreateTextureFromSurface(renderer, surface3);

    SDL_Rect rect3 = {250, 150, 500, 400};
    SDL_RenderCopy(renderer, texture3, NULL, &rect3);


    SDL_Texture *standing_knight_type1[7];
    const char *standing_knight_type_1[7] = {"asset_knight1_stand1.bmp",
                                             "asset_knight1_stand2.bmp",
                                             "asset_knight1_stand3.bmp",
                                             "asset_knight1_stand4.bmp",
                                             "asset_knight1_stand3.bmp",
                                             "asset_knight1_stand2.bmp",
                                             "asset_knight1_stand1.bmp"};

    if(loadTextureArray(renderer, standing_knight_type_1, 7, standing_knight_type1) != 0)
    {
        SDL_Quit();
        return;
    }

    SDL_Texture *wizard1[6];
    const char *wizard_1[6] = {"mag1.bmp",
                               "mag2.bmp",
                               "mag3.bmp",
                               "mag4.bmp",
                               "mag5.bmp",
                               "mag6.bmp"};

    if(loadTextureArray(renderer, wizard_1, 6, wizard1) != 0)
    {
        SDL_Quit();
        return;
    }

    if(pick == 1)
    {
        draw_text(renderer, "Knight", font, textColor, 450, 530);
        SDL_Rect pers1 = {420, 250, 170, 170};
        SDL_RenderCopy(renderer, standing_knight_type1[move_pers1 % 7], NULL, &pers1);
    }
    else if(pick == 0)
    {
        draw_text(renderer, "Wizard", font, textColor, 450, 530);
        SDL_Rect pers2 = {420, 250, 170, 170};
        SDL_RenderCopy(renderer, wizard1[move_pers2 % 6], NULL, &pers2);
    }

    move_pers1 = (move_pers1 + 1) % 7;
    move_pers2 = (move_pers2 + 1) % 6;

    TTF_Font* font1 = TTF_OpenFont("font.ttf", 20);
    if (font == NULL)
    {
        printf("Error loading font: %s\n", TTF_GetError());

        SDL_DestroyRenderer(renderer);
        TTF_Quit();
        SDL_Quit();

        return;
    }

    if(pick == 1)
    {
        draw_text(renderer, "Damage - 10", font1, textColor, 50, 120);
        draw_text(renderer, "Stamina - 100", font1, textColor, 50, 150);
        draw_text(renderer, "W S A D to walk", font1, textColor, 800, 120);
        draw_text(renderer, "Left click to hit", font1, textColor, 800, 150);
        draw_text(renderer, "R to use shield", font1, textColor, 800, 180);
    }
    else
    {
        draw_text(renderer, "Damage - 5", font1, textColor, 50, 120);
        draw_text(renderer, "Mana - 100", font1, textColor, 50, 150);
        draw_text(renderer, "W S A D to walk", font1, textColor, 800, 120);
        draw_text(renderer, "Left click to hit", font1, textColor, 800, 150);
        draw_text(renderer, "T to use rage", font1, textColor, 800, 180);
    }

    draw_text(renderer, "Pick your fighter!", font, textColor, 330, 60);
    draw_text(renderer, "Enter  m", font1, textColor, 820, 470);
    draw_text(renderer, "to continue!", font1, textColor, 820 , 500);
    draw_text(renderer, "Enter  n", font1, textColor, 70, 470);
    draw_text(renderer, "to test!", font1, textColor, 70, 500);
}

void draw_wiki(SDL_Renderer *renderer, TTF_Font *font, int table[50][30], int where)
{
    draw_back(renderer, table, 4);
}

int is_intersects(SDL_Rect rect1, SDL_Rect rect2, int pick)
{
    if (pick == 0)
    {
        if (rect2.x >= rect1.x - 130 && rect2.x <= rect1.x)
        {
            return 1;
        }
    }
    else if(pick == 1)
    {
        if(rect2.x >= rect1.x && rect2.x <= rect1.x + 140)
        {
            return 1;
        }
    }
    return 0;
}