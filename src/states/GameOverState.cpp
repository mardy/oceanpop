#include "GameOverState.hpp"

GameOverState::GameOverState(SDL_Renderer * renderer, FontManager * fonts, SoundManager * sounds) :
    theme(renderer, Theme::MENU),
    screen_text(renderer, "Game Over!", "Press the confirm button to exit")
{
    this->renderer = renderer;
    this->fonts = fonts;
    this->sounds = sounds;
}

GameOverState::~GameOverState() {
}

void GameOverState::update() {
    if (!this->sound_played) {
        this->sounds->play(Sound::FAILED);
        this->sound_played = true;
    }
}

void GameOverState::handleEvents(std::vector<Event> events) {
    for(Event event: events) {
        if (event == Event::CONFIRM) {
            this->done = true;
        }
    }
}

void GameOverState::draw(SDL_Renderer *renderer) {
    this->theme.draw(renderer);
    screen_text.draw(renderer);
}

State GameOverState::getNextState() {
    return State::MENU;
}
