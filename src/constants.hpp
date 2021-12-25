#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

inline constexpr float ANALOG_DEADZONE_MULTIPLIER = 0.5;

inline constexpr int BOARD_WIDTH = 8;
inline constexpr int BOARD_HEIGHT = 7;

#if defined(__vita__)
inline constexpr int SCREEN_WIDTH = 960;
inline constexpr int SCREEN_HEIGHT = 544;
inline constexpr int SHELL_SIZE = 64;
#elif defined(__PSP__)
inline constexpr int SCREEN_WIDTH = 480;
inline constexpr int SCREEN_HEIGHT = 272;
inline constexpr int SHELL_SIZE = 32;
#else
inline constexpr int SCREEN_WIDTH = 1920;
inline constexpr int SCREEN_HEIGHT = 1080;
inline constexpr int SHELL_SIZE = 128;
#endif

inline constexpr int FONT_SIZE = SHELL_SIZE/2;
inline constexpr int FONT_SIZE_TITLE = SHELL_SIZE;

inline constexpr int DROP_TIME = 400;
inline constexpr float DROP_STEP = DROP_TIME/SHELL_SIZE;

inline constexpr int MATCH_TIME = 1000;

#endif // CONSTANTS_HPP
