
MAX(x,y)
int x,y;
{
	return x>y?x:y;
}

/***************************************/
/*   test function for left movement   */
/***************************************/
moveltest()
{
int column;
char row;

  if (spriteX <= 0) {
    /* Si on est au bord à gauche, on évite de sortir */
    return;
  }

  if (spriteX & 0xf) {
	  /* En milieu de case, on passe */
	  go_left();
  } else {
	 /* En bout de case
	  * On calcule la colonne actuelle (pour mask) */
	 column = 1 << ((spriteX>>4)-1);
	 /*column = 1;
	 for (colNumber =0 ; colNumber < spriteX/16 -1; colNumber++) {
		 column = column *2;
	 }*/
	 /* On fait un décalage pour tester la colonne à gauche. */
	 /*column = column >> 1;*/
	 /* on calcul la ligne courante, à partir de la position en Y divisé par 16 */
	 row = spriteY>>4;
	 /* On test si on est aligné verticalement */
     if (spriteY & 0xf) {
		 /* Non aligné, il faut vérifier les cases au dessus/au dessous */
		 if (((move_in_map[row] & column ) == 0) &&
			 ((move_in_map[row+1] & column ) == 0)) {
				 /* 1 : déplacement OK */
				 go_left();
				 return;
		 } else {
			 if (((move_in_map[row] & column ) != 0) &&
				((move_in_map[row+1] & column ) == 0)) {
					/* 3 : Décalage vers le bas */
					go_down();
					return;
			 } else {
				 if (((move_in_map[row] & column ) == 0) &&
					((move_in_map[row+1] & column ) != 0)) {
						/* 2 : Décalage vers le haut */
						go_up();
						return;
				}
			 }
		 }
	} else {
		/* Aligné, on vérifie juste la case à gauche */
		if ((move_in_map[row] & column ) == 0) {
			/* 1 : déplacement OK */
			go_left();
		}
	}
  }
  /* 4 : pas de déplacement. */
}

/****************************************/
/*   test function for right movement   */
/****************************************/
movertest()
{
int column;
char row;

  if (spriteX >= 255) {
    /* Si on est au bord à droite, on évite de sortir */
    return;
  }

  if (spriteX & 0xf) {
	/* En milieu de case, on passe */
	go_right();
  } else{
	 /* En bout de case
	  * On calcule la colonne actuelle (pour mask) */
	 /*colNumber = spriteX/16;*/
	 column = 1 << ((spriteX>>4)+1);
	 /*column = 1;
	 for (colNumber =0 ; colNumber < spriteX/16 +1; colNumber++) {
		 column = column *2;
	 }*/
	 /* On fait un décalage pour tester la colonne à droite. */
	 /*column = column *2;*/
	 /* on calcul la ligne courante, à partir de la position en Y divisé par 16 */
	 row = spriteY>>4;
	 /* On test si on est aligné verticalement */
      if (spriteY & 0xf) {
		/* Non aligné, il faut vérifier les cases au dessus/au dessous */
		 if (((move_in_map[row] & column ) == 0) &&
			 ((move_in_map[row+1] & column ) == 0)) {
				 /* 1 : déplacement OK */
				 go_right();
				 return;
		 } else {
			 if (((move_in_map[row] & column ) != 0) &&
				((move_in_map[row+1] & column ) == 0)) {
					/* 3 : Décalage vers le bas */
					go_down();
					return;
			 } else {
				 if (((move_in_map[row] & column ) == 0) &&
					((move_in_map[row+1] & column ) != 0)) {
						/* 2 : Décalage vers le haut */
						go_up();
						return;
				}
			 }
		 }
	} else {
		/* Aligné, on vérifie juste la case à gauche */
		if ((move_in_map[row] & column ) == 0) {
			/* 1 : déplacement OK */
			go_right();
		}
	} 
  }
  /* 4 : pas de déplacement. */
}

