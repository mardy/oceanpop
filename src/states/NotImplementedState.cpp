#include "NotImplementedState.hpp"

NotImplementedState::NotImplementedState(SDL_Renderer * renderer, FontManager * fonts, SoundManager * sounds, OptionManager * options) :
    theme(renderer, options, Theme::MENU),
    screen_text(renderer, fonts, options, "Not Yet Implemented", "press the confirm button to continue")
{
    this->renderer = renderer;
    this->fonts = fonts;
    this->sounds = sounds;
    this->options = options;
}

NotImplementedState::~NotImplementedState() {
}

void NotImplementedState::update() {

}

void NotImplementedState::handleEvents(std::vector<Event> events) {
    for(Event event: events) {
        if (event == Event::QUIT) {
            this->next_state = State::EXIT;
            this->done = true;
        } else if (event == Event::CONFIRM || event == Event::CANCEL || event == Event::MENU) {
            this->done = true;
        }
    }
}

void NotImplementedState::draw(SDL_Renderer *renderer) {
    this->theme.draw(renderer);
    screen_text.draw(renderer);
}

State NotImplementedState::getNextState() {
    return this->next_state;
}
