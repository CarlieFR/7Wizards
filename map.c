/*#define Ram_tiles 0X1200*/

#define Hill 0X12b6
#define Hill21 0X12b7
#define Hill12 0X12d6
#define Hill22 0X12d7
#define Plain 0X122a
#define Plain21 0X122b
#define Plain12 0X124a
#define Plain22 0X124b
#define Forest 0X12e4
#define Forest21 0X12e5
#define Forest12 0X1304
#define Forest22 0X1305
#define Fence 0X12e6
#define Fence21 0X12e7
#define Fence12 0X1306
#define Fence22 0X1307
#define Pave 0X1220
#define Pave21 0X1221
#define Pave12 0X1240
#define Pave22 0X1241
#define HouseDoor11 0x1264
#define HouseDoor21 0x1265
#define HouseDoor12 0x1284
#define HouseDoor22 0x1285
#define HouseWindow 0x11e8
#define HouseWindow21 0x11e9
#define HouseWindow12 0x1208
#define HouseWindow22 0x1209
#define HouseBlank11 0x11a4
#define HouseBlank21 0x11a5
#define HouseBlank12 0x11c4
#define HouseBlank22 0x11c5
#define HouseRoofL11 0x1222
#define HouseRoofL21 0x1223
#define HouseRoofL12 0x1242
#define HouseRoofL22 0x1243
#define HouseRoofM11 0x1224
#define HouseRoofM21 0x1225
#define HouseRoofM12 0x1244
#define HouseRoofM22 0x1245
#define HouseRoofR11 0x1226
#define HouseRoofR21 0x1227
#define HouseRoofR12 0x1246
#define HouseRoofR22 0x1247
#define HouseIn 0x12ec
#define HouseIn21 0x12ed
#define HouseIn12 0x130c
#define HouseIn22 0x130d
#define HouseInWallUL 0x116e
#define HouseInWallUL21 0x116f
#define HouseInWallUL12 0x118e
#define HouseInWallUL22 0x118f
#define HouseInWallU 0x1170
#define HouseInWallU21 0x1171
#define HouseInWallU12 0x1190
#define HouseInWallU22 0x1191
#define HouseInWallUR 0x1178
#define HouseInWallUR21 0x1179
#define HouseInWallUR12 0x1198
#define HouseInWallUR22 0x1199
#define HouseInWallL 0x11ae
#define HouseInWallL21 0x11af
#define HouseInWallL12 0x11ce
#define HouseInWallL22 0x11cf
#define HouseInWallR 0x11b8
#define HouseInWallR21 0x11b9
#define HouseInWallR12 0x11d8
#define HouseInWallR22 0x11d9
#define HouseInWallDL 0x122e
#define HouseInWallDL21 0x122f
#define HouseInWallDL12 0x124e
#define HouseInWallDL22 0x124f
#define HouseInWallD 0x1230
#define HouseInWallD21 0x1231
#define HouseInWallD12 0x1250
#define HouseInWallD22 0x1251
#define HouseInWallDR 0x1238
#define HouseInWallDR21 0x1239
#define HouseInWallDR12 0x1258
#define HouseInWallDR22 0x1259
#define GrassPave11 0x113a
#define GrassPave21 0x113b
#define GrassPave12 0x115a
#define GrassPave22 0x115b
#define GrassPave3111 0x113e
#define GrassPave3121 0x113f
#define GrassPave3112 0x115e
#define GrassPave3122 0x115f
#define GrassPave1411 0x11fa
#define GrassPave1421 0x11fb
#define GrassPave1412 0x121a
#define GrassPave1422 0x121b
#define GrassPave3411 0x11fe
#define GrassPave3421 0x11ff
#define GrassPave3412 0x121e
#define GrassPave3422 0x121f
#define FenceUR 0x112a
#define FenceUR21 0x112b
#define FenceUR12 0x114a
#define FenceUR22 0x114b
#define FenceUL 0x112c
#define FenceUL21 0x112d
#define FenceUL12 0x114c
#define FenceUL22 0x114d