/*************************************/
/*   test function for up movement   */
/*************************************/
moveutest()
{
int column, columnNext;
char row;

  if (spriteY <= 0) {
    /* Si on est au bord en haut, on évite de sortir */
    return;
  }

  if (spriteY & 0xf) {
	  /* En milieu de case, on passe */
	go_up();
  } else {
	  column = 1 << (spriteX>>4);
	  /* On calcul la ligne précédente */
	  row = (spriteY>>4) -1;
    if (spriteX & 0xf) {
	  /* Non aligné horizontalement, on calcule la colonne suivante */
	  columnNext = column << 1;
	  
	  if (((move_in_map[row] & column) == 0) &&
	       ((move_in_map[row] & columnNext) == 0)) {
		 /* Les 2 cases laissent passer */
		 /* 1 : déplacement OK */
		 go_up();
		 return;
	  } else {
		  if (((move_in_map[row] & column) != 0) &&
			  ((move_in_map[row] & columnNext) == 0)) {
		    /* La colonne de droite est libre */
			/* 3 : décalage à droite */
			go_right();
			return;
		  } else {
			  if (((move_in_map[row] & column) == 0) &&
			      ((move_in_map[row] & columnNext) != 0)) {
			    /* La colonne de gauche est libre */
				/* 2: décalage à gauche */
				go_left();
				return;
			  }
		  }
	  }
	} else {
	  /* On est aligné, on teste juste la case au dessus */
	  if ((move_in_map[row] & column) == 0) {
		/* 1 : déplacement OK */
		go_up();
	  }
	}
  }
  /* 4 : Déplacement refusé */
}

/***************************************/
/*   test function for down movement   */
/***************************************/
movedtest()
{
int column, columnNext;
char row;

  if (spriteY >= 223) {
    /* Si on est au bord en bas, on évite de sortir */
    return;
  }

  if (spriteY & 0xf) {
	  /* En milieu de case, on passe */
	go_down();
  } else {
	  column = 1 << (spriteX>>4);
	  /* On calcul la ligne suivante */
	  row = (spriteY>>4) +1;
    if (spriteX & 0xf) {
	  /* Non aligné horizontalement, on calcule la colonne suivante */
	  columnNext = column << 1;
	  
	  if (((move_in_map[row] & column) == 0) &&
	       ((move_in_map[row] & columnNext) == 0)) {
		/* Les 2 cases laisses passer */
		/* 1 : déplacement OK */
		go_down();
		return;
	  } else {
		  if (((move_in_map[row] & column) != 0) &&
			  ((move_in_map[row] & columnNext) == 0)) {
		    /* La colonne de droite est libre */
			/* 3 : décalage à droite */
			go_right();
			return;
		  } else {
			  if (((move_in_map[row] & column) == 0) &&
			      ((move_in_map[row] & columnNext) != 0)) {
			    /* La colonne de gauche est libre */
				/* 2: décalage à gauche */
				go_left();
				return;
			  }
		  }
	  }
	} else {
	  /* On est aligné, on teste juste la case au dessus */
	  if ((move_in_map[row] & column) == 0) {
		/* 1 : déplacement OK */
		go_down();
	  }
	}
  }
  /* 4 : Déplacement refusé */
}


manage_move() {
	/* RAZ de la direction */
	direction = 0;
	if (joy(0) & JOY_LEFT) {
	  moveltest();
	}
    if (joy(0) & JOY_RGHT) {
	  movertest();
	}
    if (joy(0) & JOY_UP) {
	  moveutest();
	}
    if (joy(0) & JOY_DOWN) {
	  movedtest();
	}
  
  if (direction != 0 && nb_monsters > 0) {
    if ((rand() % 200) < (monster / 10)) {
      spr_hide();
      
      monsterID=1;
      /*monster=0;*/
      
      /*battle();*/
      cd_execoverlay(OVL_BATTLE);

      /*spr_show();
      spr_x(spriteX);
      spr_y(spriteY);
      /* On utilise la fonction de téléport pour réafficher la carte *
      teleport(oldpos);
      music1Init();
      satb_update();*/
     }
  }
}

