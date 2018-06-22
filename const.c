/* Overlay values */
#define OVL_INIT 1
#define OVL_RPG 2
#define OVL_BATTLE 3

/* Coding */
#define NULL 0
/* Set to 1 for debug view, set to 0 for normal view */
#define DEBUG 1

/* attribute types */
#define STAT_TYPE unsigned char
#define HP_TYPE int
#define MP_TYPE unsigned int
#define RESIST_TYPE unsigned int
#define MAX_HPMP_TYPE unsigned int

/* game values */
#define LIFEMAX 500
#define MPMAX 30
#define DEX 40
#define ATK 50
#define DEF 50
#define COUNTMAX 6

/* graph values */
#define TITLEPCX "title.pcx"
#define SPRITE "sprite1.pcx"
#define PERSO1PCX "perso1.pcx"
#define PERSO2PCX "perso2.pcx"
#define TILES "tiles.pcx"
#define SCREEN "screen.pcx"
#define NUMBERS "numbers16x16.pcx"
#define FIRE_MAGIC "fireball.pcx"
#define ICE_MAGIC "ice.pcx"
#define BAR "actionbar.pcx"
#define BATTLE_BG_PCX "battle_bg.pcx"
#define P1PAL 0
#define P2PAL 1
#define NUMPAL 2
#define SPRITEPAL 3
#define FIRE_MAGICPAL 4
#define ICE_MAGICPAL 5
#define BARPAL 8
#define TILE_PAL 12
#define MAGICSPR 30
#define Ram_tiles 0X1200
#define FIREMAGICPTR 0x7000
#define ICEMAGICPTR 0x7100
#define ACTIONBARPTR 0x6800
#define PLAYER1PTR 0x5200
#define PLAYER2PTR 0x6500
#define NUMBERPTR 0x5500
#define BARBASESPR 20
#define FIGHT_CHAR_SPR 50

/* Magic defines*/
#define FIRE_MASK 0xf
#define FIRE_WEAK 0x1
#define FIRE_STRONG 0x2
#define FIRE_NULL 0x4
#define FIRE_ABSORB 0x8
#define ICE_MASK 0xf0
#define ICE_WEAK 0x10
#define ICE_STRONG 0x20
#define ICE_NULL 0x40
#define ICE_ABSORB 0x80
#define AIR_MASK 0xf00
#define AIR_WEAK 0x100
#define AIR_STRONG 0x200
#define AIR_NULL 0x400
#define AIR_ABSORB 0x800
#define EARTH_MASK 0xf000
#define EARTH_WEAK 0x1000
#define EARTH_STRONG 0x2000
#define EARTH_NULL 0x4000
#define EARTH_ABSORB 0x8000

#define MOVE_COL01 0x0001
#define MOVE_COL02 0x0002
#define MOVE_COL03 0x0004
#define MOVE_COL04 0x0008
#define MOVE_COL05 0x0010
#define MOVE_COL06 0x0020
#define MOVE_COL07 0x0040
#define MOVE_COL08 0x0080
#define MOVE_COL09 0x0100
#define MOVE_COL10 0x0200
#define MOVE_COL11 0x0400
#define MOVE_COL12 0x0800
#define MOVE_COL13 0x1000
#define MOVE_COL14 0x2000
#define MOVE_COL15 0x4000
#define MOVE_COL16 0x8000

#define MOVE_LINE 0xffff

#define TELEPORT_EVT 1
#define BATTLE_EVT 2
#define MAP_SPECIAL_EVT 3

#define DIR_LEFT 1
#define DIR_RIGHT 2
#define DIR_UP 4
#define DIR_DOWN 8

/**
 * Pattern à afficher en fonction de la direction
 */
#define FR_Face PLAYER1PTR
#define BK_Face FR_Face+0xC0
#define RGT_Face BK_Face+0xC0
#define LFT_Face RGT_Face+0xC0

/**
 * Définition des id de tile
 */
const unsigned char tiles_pal_ref[250];

#define T_Hill 107

#define T_WaterSky 108

#define T_PlainPuddle 85
#define T_PlainTrunk 101

#define T_Plain 112

