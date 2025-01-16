# GnomeRush
There is my little project, where I've tried to use all abilities of SDL framework.
## Table of contents
* [General info](#general-info)
* [Gameplay](#gameplay)
* [Inspiration](#inspiration)
* [Technologies](#technologies)
* [Features](#features)
* [Setup](#setup)
---
## General info
After many hours spent reading The Hobbit, The Witcher and Lord of the Rings, I decided to play out my fantasy and put it to code. So, I'm proud to show you my medieval-themed wandering game. Mages, knights, dwarves and more! Explore, check it out and find out!
I wrote the game in pure C, using SDL, based on the base. Music, graphics, plot and so on - all my own!
---
## Gameplay
Now I will show you what you can do in my game

- There you can read some info about the game, sadly at this point I don't add pretty much to read, but it will appear in the nearest future!
  
https://github.com/Andezion/GnomeRush/assets/e25fb870-4614-41b1-ac73-63d7981098cb

- There you can try to play for the wizard! I still don't add some features and gameplays moment, but at least you can test some of them!
  
https://github.com/Andezion/GnomeRush/assets/9c4b5083-9af3-4b22-b81a-de36cf62488c

https://github.com/Andezion/GnomeRush/assets/9cb022f7-0d73-4a2f-920e-d81195b7ed90

- And there you can try yourself as a knight!
  
https://github.com/Andezion/GnomeRush/assets/f4ab9419-9439-42c0-92da-b556da106dc0

https://github.com/Andezion/GnomeRush/assets/641ad646-5dec-4b54-a93c-bf9bcca93e51

- If you want to end your game you will see something like that
  
https://github.com/Andezion/GnomeRush/assets/b50f2018-39f5-488e-b810-cde454b764c0

---
## Inspiration
- Crawly The Gnome
- Stopiaż z Bałut
- Project Dupa
---
## Technologies
Project created with:
* SDL for most features
* SDL_mixer for music
* SDL_image for correcting photoes
* SDL_ttf for text usage
* Photoshop for editing photoes
* Tavern music and beer
---
## Features
First we declare some important constants, window size and player position. 

The interesting thing is that the level switching is done via the enum construct, which makes it much easier to switch from one screen to another:
```
typedef enum
{
    MENU,
    WIKI,
    PICK,
    GAME,
    TEST,
    OVER
} GameState;
```

Next comes a very long and crookedly done initialisation of photos, texts, sounds and objects, and of course all this should have been put out separately and more beautifully, but! I didn't do it :(

Then again the declaration of variables for our character's animations and finally the algorithm for generating the background.  Initially we create a table, filling it with values that are later responsible for a certain colour:
```
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
```

Once the game loop starts, we just handle some keystroke events moving the player, changing and scrolling animations.
Then, depending on the player's action, we initialise our variables indicating running, standing, attacking or whatever, so that we can understand what animation we should include. 

Then we clear the window and start displaying our windows, which are stored in our enum, via switch. Then we play the desired animation, and the cycle repeats while we play.

Then we clear all arrays, because in SDL it is not done automatically )).
---
## Setup
Just download the recent release
