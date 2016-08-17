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
#define P1PAL 0
#define P2PAL 1
#define NUMPAL 2
#define SPRITEPAL 3
#define FIRE_MAGICPAL 4
#define ICE_MAGICPAL 5
#define BARPAL 8
#define DEX 40
#define ATK 50
#define DEF 50
#define COUNTMAX 6
#define MAGICSPR 30
#define FIREMAGICPTR 0x7000
#define ICEMAGICPTR 0x7100
#define ACTIONBARPTR 0x4000
#define PLAYER1PTR 0x5000
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
#define FR_Face 0x5000
#define BK_Face 0x50C0
#define RGT_Face 0x5180
#define LFT_Face 0x5240

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
 