go_left(/*counters_c, size_c, counters_i, size_i*/)
/*char counters_c[], size_c, size_i;
int counters_i[];*/
{
  if (!(direction & (DIR_LEFT | DIR_RIGHT))) {
    direction = direction | DIR_LEFT;
    SPRPATTERN=LFT_Face+pattern;
    spriteX--;
    spr_x(spriteX);
    meter++;
    monster++;
    manage_events();
  }
  /*for(i=0; i<size_c; i++) {
	counters_c[i]++;
  }
  
  for(i=0; i<size_i; i++) {
	counters_i[i]++;
  }*/
}

go_right(/*counters_c, size_c, counters_i, size_i*/)
/*char counters_c[], size_c, size_i;
int counters_i[];*/
{
  if (!(direction & (DIR_LEFT | DIR_RIGHT))) {
    direction = direction | DIR_RIGHT;
    SPRPATTERN=RGT_Face+pattern;
    spriteX++;
    spr_x(spriteX);
    meter++;
    monster++;
    manage_events();
  }
  /*for(i=0; i<size_c; i++) {
	counters_c[i]++;
  }
  
  for(i=0; i<size_i; i++) {
	counters_i[i]++;
  }*/
}

go_up(/*counters_c, size_c, counters_i, size_i*/)
/*char counters_c[], size_c, size_i;
int counters_i[];*/
{
  if (!(direction & (DIR_UP | DIR_DOWN))) {
    direction = direction | DIR_UP;
    SPRPATTERN=BK_Face+pattern;
    spriteY--;
    spr_y(spriteY);
    meter++;
    monster++;
    manage_events();
  }
  /*for(i=0; i<size_c; i++) {
	counters_c[i]++;
  }
  
  for(i=0; i<size_i; i++) {
	counters_i[i]++;
  }*/
}

go_down(/*counters_c, size_c, counters_i, size_i*/)
/*char counters_c[], size_c, size_i;
int counters_i[];*/
{
  if (!(direction & (DIR_UP | DIR_DOWN))) {
    direction = direction | DIR_DOWN;
    SPRPATTERN=FR_Face+pattern;
    spriteY++;
    spr_y(spriteY);
    meter++;
    monster++;
    manage_events();
  }
  /*for(i=0; i<size_c; i++) {
	counters_c[i]++;
  }
  
  for(i=0; i<size_i; i++) {
	counters_i[i]++;
  }*/
}

manage_events() {
  char pos_X, pos_Y;
  
  if ((direction & (DIR_LEFT | DIR_RIGHT)) && spriteX & 0x8 && !(spriteX & 0x7)) {
    /* Si on est en milieu de case en allant à gauche ou à droite */
    /* Vers la gauche, on teste la case du sprite */
    pos_X = spriteX >> 4;
    /*if (direction & DIR_LEFT) {
    
    } else*/
    if (direction & DIR_RIGHT) {
      /* Vers la droite, on teste la case suivante du sprite */
      pos_X ++;      
    }
    
    pos_Y = spriteY >> 4;
    if (spriteY & 0x8) {
      pos_Y++;
    }
    
    /* On vérifie et agit s'il y a un event sur la case */
    check_event(pos_Y + (256*pos_X));
    
  } else if ((direction & (DIR_UP | DIR_DOWN)) && spriteY & 0x8 && !(spriteY & 0x7)) {
    /* Si on est en milieu de case en allant en haut ou en bas */
    /* Pour un déplacement vers le haut ou le bas on calcul la case en fonction de là où on se trouve le plus */
    pos_X = spriteX >> 4;
    if (spriteX & 0x8) {
      pos_X++;
    }
    
    pos_Y = spriteY >> 4;
    if (direction & DIR_DOWN) {
      /* Vers le bas on prend la case suivante*/
      pos_Y++;
    }
    
    /* On vérifie et agit s'il y a un event sur la case */
    check_event(pos_Y + (256*pos_X));
  }
}