#define line_shift 0x0020

print_map(map)
int* map;
{
	char line, row;
	
	for(line=0; line<14; line++) {
		for(row=0; row<16; row++) {
			put_raw(map[16*line+row], 2*row, 2*line);
			put_raw(map[16*line+row]+1, 2*row+1, 2*line);
			put_raw(map[16*line+row]+line_shift, 2*row, 2*line+1);
			put_raw(map[16*line+row]+1+line_shift, 2*row+1, 2*line+1);
		}
	}
}

const int map_in_1[224] = 
 {Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Forest,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Forest, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill};

const int move_in_1[14] = 
 {MOVE_LINE,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_LINE};
  
const int event_in_1[8]={
	4+15*256, TELEPORT_EVT, 2, 4+0*256,
	8+5*256, BATTLE_EVT, 0, 0};
  
int *no_monster_in_map;
 
map1()
{

/*vsync();*/
cls();

/*load_sprites(Ram_tiles,tilesgfx,16);
set_bgpal(1,tilespal);*/

 print_map(map_in_1);
 
 move_in_map = move_in_1;
 
 event_in_map = event_in_1;
 nb_events = 2;
 
 monsters_in_map = no_monster_in_map;
 nb_monsters = 0;
 
 music1Init();
 /*array_copy(move_in_1, move_in_map, 14);*/
 /*for (i=0; i<14; i++) {
	move_in_map[i] = move_in_1[i];
 }*/
 
}
/***********************************************/

const int map_in_2[224] = 
 {Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Forest,Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill};

const int move_in_2[14] = 
 {MOVE_LINE,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16};
  
const int event_in_2[60]={
	4+0*256, TELEPORT_EVT, 1, 4+15*256,
	13+1*256, TELEPORT_EVT, 3, 0+1*256,
  13+2*256, TELEPORT_EVT, 3, 0+2*256,
  13+3*256, TELEPORT_EVT, 3, 0+3*256,
  13+4*256, TELEPORT_EVT, 3, 0+4*256,
  13+5*256, TELEPORT_EVT, 3, 0+5*256,
  13+6*256, TELEPORT_EVT, 3, 0+6*256,
  13+7*256, TELEPORT_EVT, 3, 0+7*256,
  13+8*256, TELEPORT_EVT, 3, 0+8*256,
  13+9*256, TELEPORT_EVT, 3, 0+9*256,
  13+10*256, TELEPORT_EVT, 3, 0+10*256,
  13+11*256, TELEPORT_EVT, 3, 0+11*256,
  13+12*256, TELEPORT_EVT, 3, 0+12*256,
  13+13*256, TELEPORT_EVT, 3, 0+13*256,
  13+14*256, TELEPORT_EVT, 3, 0+14*256};
  
const int monsters_in_map2[1] = { 1 };
  
map2()
{

/*vsync();*/
cls();

print_map(map_in_2);

move_in_map = move_in_2;

event_in_map = event_in_2;
 nb_events = 15;
 
 monsters_in_map = monsters_in_map2;
 nb_monsters = 1;

/*load_sprites(Ram_tiles,tilesgfx,1);
set_bgpal(1,tilespal);
*/


}
/***********************************************/

const int map_in_3[224] = 
 {Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Plain, Hill,
  Hill,  Hill,  Hill,  Hill,  Hill,  Hill,  FenceUR,  GrassPave11,  GrassPave3111,  FenceUL,  Hill,  Hill,  Hill,  Hill,  Hill,  Hill};
  
const int move_in_3[14] = 
 {MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  0xf + MOVE_COL05 + MOVE_COL06 + MOVE_COL07 + MOVE_COL10 + MOVE_COL11 + MOVE_COL12 + 0xf000};

