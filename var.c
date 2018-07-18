char g_nameP1[7],g_nameP2[7],g_nameP3[7],g_nameP4[7]; /* name Player 1-4 */
STAT_TYPE g_dexP[4],g_atkP[4],g_defP[4];
unsigned int g_expP[4]; /* carac Player 1-4*/
char g_activePlayer[4]; /* flag to indicate if the player is available or not */
unsigned int g_spriteX;
unsigned int g_spriteY;
int g_hp[4];
int g_mp[4];
unsigned int g_maxHP[4];
unsigned int g_maxMP[4];
unsigned int g_battleX[5];
unsigned int g_battleY[5];
unsigned char g_itemnb[11]; /* item number*/
/*char play[5],round[5];*/
unsigned int g_roundCount[5]; /* round counter to indicate who is ready to fight*/
char g_firstTime; /* move info */

unsigned int g_monsterID;
unsigned int g_gameState;
unsigned int g_pos;
unsigned int g_oldpos;
unsigned char g_battleEnd;
unsigned int *g_move_in_map;
/**
 * Par groupe de 4 int
 * 1 : position sur la map
 * 2 : type d'évènement
 * 3 et 4 : pour des paramètres
 */
unsigned int *g_event_in_map;
unsigned int g_nb_events;
/**
 * Direction en cours de déplacement.
 * voir les constantes pour savoir quelle direction utilise quelle valeur
 */
int g_direction;

/**
 * Pattern du sprite à afficher lors du déplacement
 */
unsigned int g_SPRPATTERN;
unsigned char g_pattern;
unsigned char g_meter;
unsigned int g_monster;
char g_positive_pattern;

/**
 * Variables sur les monstres possibles dans une zone
 */

unsigned int *g_monsters_in_map;
unsigned char g_nb_monsters;
/**
 * Index du background à afficher en combat.
 * Utilisation d'une variable séparée pour indiquer le background pour la map.
 * Cela permet de séparer le background d'une map de celui d'un event spécifique.
 */
unsigned int g_battle_bg;
unsigned int g_map_battle_bg;

/**
 * Indicateur de la musique actuellement jouée.
 * 0 indique aucune musique.
 */
unsigned char g_currentMusic;

/**
 * Special event variables
 */
char g_first_time_map4;