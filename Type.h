#ifndef AZUL_TYPES
#define AZUL_TYPES
#define enum_to_string(x) #x

enum Color{
		RED = 'R', 
		YELLOW = 'Y', 
		DARK_BLUE = 'D', 
		LIGHT_BLUE = 'L', 
		BLACK = 'B', 
		FIRST_PLAYER  = 'F',
		NO_TILE
		};

#define MAX_WALL_COL 5
#define MAX_WALL_ROW 5
#define MAX_BROKENTILE 5
#define MAX_FACTORYNUMBER 4

#define NEW_GAME 1
#define LOAD_GAME 2
#define CREDITS 3
#define QUIT 4

#endif