const int event_in_3[64]={
	13+7*256, TELEPORT_EVT, 4, 0+7*256,
  13+8*256, TELEPORT_EVT, 4, 0+8*256,
	0+1*256, TELEPORT_EVT, 2, 13+1*256,
  0+2*256, TELEPORT_EVT, 2, 13+2*256,
  0+3*256, TELEPORT_EVT, 2, 13+3*256,
  0+4*256, TELEPORT_EVT, 2, 13+4*256,
  0+5*256, TELEPORT_EVT, 2, 13+5*256,
  0+6*256, TELEPORT_EVT, 2, 13+6*256,
  0+7*256, TELEPORT_EVT, 2, 13+7*256,
  0+8*256, TELEPORT_EVT, 2, 13+8*256,
  0+9*256, TELEPORT_EVT, 2, 13+9*256,
  0+10*256, TELEPORT_EVT, 2, 13+10*256,
  0+11*256, TELEPORT_EVT, 2, 13+11*256,
  0+12*256, TELEPORT_EVT, 2, 13+12*256,
  0+13*256, TELEPORT_EVT, 2, 13+13*256,
  0+14*256, TELEPORT_EVT, 2, 13+14*256};
  
map3()
{

/*vsync();*/
cls();

/*load_sprites(Ram_tiles,tilesgfx,1);
set_bgpal(1,tilespal);*/

print_map(map_in_3);

move_in_map = move_in_3;
/*array_copy(move_in_3, move_in_map, 14);*/

event_in_map = event_in_3;
 nb_events = 16;
 
 monsters_in_map = no_monster_in_map;
 nb_monsters = 0;

}

/************************************/

const int map_in_4[224] = 
 {Fence,  Fence, Fence, Fence, Fence, Fence, Fence, GrassPave1411, GrassPave3411, Fence, Fence, Fence, Fence, Fence, Fence, Fence,
  Fence,  Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Fence,
  Fence,  Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Fence,
  Fence,  Pave, Pave, HouseRoofL11, HouseRoofM11, HouseRoofR11, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Fence,
  Fence,  Pave, Pave, HouseBlank11, HouseWindow, HouseBlank11, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Fence,
  Fence,  Pave, Pave, HouseWindow, HouseDoor11, HouseWindow, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Fence,
  Fence,  Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Fence,
  Fence,  Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Fence,
  Fence,  Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Fence,
  Fence,  Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Fence,
  Fence,  Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Fence,
  Fence,  Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Fence,
  Fence,  Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Fence,
  Fence,  Fence,  Fence,  Fence,  Fence,  Fence,  Fence,  Fence,  Fence,  Fence,  Fence,  Fence,  Fence,  Fence,  Fence,  Fence};

const int move_in_4[14] = 
 {0xf + MOVE_COL05 + MOVE_COL06 + MOVE_COL07 + MOVE_COL10 + MOVE_COL11 + MOVE_COL12 + 0xf000,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL04 + MOVE_COL05 + MOVE_COL06 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL04 + MOVE_COL05 + MOVE_COL06 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL04 + MOVE_COL06 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL16,
  MOVE_LINE};
  
const int event_in_4[12]={
	0+7*256, TELEPORT_EVT, 3, 13+7*256,
  0+8*256, TELEPORT_EVT, 3, 13+8*256,
  5+4*256, TELEPORT_EVT, 20000, 11+8*256};

map4()
{
  
  /*vsync();*/
cls();
print_map(map_in_4);

move_in_map = move_in_4;

event_in_map = event_in_4;
 nb_events = 3;
 
 monsters_in_map = no_monster_in_map;
 nb_monsters = 0;

}

/**********************************/
/*     First House Inside test    */
/**********************************/

