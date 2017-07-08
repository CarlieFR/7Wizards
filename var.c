char Entry[7]; /* temporary name */
char NamP1[7],NamP2[7],NamP3[7],NamP4[7]; /* name Player 1-4 */
int DexP[4],AtkP[4],DefP[4],ExpP[4]; /* carac Player 1-4*/
int spriteX,spriteY,HPp[4],MPp[4],MaxHP[4],MaxMP[4],BattleX[5],BattleY[5];
char itemnb[11]; /* item number*/
/*char play[5],round[5];*/
int roundCount[5]; /* round counter to indicate who is ready to fight*/
char FirstTime; /* move info */
char count;/*music counter*/
char *Track0,*Track1,*Track2,*Track3,*Track4,*Track5;
int *TrackLength0,*TrackLength1,*TrackLength2,*TrackLength3,*TrackLength4,*TrackLength5;
int Mus_Length;
int Mus_Repeat;
int monsterID;
int gameState;
int pos,oldpos;
char battleEnd;
int *move_in_map;
/**
 * Par groupe de 4 int
 * 1 : position sur la map
 * 2 : type d'évènement
 * 3 et 4 : pour des paramètres
 */
int *event_in_map;
int nb_events;
/**
 * Direction en cours de déplacement.
 * voir les constantes pour savoir quelle direction utilise quelle valeur
 */
int direction;

/**
 * Pattern du sprite à afficher lors du déplacement
 */
int SPRPATTERN;
char pattern;
char meter;
int monster;
char positive_pattern;

/**
 * Variables sur les monstres possibles dans une zone
 */

int *monsters_in_map;
char nb_monsters;
/**
 * Index du background à afficher en combat.
 * Utilisation d'une variable séparée pour indiquer le background pour la map.
 * Cela permet de séparer le background d'une map de celui d'un event spécifique.
 */
char battle_bg;
char map_battle_bg;

/**
 * Indicateur de la musique actuellement jouée.
 * 0 indique aucune musique.
 */
char currentMusic;

/**
 * Special event variables
 */
char first_time_map4;