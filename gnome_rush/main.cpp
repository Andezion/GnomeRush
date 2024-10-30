#include <raylib.h>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Tanki");

    Image tanki = LoadImage("tanchik.png");
    Rectangle rect = {50, 70, 100, 100};
    ImageCrop(&tanki, rect);

    Texture2D texture = LoadTextureFromImage(tanki);

    UnloadImage(tanki);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(texture, 100, 100, WHITE);

        DrawFPS(10, 10);

        EndDrawing();
    }

    UnloadTexture(texture);
    CloseWindow();

    return 0;
}