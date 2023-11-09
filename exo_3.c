#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

#define HAUTEUR 400
#define LARGEUR 500
#define TAILLE_MAX 20


typedef struct point{
    int x;
    int y;
}Point;

typedef struct polygone{
    int taille;
    Point ensemble[TAILLE_MAX];
}Polygone;

void saisiePoint(Point * p){
    MLV_wait_mouse(&p->x, &p->y);
    printf("x: %d, y: %d\n", p->x, p->y);
}

void dessinePolygone(Polygone poly){
    int x_coords[poly.taille];
    int y_coords[poly.taille];
    int x, y;
    
    for (int i = 0; i < poly.taille; ++i){
        MLV_wait_mouse(&x, &y);
        *(x_coords + i) = x;
        *(y_coords + i) = y;
    }
    MLV_draw_polygon(x_coords, y_coords, poly.taille, MLV_COLOR_GREEN);
    printf("i\n");
}

int main(int argc, char * argv[]){
    Polygone poly;

    poly.taille = TAILLE_MAX;


    dessinePolygone(poly);

    //poly.ensemble[0].x = LARGEUR /2;
    //poly.ensemble[0].y = HAUTEUR /2;
    
    return 0;
}