#define T_Forest 114

#define T_Fence 115

#define T_Pave 64

#define T_HouseDoorOut 82

#define T_HouseWindowDL 81
#define T_HouseWindowDR 121
#define T_HouseWindowM 120
#define T_HouseWindowD 122

#define T_HouseBlankM 34
#define T_HouseBlankD 50
#define T_HouseBlankDR 83
#define T_HouseBlankL 123
#define T_HouseBlankR 124

#define T_HouseRoofL 65

#define T_HouseRoofM 66

#define T_HouseRoofR 67

/**
 * Intérieur de la maison
 */
#define T_HouseIn 118
#define T_HouseInWallUL 23
#define T_HouseInWallU 24
#define T_HouseInWallUR 28
#define T_HouseInWallL 39
#define T_HouseInWallR 44
#define T_HouseInWallDL 71
#define T_HouseInWallD 72
#define T_HouseInWallDR 76

#define T_HouseInWall 40

#define T_HouseDoorIn 74
#define T_HouseInWindowFront 60
#define T_HouseInWindowBack 42

#define T_HouseInClock 91
#define T_HouseInWallFloor 92
#define T_HouseInBed 56

/**
 * Chemin pavé avec herbe
 */
#define T_GrassPaveUL 13
#define T_GrassPaveU 14
#define T_GrassPaveUR 15
#define T_GrassPaveL 61
#define T_GrassPaveR 63
#define T_GrassPaveDL 30
#define T_GrassPaveD 46
#define T_GrassPaveDR 62
#define T_GrassPaveLUL 29
#define T_GrassPaveRUR 31
#define T_GrassPaveLDL 45
#define T_GrassPaveRDR 47


#define T_FenceUL 6
#define T_FenceL 22
#define T_FenceDL 38
#define T_FenceUR 5
#define T_FenceR 21
#define T_FenceDR 37

/**
 * Index des background de combat
 */

#define PLAIN_BG 0
#define FOREST_BG 1
#define PAVE_CITY_BG 2

/**
 * Autres constantes
 */

const char* c_magicname[10] =
{"Fire",
 "Ice",
 "Bolt",
 "Water",
 "Comet",
 "Burst",
 "Bio",
 "Flare",
 "Meteo",
 "Ultima"};

const int c_magicelement[10] =
{0xf,
 0xf0,
 0xf00,
 0xf0,
 0xf000,
 0xf00,
 0xf000,
 0xf,
 0,
 0};

const char* c_magicdesc[10] =
{"Burn enemy with fire",
 "Freeze enemy with ice",
 "Cast bolt on enemy",
 "Flood enemy with water",
 "Throw a small comet on enemy",
 "Cast a magic bomb on enemy",
 "Poison enemy",
 "Strongest magic fire attack",
 "Ancient spell",
 "Ultimate magic spell"};

const char c_magicmp[10] =
{3,4,5,7,9,10,15,20,30,50};

const char* c_item[11] =
{"Potion",
 "HyperPotion",
 "Ether",
 "HyperEther",
 "Antidote",
 "Elixir",
 "Heal",
 "",
 "",
 "",
 ""};

const char* c_itemdesc[11] =
{"Restore 50 HP",
 "Restore 250 HP",
 "Restore 10 MP",
 "Restore 30 MP",
 "Cure poison",
 "Fully restore HP/MP",
 "Heal status aliment",
 "",
 "",
 "",
 ""};
 
 /**
  * Fonction de copie de tableau.
  * Prévu pour des tableaux de int.
  * Fait une copie de 0 à length.
  * Aucune vérification sur la taille des tableaux
  *
  * source est le tableau d'origine
  * target est le tableau cible
  * length la taille à copier
  */
 /*array_copy(source, target, length)
 unsigned int *source, *target;
 unsigned char length;
 {
	 unsigned char i;
	 for (i=0; i<length; i++) {
		 target[i] = source[i];
	 }
 }*/
 
#define continue_indicator "<.>"
#define end_indicator "<X>"
#define empty_indicator "   "
#define TEXT_BUTTON_MASK (JOY_STRT | JOY_A | JOY_B)