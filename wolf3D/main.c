

#include "cub3d/cub3d.h"

int main(int argc, char **argv)
{
    // l'ensemble de la configuration pour le parsing du fichier deja faite.

    t_game game;

    init_map(&game);
    start_game(&game);

    return(EXIT_SUCCESS);
}