check_event(event_pos)
int event_pos;
{
  char i;
  
  for(i=0; i<nb_events; i++) {
    if (event_in_map[i*4] == event_pos) {
      do_event(event_in_map[(i*4)+1], event_in_map[(i*4)+2], event_in_map[(i*4)+3]);
      return;
    }
  }  
}

do_event(type, arg1, arg2) 
int type, arg1, arg2;
{
  switch(type) {
    case TELEPORT_EVT :
      /* arg1 : id de la prochaine map */
      /* arg2 : position */
      spriteX = (arg2 >> 8) << 4;
      spriteY = (arg2 & 0xff) << 4;
      spr_x(spriteX);
      spr_y(spriteY);
      teleport(arg1);
      break;
    case BATTLE_EVT :
      break;
    default :
      break;
  }
  
}

teleport(mapId)
int mapId;
{
  oldpos = mapId;
  monster=0;
  meter=0;
  switch(mapId) {
    case 1:
      map1();
      break;
    case 2:
      map2();
      break;
    case 3:
      map3();
      break;
    case 4:
      map4();
      break;
    case 20000:
      silence();
      housemap1();
      break;
  }
}


/**
 * Fonction de gestion du changement de pattern pour le sprite du personnage.
 * Calcul quand il faut animer le sprite en changeant de pattern.
 * Compatible avec un changement de pattern principal pour voir le personnage de face, de dos ou de coté.
 */
manage_pattern() {
  if (meter>30) {
    meter=0;
    if(!(pattern)) {
      pattern=0X40;
      positive_pattern=1;
      SPRPATTERN+=0x0040;
    } else {
      if (pattern==0x80) {
      positive_pattern=0;
      pattern=0x40;
      SPRPATTERN-=0x0040;
      } else {
      pattern=positive_pattern*0x80;
      SPRPATTERN=SPRPATTERN-0x40+positive_pattern*0x80;
      }
    }
  }
  spr_pattern(SPRPATTERN);
  meter++;
}

/**
  * fonction générique de déplacement
  */
move() {
  
  spr_show();
  SPRPATTERN=FR_Face;
  pattern=0;
  positive_pattern=1;
  spr_pattern(SPRPATTERN);
  
  while(!(JOY_STRT & joytrg(0))) {
    satb_update();
    rand();

    manage_move();
    
    manage_pattern();
    music_update();
    vsync();
  }
  return -1;
}

/**********************************************/
/*           map 1 movement system            */
/**********************************************/
/*move1()
{
  char i;
  
  map1();
  
  positive_pattern=1;
  pattern=0;
  meter = 0;
  spr_set(0);
  spr_show();
  SPRPATTERN=FR_Face;
  spr_pattern(SPRPATTERN);
  if(battleEnd)
  {
    music1Init();
    battleEnd=0;
  }
  
  while(!(JOY_STRT & joytrg(0))) {
    satb_update();
    rand();

    manage_move();
	
    if ((spriteX<96) && (spriteX>64) && (spriteY<144) && (spriteY>112))	{
      spriteX=16;
      spriteY=16;
      spr_x(spriteX);
      spr_y(spriteY);
      spr_hide();
      satb_update();
      border(0,0,32,10);
      blank(1,1,30,8);
      put_string("You are under attack!",2,2);
      for(i=0;i<30;i++)
      {
        music_update();
        vsync(1);
      }
      put_char('>',30,8);
      while(!(joytrg(0) & JOY_STRT))
      {
        music_update();
        vsync();
      }
      silence();
      /*battle(LIFEMAX*2/3+rand()%(LIFEMAX/3),ATK,DEF,DEX,50,0);*/
      /*monsterID=0;
      /*battle();*/
      /*cd_execoverlay(OVL_BATTLE);
      /*spr_set(0);
      map1();
      spr_show();
      satb_update();
    }*/
   /* if (spriteX>239) {
		spriteX=2; spr_x(spriteX); return 2;
	}*/
  /*  manage_pattern();
    music_update();
    vsync();
  }
  return -1;
}*/

