//
// Created by dyaki on 3/22/2019.
//

#include "logic.h"
#include "interface.h"

// Take Game, use logic and make one step, move pointer from _game to new_game
void stepGame(Game *_game) {
    if (_game == NULL) {
        // TODO Add here log err msg
        return;
    }
    size_t size = _game->size;

    Game *new_game = initGame(size + 2);
    size_t new_size = new_game->size;

    for (int i = 1; i < new_size - 1; i++)
        for (int j = 1; j < new_size - 1; j++)
            new_game->map[i][j] = _game->map[i - 1][j - 1];

    updateMap(new_game);
    for (int i = 1; i < new_size - 1; i++) {
        new_game->map[0][i] = new_game->map[new_size - 2][i];
        new_game->map[new_size - 1][i] = new_game->map[1][i];
        new_game->map[i][0] = new_game->map[i][new_size - 2];
        new_game->map[i][new_size - 1] = new_game->map[i][1];
    }
    new_game->map[0][0] = _game->map[size - 1][size - 1];
    new_game->map[new_size - 1][new_size - 1] = _game->map[0][0];
    new_game->map[0][new_size - 1] = _game->map[size - 1][0];
    new_game->map[new_size - 1][0] = _game->map[0][size - 1];
    updateMap(new_game);

    size_t countLife = 0;
    for (int i = 1; i < new_size - 1; i++)
        for (int j = 1; j < new_size - 1; j++) {
            countLife = new_game->map[i - 1][j - 1] + new_game->map[i - 1][j] + new_game->map[i - 1][j + 1] +
                        new_game->map[i][j - 1] + new_game->map[i][j + 1] + new_game->map[i + 1][j - 1] +
                        new_game->map[i + 1][j] + new_game->map[i + 1][j + 1];
            if (new_game->map[i][j] == 1 && (countLife > 3 || countLife < 2)) {
                new_game->map[i][j] = 0;
            } else if (new_game->map[i][j] == 0 && (countLife == 3)) {
                new_game->map[i][j] = 1;
            }
        }

    endGame(new_game);
}