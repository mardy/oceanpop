#include <iostream>
#include <stdexcept>
#include <vector>
#include "Window.hpp"
#include "StateManager.hpp"
#include "EventManager.hpp"
#include "TextureManager.hpp"
#include "utils.hpp"
#include "constants.hpp"
#include "states/MenuState.hpp"

void run() {
    Window window("Match Theory", SCREEN_WIDTH, SCREEN_HEIGHT);
    StateManager state_manager(window.renderer);
    EventManager input_manager;
    TextureManager texture_manager;

    while (!window.should_close && !state_manager.isDone()) {
        std::vector<Event> events = input_manager.getEvents(window);

        state_manager.handleEvents(events);
        state_manager.update();

        window.clear();
        state_manager.draw(window.renderer);
        window.present();
    }
}

int main(int argv, char** args) {
    (void) argv;
    (void) args;

    // try {
    //     run();
    // } catch (...) {
    //     std::rethrow_exception(std::current_exception());
    // }
    run();

    return EXIT_SUCCESS;
}
