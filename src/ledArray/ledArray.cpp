// This module will simulate the physical LED array as a window in which m*n 
// cells will be lit up according to the values of the memory addresses shared 
// by the microMem module
#include <iostream>
#include <SDL.h>

int main() {
    const int nx = 1440; // Number of columns (width)
    const int ny = 810;  // Number of rows (height)

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Color Grid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, nx, ny, 0);
    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw the grid
    for (int x = 0; x < nx; x++) {
        for (int y = 0; y < ny; y++) {
            float r = static_cast<float>(x) / nx;
            float g = static_cast<float>(y) / ny;
            float b = 0.2;

            int ir = static_cast<int>(255.99 * r);
            int ig = static_cast<int>(255.99 * g);
            int ib = static_cast<int>(255.99 * b);

            SDL_SetRenderDrawColor(renderer, ir, ig, ib, 255);
            SDL_RenderDrawPoint(renderer, x, ny - y);
        }
    }

    // Present the renderer
    SDL_RenderPresent(renderer);

    // Wait for a key press
    bool quit = false;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN) {
                quit = true;
            }
        }
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}