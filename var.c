char Entry[7]; /* temporary name */
char NamP1[7],NamP2[7],NamP3[7],NamP4[7]; /* name Player 1-4 */
STAT_TYPE DexP[4],AtkP[4],DefP[4];
unsigned int ExpP[4]; /* carac Player 1-4*/
unsigned int spriteX;
unsigned int spriteY;
int HPp[4];
int MPp[4];
unsigned int MaxHP[4];
unsigned int MaxMP[4];
unsigned int BattleX[5];
unsigned int BattleY[5];
unsigned char itemnb[11]; /* item number*/
/*char play[5],round[5];*/
unsigned int roundCount[5]; /* round counter to indicate who is ready to fight*/
char FirstTime; /* move info */
/*unsigned char count;/*music counter*/
/*char *Track0,*Track1,*Track2,*Track3,*Track4,*Track5;
int *TrackLength0,*TrackLength1,*TrackLength2,*TrackLength3,*TrackLength4,*TrackLength5;
int Mus_Length;
int Mus_Repeat;*/
unsigned int monsterID;
unsigned int gameState;
unsigned int pos;
unsigned int oldpos;
unsigned char battleEnd;
unsigned int *move_in_map;
/**
 * Par groupe de 4 int
 * 1 : position sur la map
 * 2 : type d'évènement
 * 3 et 4 : pour des paramètres
 */
unsigned int *event_in_map;
unsigned int nb_events;
/**
 * Direction en cours de déplacement.
 * voir les constantes pour savoir quelle direction utilise quelle valeur
 */
int direction;

/**
 * Pattern du sprite à afficher lors du déplacement
 */
unsigned int SPRPATTERN;
unsigned char pattern;
unsigned char meter;
unsigned int monster;
char positive_pattern;

/**
 * Variables sur les monstres possibles dans une zone
 */

unsigned int *monsters_in_map;
unsigned char nb_monsters;
/**
 * Index du background à afficher en combat.
 * Utilisation d'une variable séparée pour indiquer le background pour la map.
 * Cela permet de séparer le background d'une map de celui d'un event spécifique.
 */
unsigned int battle_bg;
unsigned int map_battle_bg;

/**
 * Indicateur de la musique actuellement jouée.
 * 0 indique aucune musique.
 */
unsigned char currentMusic;

/**
 * Special event variables
 */
char first_time_map4;