/***********************************************/
/*move2()
{
  char resist;
  int enemyres;
  map2();
  monster=0;
  meter=0;
  positive_pattern=1;
  enemyres=0;
  pattern=0;

  spr_set(0);
  spr_show();
  SPRPATTERN=FR_Face;
  if(battleEnd)
  {
    music1Init();
    battleEnd=0;
  }

  while(!(JOY_STRT & joytrg(0))) {
    satb_update();
    
	manage_move();
	
      if (spriteY>210)
	{spriteY=3; spr_y(spriteY); return 3;}
      if (spriteX<1)
	{spriteX=238; spr_x(spriteX); return 1;}
      if (!(monster % 10))
	{
	 if ((rand() % 200) < (monster / 10))
	 {
	  spr_hide();
	  /*resist=rand()&0xf;
	  if (resist&0x1) enemyres=(1<<(rand()&3+1));
	  if (resist&0x2) enemyres+=(1<<(rand()&3+5));
	  if (resist&0x4) enemyres+=(1<<(rand()&3+9));
	  if (resist&0x8) enemyres+=(1<<(rand()&3+13));*/
	/*  monsterID=1;
	  monster=0;
	  /*battle();*/
	/*  cd_execoverlay(OVL_BATTLE);

	  /*spr_show;
	  spr_x(spriteX);
	  spr_y(spriteY);
	  map2();
	  music1Init();
	  satb_update();*/
/*	 }
	}
    manage_pattern();
      music_update();
      vsync();
    }
  return -1;
}*/
/***********************************************/
/*move3()
{

  meter=0;
  positive_pattern=1;
  SPRPATTERN=FR_Face;
  pattern=0;
  map3();
  
  while(!(JOY_STRT & joytrg(0))) {
    satb_update();
    
	manage_move();
	
      if (spriteY<1)
	{spriteY=207; spr_y(spriteY); return 2;}
      if (spriteY>210)
	{spriteY=2; spr_y(spriteY); return 4;}
      if ((spriteX>197) && (spriteY>181))
	{
	  silence();
	  spr_hide();
	  satb_update();
	  help();
	  spriteX=100;
	  spriteY=100;
	  spr_x(spriteX);
	  spr_y(spriteY);
	  spr_show();
	  satb_update();
	  map3();
	}
    manage_pattern();
      music_update();
      vsync();
    }
  return -1;
}*/
/**************************************/
/*move4()
{

  map4();
  
  SPRPATTERN=FR_Face;
  positive_pattern=1;
  meter=0;
  pattern=0;

  silence();
  spr_hide();
  satb_update();
  if (FirstTime)
  {
    Welcome();
    FirstTime=0;
  }
  map4();
  spr_show();
  
  while(!(JOY_STRT & joytrg(0))) {
    satb_update();
    
	manage_move();
	
      if (spriteY<1)
	{
	 spriteY=205;
	 spr_y(spriteY);
	 music1Init();
	 return 3;
	}
      
      if ((spriteY>96)&&(spriteY<101)&&(spriteX>55)&&(spriteX<60))
         {
	   spriteX=128;
           spriteY=160;
           spr_y(spriteY);
           spr_x(spriteX);
           return 20000;
         }

    manage_pattern();
      vsync();
    }
  return -1;
}*/

/************************************/
/*housemove1()
{


  housemap1();

  SPRPATTERN=FR_Face;
  meter=0;
  pattern=0;
  positive_pattern=1;

  if (FirstTime)
    {
      spr_hide();
      satb_update();
      FirstTime=0;
      HouseText1();
      housemap1();
      spr_show();
      satb_update();
    }

  while(!(JOY_STRT & joytrg(0))) {
    satb_update();

    manage_move();

     if (spriteY>178)
        {
	  spriteX=56;
	  spriteY=110;
          spr_y(spriteY);
          spr_x(spriteX);
          return 4;
	}

    manage_pattern();
      vsync();
    }
  return -1; 
}*/
