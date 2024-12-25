#include <raylib.h>
#include <raylib-tileson.h>


#define ATTR_ORBIS_WIDTH 640
#define ATTR_ORBIS_HEIGHT 480

static bool done = false;
int x;
int y;
int scrollx;
int scrolly;
bool dpadLeftDown;
bool dpadRightDown;
bool dpadDownDown;
bool dpadUpDown;
Rectangle box;
static void updateController(void) {
    bool startPressed;

    if(!IsGamepadAvailable(0))
        return;

    startPressed = IsGamepadButtonPressed(0, GAMEPAD_BUTTON_MIDDLE_RIGHT);
    dpadLeftDown = IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT);
    dpadRightDown = IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT);
    dpadDownDown = IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN);
    dpadUpDown = IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP);

    if(startPressed)
        done = true;

    if(dpadUpDown)
    {
        y = y - 32;
        if(y<0)
        {
            y=0;
        }
        TraceLog(LOG_INFO, "main: %s up x:%d,y:%d",__FUNCTION__,x,y);
        if(y<3*640/2 && y>640/2)
        {
            scrolly=scrolly+32;
            TraceLog(LOG_INFO, "main: %s up scroolx:%d,scrolly:%d",__FUNCTION__,scrollx,scrolly);

        }
    }

    if(dpadDownDown)
    {
        y = y + 32;
        if(y>=1280-32)
        {
            y=1280-32;
        }
        TraceLog(LOG_INFO, "main: %s down x:%d,y:%d",__FUNCTION__,x,y);
        if(y>640/2 && y<3*640/2)
        {
            scrolly=scrolly-32;
            TraceLog(LOG_INFO, "main: %s down scroolx:%d,scrolly:%d",__FUNCTION__,scrollx,scrolly);

        }

    }

    if(dpadRightDown)
    {
        x = x + 32;
        if(x>=1280-32)
        {
            x=1280-32;
        }
        TraceLog(LOG_INFO, "main: %s right x:%d,y:%d",__FUNCTION__,x,y);
        if(x>640/2 && x<3*640/2)
        {
            scrollx=scrollx-32;
            TraceLog(LOG_INFO, "main: %s right scroolx:%d,scrolly:%d",__FUNCTION__,scrollx,scrolly);

        }

    }

    if(dpadLeftDown)
    {
        x = x - 32;
        if(x<0)
        {
            x=0;
        }
        TraceLog(LOG_INFO, "main: %s left x:%d,y:%d",__FUNCTION__,x,y);
        if(x<3*640/2 && x>640/2)
        {
            scrollx=scrollx+32;
            TraceLog(LOG_INFO, "main: %s left scroolx:%d,scrolly:%d",__FUNCTION__,scrollx,scrolly);

        }

    }




   
   
    

}

int main(int argc, char** argv) {

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = ATTR_ORBIS_WIDTH;
    const int screenHeight = ATTR_ORBIS_HEIGHT;

    x = screenWidth/2;
    y = screenHeight/2;
    scrollx=0;
    scrolly=0;

    box = { screenWidth/2, screenHeight/2, 32, 32 };
    InitWindow(screenWidth, screenHeight, "raylib [models] example - tileson");
    
    ChangeDirectory("/rd");
    
    TraceLog(LOG_INFO, "main: %s dir %s",__FUNCTION__,GetWorkingDirectory());

    //int bytesRead;
    //unsigned char* data = LoadFileData("desert.json", &bytesRead);
    //Map map = LoadTiledFromMemory(data, bytesRead, "./");

    
    Map map = LoadTiled("desert.json");

    TraceLog(LOG_INFO, "main: %s map status %d",__FUNCTION__,IsTiledReady(map));



    SetTargetFPS(60);     // Set our game to run at 60 frames-per-second
    //----------------------------------------------------------

    // Main game loop
    while(!done) {

        updateController();
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTiled(map, scrollx, scrolly, WHITE);

            //DrawRectangleRec(box, BLUE);

          
            ///DrawFPS(10, 10);

        EndDrawing();
        //-----------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadMap(map);
 
    CloseWindow();     // Close window and OpenGL context
    //----------------------------------------------------------

    return 0;
}
