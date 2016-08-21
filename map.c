/*#define Ram_tiles 0X1200*/


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

/*const int map_in_1[224] = 
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
  */
const char tiles_map1[224] = 
 {Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,
     Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Forest,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Forest, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,
      Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill};

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

 /*print_map(map_in_1);*/
 set_map_data(tiles_map1, 16,14);
 load_map(0,0, 0,0, 16,14);
 
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

const char tiles_map2[224] = 
 {Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,
     Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Forest,Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill};

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

/*print_map(map_in_2);*/
set_map_data(tiles_map2, 16,14);
 load_map(0,0, 0,0, 16,14);

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

const char tiles_map3[224] = 
 {Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
     Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain,
      Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Plain, Tile_Hill,
  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_FenceUR,  Tile_GrassPaveUL,
     Tile_GrassPaveUR,  Tile_FenceUL,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill,  Tile_Hill};
  
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

  set_map_data(tiles_map3, 16,14);
  load_map(0,0, 0,0, 16,14);

move_in_map = move_in_3;
/*array_copy(move_in_3, move_in_map, 14);*/

event_in_map = event_in_3;
 nb_events = 16;
 
 monsters_in_map = no_monster_in_map;
 nb_monsters = 0;

}

/************************************/

const char tiles_map4[224] = 
 {Tile_FenceUL,  Tile_Fence, Tile_Fence, Tile_Fence, Tile_Fence, Tile_Fence, Tile_Fence, Tile_GrassPaveL,
     Tile_GrassPaveR, Tile_Fence, Tile_Fence, Tile_Fence, Tile_Fence, Tile_Fence, Tile_Fence, Tile_FenceUR,
  Tile_FenceL,  Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave,
      Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_FenceR,
  Tile_FenceL,  Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave,
      Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_FenceR,
  Tile_FenceL,  Tile_Pave, Tile_Pave, Tile_HouseRoofL, Tile_HouseRoofM, Tile_HouseRoofR, Tile_Pave, Tile_Pave,
      Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_FenceR,
  Tile_FenceL,  Tile_Pave, Tile_Pave, Tile_HouseBlankM, Tile_HouseWindowM, Tile_HouseBlankM, Tile_Pave, Tile_Pave,
      Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_FenceR,
  Tile_FenceL,  Tile_Pave, Tile_Pave, Tile_HouseWindowDL, Tile_HouseDoorOut, Tile_HouseWindowDR, Tile_Pave, Tile_Pave,
      Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_FenceR,
  Tile_FenceL,  Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave,
      Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_FenceR,
  Tile_FenceL,  Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave,
      Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_FenceR,
  Tile_FenceL,  Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave,
      Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_FenceR,
  Tile_FenceL,  Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave,
      Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_FenceR,
  Tile_FenceL,  Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave,
      Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_FenceR,
  Tile_FenceL,  Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave,
      Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_FenceR,
  Tile_FenceL,  Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave,
      Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_FenceR,
  Tile_FenceDL,  Tile_Fence,  Tile_Fence,  Tile_Fence,  Tile_Fence,  Tile_Fence,  Tile_Fence,  Tile_Fence,
      Tile_Fence,  Tile_Fence,  Tile_Fence,  Tile_Fence,  Tile_Fence,  Tile_Fence,  Tile_Fence,  Tile_FenceDR};

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
/*print_map(map_in_4);*/
  set_map_data(tiles_map4, 16,14);
 load_map(0,0, 0,0, 16,14);

move_in_map = move_in_4;

event_in_map = event_in_4;
 nb_events = 3;
 
 monsters_in_map = no_monster_in_map;
 nb_monsters = 0;

}

/**********************************/
/*     First House Inside test    */
/**********************************/

const char tiles_house1[224] = 
 {Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave,
     Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave,
  Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave,
      Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave,
  Tile_Pave, Tile_Pave, Tile_HouseInWallUL, Tile_HouseInWallU, Tile_HouseInWallU, Tile_HouseInWallU, Tile_HouseInWallU, Tile_HouseInWallU,
     Tile_HouseInWallU, Tile_HouseInWallU, Tile_HouseInWallU, Tile_HouseInWallU, Tile_HouseInWallU, Tile_HouseInWallUR, Tile_Pave, Tile_Pave,
  Tile_Pave, Tile_Pave, Tile_HouseInWallL, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn,
     Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseInWallR, Tile_Pave, Tile_Pave,
  Tile_Pave, Tile_Pave, Tile_HouseInWallL, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn,
    Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseInWallR, Tile_Pave, Tile_Pave,
  Tile_Pave, Tile_Pave, Tile_HouseInWallL, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn,
    Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseInWallR, Tile_Pave, Tile_Pave,
  Tile_Pave, Tile_Pave, Tile_HouseInWallL, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn,
    Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseInWallR, Tile_Pave, Tile_Pave,
  Tile_Pave, Tile_Pave, Tile_HouseInWallL, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn,
    Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseInWallR, Tile_Pave, Tile_Pave,
  Tile_Pave, Tile_Pave, Tile_HouseInWallL, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn,
    Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseInWallR, Tile_Pave, Tile_Pave,
  Tile_Pave, Tile_Pave, Tile_HouseInWallL, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn,
    Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseInWallR, Tile_Pave, Tile_Pave,
  Tile_Pave, Tile_Pave, Tile_HouseInWallL, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn,
    Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseIn, Tile_HouseInWallR, Tile_Pave, Tile_Pave,
  Tile_Pave, Tile_Pave, Tile_HouseInWallDL, Tile_HouseInWallD, Tile_HouseInWallD, Tile_HouseWindowD, Tile_HouseInWallD, Tile_HouseInWallD,
    Tile_HouseDoorIn, Tile_HouseInWallD, Tile_HouseWindowD, Tile_HouseInWallD, Tile_HouseInWallD, Tile_HouseInWallDR, Tile_Pave, Tile_Pave,
  Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave,
      Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave,
  Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave,
      Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave, Tile_Pave};
  
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

/*print_map(map_in_house1);*/
  set_map_data(tiles_house1, 16,14);
  load_map(0,0, 0,0, 16,14);

move_in_map = move_in_house1;
/*array_copy(move_in_house1, move_in_map, 14);*/

event_in_map = event_in_house1;
 nb_events = 1;
 
 monsters_in_map = no_monster_in_map;
 nb_monsters = 0;

}
