#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"


//mingw argument de compilation
//Gérer les bibliothèque win32
// le reste des questions
//6)7)
int main(int argc, char *argv[])
{
    int i=0;
    for(i=0; i<argc; i++)
        printf("%s",argv[i]);

    SDL_Window *pWindow = NULL; //Pointeur SDL_Window possede la référence d'un
    SDL_Renderer *pRenderer = NULL; //Pointeur typedef SDL_Renderer posseède la référence du rendu encapsulée dans Window
    //SDL_Texture *pTexture = NULL; //Pointeur typedef SDL_Texture possède la référence l'objet image matériel ou texture qui sera mutter à l'écran

    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {

        pWindow = SDL_CreateWindow("Doesn't work!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, SDL_WINDOW_SHOWN);

        if(pWindow != NULL)
            pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
        while (i < 40)
        {
            int red = rand() % 255;
            int green = rand() % 255;
            int blue = rand() % 255;

            SDL_SetRenderDrawColor(pRenderer, red, green, blue, 0);
            SDL_RenderFillRect(pRenderer, NULL);
            SDL_RenderPresent(pRenderer);
            SDL_Delay(50);

            i++;
        }
        SDL_DestroyRenderer(pRenderer);
        SDL_DestroyWindow(pWindow);
        SDL_QUIT;
    }


    return 0;
}
//8)Gestion d’une fenêtre SDL 2, donnez les primitives
//associées à la fenêtre SDL 2
int main(int argc, char argv[])
{
    SDL_Window window;

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Erreur SDL : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    window = SDL_CreateWindow("A SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900, SDL_WINDOW_RESIZABLE);


    if(window == NULL)
    {
        printf("Erreur de creation windows : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Delay(1000);

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
//9)Gérer un rendu : qu’est-ce qu’un renderer, comment
//est-il associé à la fenêtre SDL 2 ? Donnez et expliquez le
//code permettant de gérer un rendu, création, affichage,
//effacement….
int main(int argc, char *argv[])
{
	SDL_Window* window;
	SDL_Renderer* renderer;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Error initializing SDL : %s", SDL_GetError());
		return EXIT_FAILURE;
	}
	window = SDL_CreateWindow("A SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_RESIZABLE);

	if(window == NULL)
	{
		printf("Error creating the window : %s", SDL_GetError());
		return EXIT_FAILURE;
	}
renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL)
	{
		printf("Error creating the renderer : %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	SDL_SetRenderDrawColor(renderer, 255,0,255,255);

	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);

	SDL_Delay(3000);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;

//10)SDL_Point et SDL_Rect :
//Donnez et expliquez le code de la déclaration d’un
//SDL_Point et SDL_Rect
int main(int argc, char *argv[])

SDL_Point points[500];
    for(int i = 0; i<499; i++)
    {
        points[i].x = i+4;
        points[i].y = 500;
        //cela fera une bouble dans la table
    }
typedef struct{
    Sint16 x, y;
    Sint16 w, h;
}SDL_Rect;
//Creation du rect :
SDL_Rect rectangle = {0,0,100,100};

//11 ) Les couleurs avec la SDL2 : donnez les instructions
//permettant de gérer la couleur avec la SDL 2

/*Uint8 r = red
Uint8 g = green
Uint8 b = blue
Uint8 a = alpha*/

SDL_Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

//12 Donnez le code permettant d’afficher un fond rouge
//dans le rendu.

  //Red color
    SDL_SetRenderDrawColor(renderer, 255,0,0,255);
    //on vide ensuite la fenêtre en utilisant :
    SDL_RenderClear(renderer);
//afficher le rendu  avec
    SDL_RenderPresent(renderer);
/*13) Dessiner dans le rendu : donnez le code des fonctions
permettant de dessiner dans le rendu les formes
suivantes :*/
{
	SDL_Window* window;
	SDL_Renderer* renderer;
    SDL_Surface* surface = SDL_CreateRGBSurface(0, 300, 300, 64, 0, 0, 0, 0);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,200,100);
    SDL_Rect rect = {300,300,300,300};
    SDL_Rect rect2 = {300, 300, 600, 600};
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Error initializing SDL : %s", SDL_GetError());
		return EXIT_FAILURE;
	}
	window = SDL_CreateWindow("A SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_RESIZABLE);
	if(window == NULL)
	{
		printf("Error creating the window : %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL)
	{
		printf("Error creating the renderer : %s", SDL_GetError());
		return EXIT_FAILURE;
	}
	//la culeur rouge
   	SDL_SetRenderDrawColor(renderer, 255,255,255,255);
   	SDL_RenderClear(renderer);
    SDL_SetRenderTarget(renderer, texture);
    SDL_RenderDrawLine(renderer, 0, 0, 250, 25);
    SDL_SetRenderTarget(renderer, NULL);
    SDL_Rect t_Position;
    t_Position.x = 100;
    t_Position.y = 200;
    SDL_QueryTexture(texture, NULL, NULL, &t_Position.w, &t_Position.h);
    SDL_RenderCopy(renderer, texture, NULL, &t_Position);
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, 255, 0, 0));
    SDL_RenderFillRect(renderer, &rect2);
	DrawCircle(renderer, 150, 300, 150);
    DrawFilledCircle(renderer, 500, 300, 150);
	//affichage du rendu
	SDL_RenderPresent(renderer);
	SDL_Delay(3000); //3000=3s
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;

}
// cercle
void DrawCircle(SDL_Renderer *p_renderer, int origin_x, int origin_y, int radius, SDL_Color color)
{
    int new_x = 0;
    int new_y = 0;
    int old_x =  origin_x + radius;
    int old_y = origin_y;
    float step = (M_PI * 2) / 50;
    SDL_SetRenderDrawColor(p_renderer, color.r, color.g, color.b, 255);
    for(float theta = 0; theta <= (M_PI * 2); theta += step){
        new_x = origin_x + (radius * cos(theta));
        new_y = origin_y - (radius * sin(theta));
        SDL_RenderDrawLine(p_renderer, old_x, old_y, new_x, new_y);
        old_x = new_x;
        old_y = new_y;
    }
    new_x = origin_x + radius;
    new_y = origin_y;
    SDL_RenderDrawLine(p_renderer, old_x, old_y, new_x, new_y);
}
// le cercle mais, rempli
void DrawFilledCircle(SDL_Renderer *p_renderer, int origin_x, int origin_y, int radius, SDL_Color color)
{
    for(double dy = 1; dy <= radius; dy += 1.0){
        double dx = floor(sqrt((2.0 * radius * dy) - (dy * dy)));
        SDL_SetRenderDrawColor(p_renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawLine(p_renderer, origin_x - dx, origin_y + dy - radius, origin_x + dx, origin_y + dy - radius);
        SDL_RenderDrawLine(p_renderer, origin_x - dx, origin_y - dy + radius, origin_x + dx, origin_y - dy + radius);
    }
}

//14 Quelles sont les fonctions permettant de dessiner
//des points et des lignes ?

SDL_RenderDrawPoint(renderer, 100, 100);

/*15) A quoi servent les fonctions SDL_RenderClear et
SDL_RenderPresent*/

SDL_RenderClear = cela sert à nettoyer le rendu avec la couleur
SDL_RenderPresent= il met à jour le rendu avec tout les appels précédent
/*16 Expliquez SDL_Delay*/

 SDL_Delay= il oblige le programme à attendre un temps donné  avant de se lancer
 //17) Qu’est-ce qu’une surface en SDL 2 ?
"c'est une collection de pixel utilisé dans le logiciel blitting, dans une structure"
//18 Donnez le code permettant de créer une surface
SDL_Surface* surface;
surface = SDL_CreateRGBSurface (0, 100, 100, 32, 0, 0, 0, 0);
if(surface == NULL)
{
    printf("Error creating a surface : %s", SDL_GetError());
    return EXIT_FAILURE;
}
/*19) Dessiner dans une surface : Donnez le code de la
fonction SDL_FillRect*/
int SDL_FillRect(SDL_Surface* dst, const SDL_Rect* rect, Uint32 color)
/*20 SDL_BlitSurface(..) : donnez le code pour tester
cette méthode.*/


int main(int argc, char *argv[])
{
	SDL_Window* window;
	SDL_Renderer* renderer;
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,200,100);
    SDL_Rect rect = {100,100,100,100};
    SDL_Rect rect2 = {300, 300, 600, 600};
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Erreur initialisation du rendu : %s", SDL_GetError());
		return EXIT_FAILURE;
	}
	window = SDL_CreateWindow(" SDL ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_RESIZABLE);
	if(window == NULL)
	{
		printf("erreur de creation de la fenetre : %s", SDL_GetError());
		return EXIT_FAILURE;
	}
	//creation du rendu
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL)
	{
		printf("Erreur de la creation du rendu : %s", SDL_GetError());
		return EXIT_FAILURE;
	}


    SDL_Surface* src_surface = SDL_CreateRGBSurface(0, 1280, 720, 32, 0, 0, 0, 0);
    SDL_Surface* dst_surface = SDL_CreateRGBSurface(0, 1280, 720, 32, 0, 0, 0,0);
	//couleur rouge
   	SDL_FillRect(src_surface, &rect, SDL_MapRGB(src_surface->format, 255, 0, 255));
   	SDL_BlitSurface(src_surface, NULL, dst_surface, NULL);
    SDL_Texture* text_surface = SDL_CreateTextureFromSurface(renderer, dst_surface);
   	SDL_RenderClear(renderer);
	SDL_SetRenderTarget(renderer, text_surface);
	SDL_RenderCopy(renderer, text_surface, NULL, NULL);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;

}
/*21) Les textures : Qu’est-ce qu’une texture ? Donnez
le code permettant de créer une texture.*/
SDL_Texture *texture;
texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1024, 768);
 /*22) Dessinez dans une texture : SDL_RenderTarget,
donnez le code pour tester cette méthode.*/
SDL_SetRenderTarget(renderer, text_surface);
/*23 SDL_RenderCopy : A quoi sert cette méthode,
donnez le code pour tester cette méthode*/
"c'est est une fonction qui copie une partie d'une texture dans le rendu actuel"
int SDL_RenderCopy(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect);
/*24 SDL_QueryTexture : A quoi sert cette méthode,
donnez le code pour tester cette méthode*/

    SDL_Surface* src_surface = SDL_CreateRGBSurface(0, 1280, 720, 32, 0, 0, 0, 0);
    SDL_Surface* dst_surface = SDL_CreateRGBSurface(0, 1280, 720, 32, 0, 0, 0,0);

       SDL_FillRect(src_surface, &rect, SDL_MapRGB(src_surface->format, 255, 0, 255));
       SDL_BlitSurface(src_surface, NULL, dst_surface, NULL);
    SDL_Texture* text_surface = SDL_CreateTextureFromSurface(renderer, dst_surface);
       SDL_RenderClear(renderer);
    int format = 0;
    int access = 0;
    int width = 0;
    int height = 0;
    if(SDL_QueryTexture(text_surface, &format, &access, &width, &height) != 0){
        return EXIT_FAILURE;
    }else{
        printf("Texture Width: %d / Texture Height: %d", width, height);
        }
/*25 Les Images : La SDL2 ne prend en charge
nativement que les formats bmp, si vous souhaitez
utiliser d’autres formats vous devrez associer la lib
SDL2_image à votre projet. SDL_LoadBMP, est la
méthode permettant d’utiliser des bmp, donnez le
code permettant de tester cette fonction.*/
const char* kimage = "automne.bmp";
SDL_Surface* src_surface = SDL_LoadBMP(kimage);

/*26 Donnez le code permettant de créer une texture à
partir d’une image (bmp)*/
const char* kimage = "automne.bmp";
SDL_Surface* src_surface = SDL_LoadBMP(kimage);
if(src_surface == NULL){
    printf("Image non reconnu");
}
SDL_Texture* text_surface = SDL_CreateTextureFromSurface(renderer, src_surface);

/*27 Prenez une image de votre choix au format bmp
et testez les fonctions précédentes en ajoutant le
code permettant d’afficher l’image dans le rendu. (15
points)*/
SDL_SetRenderTarget(renderer, text_surface);
SDL_RenderCopy(renderer, text_surface, NULL, NULL);
SDL_RenderPresent(renderer);

/*28 Depuis le début nous créons des instances
permettant de manipuler la sdl2, cependant nous
oublions une étape essentielle dans son utilisation, la
destruction des instances, faites un relevé des
instances crées et identifier les méthodes que vous
devez utiliser pour libérer celles-ci.*/

SDL_DestroySurface(surface);
SDL_DestroyTexture(texture);
SDL_DestroyRenderer(rendu);
SDL_DestroyWindow(fenêtre);
/*29 typedef struct sdl_manager{
 SDL_Window *pWindow;
 SDL_Renderer *pRenderer;
 SDL_Texture *ptexture;
 SDL_Surface *psurface;
 }
Vous avez codé votre programme, fonctions et
procédures à la volée afin de tester plus précisément les
méthodes. A l’aide du type structuré ci-dessus, je vous
demande de reprendre votre programme afin de l’améliorer
et de proposer suivant les règles de la programmation
modulaire et des notions de patterns (MVC) une nouvelle
version plus structurée et plus performante que la version
précédemment proposée.*/

typedef struct sdl_manager{
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
    SDL_Texture *pTexture;
    SDL_Surface *pSurface;
};


