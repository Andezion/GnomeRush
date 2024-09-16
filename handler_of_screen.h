#ifndef SDL_T2_HANDLER_OF_SCREEN_H
#define SDL_T2_HANDLER_OF_SCREEN_H

#include <SDL.h>
#include <stdio.h>
#include <SDL2/SDL_ttf.h>

int loadTextureArray(SDL_Renderer *renderer, const char **fileNames, int arraySize, SDL_Texture **textureArray);

void draw_text(SDL_Renderer *renderer, const char *text, TTF_Font *font, SDL_Color color, int x, int y);

void draw_menu(SDL_Renderer *renderer, TTF_Font *font, int table[50][30]);
void draw_lose(SDL_Renderer *renderer, TTF_Font *font, int table[50][30]);
void draw_pick(SDL_Renderer *renderer, TTF_Font *font, int table[50][30], int pick);
void draw_wiki(SDL_Renderer *renderer, TTF_Font *font, int table[50][30], int where);

void draw_back(SDL_Renderer *renderer, int table[50][30], int type);
int set_background(SDL_Renderer *renderer, int table[100][60]);

int is_intersects(SDL_Rect rect1, SDL_Rect rect2, int pick);

#endif //SDL_T2_HANDLER_OF_SCREEN_H