const int map_in_house1[224] = 
 {Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave,
  Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave,
  Pave, Pave, HouseInWallUL, HouseInWallU, HouseInWallU, HouseInWallU, HouseInWallU, HouseInWallU,
     HouseInWallU, HouseInWallU, HouseInWallU, HouseInWallU, HouseInWallU, HouseInWallUR, Pave, Pave,
  Pave, Pave, HouseInWallL, HouseIn, HouseIn, HouseIn, HouseIn, HouseIn,
     HouseIn, HouseIn, HouseIn, HouseIn, HouseIn, HouseInWallR, Pave, Pave,
  Pave, Pave, HouseInWallL, HouseIn, HouseIn, HouseIn, HouseIn, HouseIn,
    HouseIn, HouseIn, HouseIn, HouseIn, HouseIn, HouseInWallR, Pave, Pave,
  Pave, Pave, HouseInWallL, HouseIn, HouseIn, HouseIn, HouseIn, HouseIn,
    HouseIn, HouseIn, HouseIn, HouseIn, HouseIn, HouseInWallR, Pave, Pave,
  Pave, Pave, HouseInWallL, HouseIn, HouseIn, HouseIn, HouseIn, HouseIn,
    HouseIn, HouseIn, HouseIn, HouseIn, HouseIn, HouseInWallR, Pave, Pave,
  Pave, Pave, HouseInWallL, HouseIn, HouseIn, HouseIn, HouseIn, HouseIn,
    HouseIn, HouseIn, HouseIn, HouseIn, HouseIn, HouseInWallR, Pave, Pave,
  Pave, Pave, HouseInWallL, HouseIn, HouseIn, HouseIn, HouseIn, HouseIn,
    HouseIn, HouseIn, HouseIn, HouseIn, HouseIn, HouseInWallR, Pave, Pave,
  Pave, Pave, HouseInWallL, HouseIn, HouseIn, HouseIn, HouseIn, HouseIn,
    HouseIn, HouseIn, HouseIn, HouseIn, HouseIn, HouseInWallR, Pave, Pave,
  Pave, Pave, HouseInWallL, HouseIn, HouseIn, HouseIn, HouseIn, HouseIn,
    HouseIn, HouseIn, HouseIn, HouseIn, HouseIn, HouseInWallR, Pave, Pave,
  Pave, Pave, HouseInWallDL, HouseInWallD, HouseInWallD, HouseWindow, HouseInWallD, HouseInWallD,
    HouseDoor11, HouseInWallD, HouseWindow, HouseInWallD, HouseInWallD, HouseInWallDR, Pave, Pave,
  Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave,
  Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave, Pave};
  
const int move_in_house1[14] = 
 {MOVE_LINE,
  MOVE_LINE,
  MOVE_LINE,
  MOVE_COL01 + MOVE_COL02 + MOVE_COL03 + MOVE_COL14 + MOVE_COL15 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL02 + MOVE_COL03 + MOVE_COL14 + MOVE_COL15 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL02 + MOVE_COL03 + MOVE_COL14 + MOVE_COL15 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL02 + MOVE_COL03 + MOVE_COL14 + MOVE_COL15 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL02 + MOVE_COL03 + MOVE_COL14 + MOVE_COL15 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL02 + MOVE_COL03 + MOVE_COL14 + MOVE_COL15 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL02 + MOVE_COL03 + MOVE_COL14 + MOVE_COL15 + MOVE_COL16,
  MOVE_COL01 + MOVE_COL02 + MOVE_COL03 + MOVE_COL14 + MOVE_COL15 + MOVE_COL16,
  MOVE_LINE - MOVE_COL09,
  MOVE_LINE,
  MOVE_LINE};
  
const int event_in_house1[4]={
	11+8*256, TELEPORT_EVT, 4, 5+4*256};
  
housemap1()
{
/*char i,j;*/

print_map(map_in_house1);

move_in_map = move_in_house1;
/*array_copy(move_in_house1, move_in_map, 14);*/

event_in_map = event_in_house1;
 nb_events = 1;
 
 monsters_in_map = no_monster_in_map;
 nb_monsters = 0;

}
