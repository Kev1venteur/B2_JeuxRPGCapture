#include "Jeux.h"
#include <stdlib.h>

int main()
{
    Jeux* monJeux = new Jeux();
    monJeux->jouer();
    free(monJeux);
    return 0;
}
