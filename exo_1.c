#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

#define HAUTEUR 400
#define LARGEUR 500

typedef struct point{
    int x;
    int y;
}Point;

typedef struct droite{
    double a;
    double b;
}Droite;

/**
 * @brief Saisie de x et y comme paramètres
 * 
 * @param p 
 */
void saisiePoint(Point * p){
    MLV_wait_mouse(&p->x, &p->y);
    printf("x: %d, y: %d\n", p->x, p->y);
}

/**
 * @brief La construction de la Droite à partir de 2 points
 * 
 * @param a 
 * @param b 
 * @param d 
 * @return int 
 */
int construireDroite(Point a, Point b, Droite *d){
    // ax + by + c = 0
    // y = ax + b 
    // b = y - ax
    if (!(b.x - a.x)) { printf("Division par zéro! \n"); return 0; }
    d -> a = (double)(b.y - a.y) / (b.x - a.x);
    d -> b = (double) b.y - (d -> a) * b.x;
    printf("a: %lf, b: %lf\n", d->a, d->b);
    return 1;
}


void dessineDroite(Droite d){
    /*
    * void MLV_draw_line(
    *    int       x1,       Coordonnée en X de la première extrémité de la ligne
    *    int       y1,       Coordonnée en Y de la première extrémité de la ligne
    *    int       x2,       Coordonnée en X de la deuxième extrémité de la ligne
    *    int       y2,       Coordonnée en Y de la deuxième extrémité de la ligne
    *    MLV_Color color     Couleur du tracé
    * );
    */
    
    MLV_draw_line(0, LARGEUR-1, d.b, d.a , MLV_COLOR_GREEN);
    MLV_update_window();
}



int main( int argc, char *argv[] ){

    MLV_create_window( "Exo - 1 - Point", "Point", LARGEUR, HAUTEUR );
    Point a;
    Point b;
    Droite d;
    saisiePoint(&a);
    MLV_update_window();
    saisiePoint(&b);
    int res = construireDroite(a, b, &d);
    printf("res : %d", res);
    MLV_update_window();

    dessineDroite(d);
	//
	// Attend 5 secondes avant la fin du programme.
	//
	MLV_wait_seconds( 5 );

	//
	// Ferme la fenêtre
	//
	MLV_free_window();

    return 0;
}