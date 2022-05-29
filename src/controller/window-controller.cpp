#include <controller/window-controller.hpp>
#include <gui/world/world.hpp>
#include <gui/world/board-tile.hpp>
#include <gui/window.hpp>

WindowController::WindowController() {
    World world;
    Window window = Window(&world);

    window.init();
    // TODO Improve this thing. Try to use unique_ptr or something else
    for (auto x = 0; x < 8; x++)
    {
        for (auto y = 0; y < 8; y++)
        {
            BoardTile *tile = new BoardTile(window.renderer, {
                origin : Gui::Point({x : x * 50, y : y * 50}),
                size : Gui::Size({x : 50, y : 50})
            });
            world.addWorldObject(tile);
        }
    }

    bool shouldExit = false;
    SDL_Event event;
    while (!shouldExit)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            // std::cout << "Received an event: " << event.type << "\n";
            switch (event.type)
            {
            case SDL_QUIT:
                shouldExit = true;
                break;
            case SDL_WINDOW_MOUSE_FOCUS:
                // world.processEvent({type : MOUSE_ENTERED, point : {x : event.motion.x, y : event.motion.y}});
                break;
            case SDL_MOUSEBUTTONDOWN:
                // world.processEvent({type : MOUSE_CLICKED, point : {x : event.motion.x, y : event.motion.y}});
                break;
            }
        }
        window.update();
        SDL_Delay(1000 / 10);
    }
}