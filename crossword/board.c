#include "board.h"
#include <stdio.h>
#include <stdlib.h>



void display_board(const struct board_t *board)
{
    if(board == NULL || board->board == NULL || board->height <= 0 || board->width <= 0)
    {
        return;
    }

    for(int i = 0; i < board->height; i++)
    {
        for(int j = 0; j < board->width; j++)
        {
            printf("%c",*(*(board->board + i) + j));
        }
        printf("\n");
    }
}

void free_board(struct board_t *board)
{
    if(board == NULL || board->board == NULL || board->height <= 0 || board->width <= 0)
    {
        return;
    }

    for(int i = 0; i < board->height; i++)
    {
        free(*(board->board + i));
    }
    free(board->board);
    free(board);
}

int set_player(struct board_t *board, int x, int y)
{
    if(board==NULL || board->board == NULL || board->width <= 0 || board->height <= 0 ||
    board->is_init == 1 || x < 0 || y < 0 || x >= board->width || y >= board->height)
    {
        return 1;
    }

    for(int i = 0; i < board->height; i++)
    {
        if (*(board->board + i) == NULL)
        {
            return 1;
        }
    }

    board->player.x = x;
    board->player.y = y;

    board->is_init = 1;

    *(*(board->board + y) + x) = '@';

    return 0;
}

struct board_t* move_player_up(struct board_t *desk)
{
    if(desk == NULL || desk->player.y >= desk->height || desk->is_init !=1 || desk->width <= 0 || desk->height <= 0
    || desk->board == NULL || desk->player.x < 0 || desk->player.y < 0 || desk->player.x >= desk->width)
    {
        return NULL;
    }

    for(int i = 0; i < desk->height; i++)
    {
        if(*(desk->board + i) == NULL)
        {
            return NULL;
        }
    }

    *(*(desk->board + desk->player.y) + desk->player.x) = '.';
    desk->player.y = desk->player.y - 1;

    if(desk->player.y == -1)
    {
        desk->player.y = desk->height - 1;
    }

    *(*(desk->board + desk->player.y) + desk->player.x) = '@';
    return desk;
}

struct board_t* move_player_down(struct board_t *desk)
{
    if(desk==NULL || desk->player.y >= desk->height || desk->is_init != 1 || desk->width <= 0 || desk->height <= 0 ||
       desk->board == NULL || desk->player.x < 0 || desk->player.y < 0 || desk->player.x >= desk->width)
    {
        return NULL;
    }

    for(int i = 0; i < desk->height; i++)
    {
        if(*(desk->board+i) == NULL)
        {
            return NULL;
        }
    }

    *(*(desk->board + desk->player.y) + desk->player.x) = '.';
    desk->player.y = desk->player.y + 1;

    if(desk->player.y == desk->height)
    {
        desk->player.y = 0;
    }

    *(*(desk->board + desk->player.y) + desk->player.x) = '@';
    return desk;
}

struct board_t* move_player_left(struct board_t *desk)
{
    if(desk==NULL || desk->player.y >= desk->height || desk->is_init != 1 || desk->width <= 0 || desk->height <= 0 ||
       desk->board == NULL || desk->player.x < 0 || desk->player.y < 0 || desk->player.x >= desk->width)
    {
        return NULL;
    }

    for(int i=0; i<desk->height; i++)
    {
        if (*(desk->board + i) == NULL)
        {
            return NULL;
        }
    }

    *(*(desk->board + desk->player.y) + desk->player.x) = '.';
    desk->player.x = desk->player.x - 1;

    if(desk->player.x == -1)
    {
        desk->player.x = desk->width - 1;
    }

    *(*(desk->board + desk->player.y) + desk->player.x) = '@';
    return desk;
}

struct board_t* move_player_right(struct board_t *desk)
{
    if(desk==NULL || desk->player.y >= desk->height || desk->is_init != 1 || desk->width <= 0 || desk->height <= 0 ||
       desk->board == NULL || desk->player.x < 0 || desk->player.y < 0 || desk->player.x >= desk->width)
    {
        return NULL;
    }

    for(int i = 0; i < desk->height; i++)
    {
        if (*(desk->board + i) == NULL)
        {
            return NULL;
        }
    }

    *(*(desk->board + desk->player.y) + desk->player.x) = '.';
    desk->player.x = desk->player.x + 1;

    if(desk->player.x == desk->width)
    {
        desk->player.x = 0;
    }

    *(*(desk->board + desk->player.y) + desk->player.x) = '@';
    return desk;
}