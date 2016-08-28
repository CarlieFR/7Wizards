#define OVL_INIT 1
#define OVL_RPG 2
#define OVL_BATTLE 3

#define LIFEMAX 500
#define MPMAX 30
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
#define DEX 40
#define ATK 50
#define DEF 50
#define COUNTMAX 6
#define MAGICSPR 30
#define Ram_tiles 0X1200
#define FIREMAGICPTR 0x7000
#define ICEMAGICPTR 0x7100
#define ACTIONBARPTR 0x6800
#define PLAYER1PTR 0x5200
#define PLAYER2PTR 0x6500
#define NUMBERPTR 0x5500
#define BARBASESPR 20

/* Magic defines*/
#define FIRE_WEAK 0x1
#define FIRE_STRONG 0x2
#define FIRE_NULL 0x4
#define FIRE_ABSORB 0x8
#define ICE_WEAK 0x10
#define ICE_STRONG 0x20
#define ICE_NULL 0x40
#define ICE_ABSORB 0x80
#define AIR_WEAK 0x100
#define AIR_STRONG 0x200
#define AIR_NULL 0x400
#define AIR_ABSORB 0x800
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

#define DIR_LEFT 1
#define DIR_RIGHT 2
#define DIR_UP 4
#define DIR_DOWN 8

/**
 * Pattern à afficher en fonction de la direction
 */
#define FR_Face 0x5200
#define BK_Face 0x52C0
#define RGT_Face 0x5380
#define LFT_Face 0x5440

/**
 * Définition des id de tile
 */
const char tiles_pal_ref[250];

#define Hill 0X12b6
#define Tile_Hill 107

#define Tile_WaterSky 108

#define Tile_PlainPuddle 85
#define Tile_PlainTrunk 101

#define Plain 0X122a
#define Tile_Plain 112

#define Forest 0X12e4
#define Tile_Forest 114

#define Fence 0X12e6
#define Tile_Fence 115

#define Pave 0X1220
#define Tile_Pave 64

#define HouseDoor11 0x1264
#define Tile_HouseDoorOut 82

#define HouseWindow 0x11e8
#define Tile_HouseWindowDL 81
#define Tile_HouseWindowDR 121
#define Tile_HouseWindowM 120
#define Tile_HouseWindowD 122

#define HouseBlank11 0x11a4
#define Tile_HouseBlankM 34
#define Tile_HouseBlankD 50
#define Tile_HouseBlankDR 83
#define Tile_HouseBlankL 123
#define Tile_HouseBlankR 124

#define HouseRoofL11 0x1222
#define Tile_HouseRoofL 65

#define HouseRoofM11 0x1224
#define Tile_HouseRoofM 66

#define HouseRoofR11 0x1226
#define Tile_HouseRoofR 67

#define HouseIn 0x12ec


#define HouseInWallUL 0x116e
#define HouseInWallU 0x1170
#define HouseInWallUR 0x1178
#define HouseInWallL 0x11ae
#define HouseInWallR 0x11b8
#define HouseInWallDL 0x122e
#define HouseInWallD 0x1230
#define HouseInWallDR 0x1238
/**
 * Intérieur de la maison
 */
#define Tile_HouseIn 118
#define Tile_HouseInWallUL 23
#define Tile_HouseInWallU 24
#define Tile_HouseInWallUR 28
#define Tile_HouseInWallL 39
#define Tile_HouseInWallR 44
#define Tile_HouseInWallDL 71
#define Tile_HouseInWallD 72
#define Tile_HouseInWallDR 76

#define Tile_HouseInWall 40

#define Tile_HouseDoorIn 74
#define Tile_HouseInWindowFront 60
#define Tile_HouseInWindowBack 42

#define Tile_HouseInClock 91
#define Tile_HouseInWallFloor 92
#define Tile_HouseInBed 56

#define GrassPave11 0x113a
#define GrassPave3111 0x113e
#define GrassPave1411 0x11fa
#define GrassPave3411 0x11fe

/**
 * Chemin pavé avec herbe
 */
#define Tile_GrassPaveUL 13
#define Tile_GrassPaveU 14
#define Tile_GrassPaveUR 15
#define Tile_GrassPaveL 61
#define Tile_GrassPaveR 63
#define Tile_GrassPaveDL 30
#define Tile_GrassPaveD 46
#define Tile_GrassPaveDR 62
#define Tile_GrassPaveLUL 29
#define Tile_GrassPaveRUR 31
#define Tile_GrassPaveLDL 45
#define Tile_GrassPaveRDR 47


#define FenceUL 0x112c
#define Tile_FenceUL 6
#define Tile_FenceL 22
#define Tile_FenceDL 38
#define Tile_FenceUR 5
#define Tile_FenceR 21
#define Tile_FenceDR 37

/**
 * Index des background de combat
 */

#define PLAIN_BG 0
#define FOREST_BG 1
#define PAVE_CITY_BG 2

/**
 * Autres constantes
 */

const char* magicname[10] =
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

const int magicelement[10] =
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

const char* magicdesc[10] =
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

const char magicmp[10] =
{3,4,5,7,9,10,15,20,30,50};

const char* item[11] =
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

const char* itemdesc[11] =
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
 array_copy(source, target, length)
 int *source, *target;
 char length;
 {
	 char i;
	 for (i=0; i<length; i++) {
		 target[i] = source[i];
	 }
 }
 