add_executable(tetris_mini src/tetris.c src/input.c src/render.c src/shape.c src/state.c src/terminal.c)

target_include_directories(tetris_mini PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/inc")
