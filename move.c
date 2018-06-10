
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

  if (g_spriteX <= 0) {
    /* Si on est au bord à gauche, on évite de sortir */
    return;
  }

  if (g_spriteX & 0xf) {
	  /* En milieu de case, on passe */
	  go_left();
  } else {
	 /* En bout de case
	  * On calcule la colonne actuelle (pour mask) */
	 column = 1 << ((g_spriteX>>4)-1);
	 /*column = 1;
	 for (colNumber =0 ; colNumber < spriteX/16 -1; colNumber++) {
		 column = column *2;
	 }*/
	 /* On fait un décalage pour tester la colonne à gauche. */
	 /*column = column >> 1;*/
	 /* on calcul la ligne courante, à partir de la position en Y divisé par 16 */
	 row = g_spriteY>>4;
	 /* On test si on est aligné verticalement */
     if (g_spriteY & 0xf) {
		 /* Non aligné, il faut vérifier les cases au dessus/au dessous */
		 if (((g_move_in_map[row] & column ) == 0) &&
			 ((g_move_in_map[row+1] & column ) == 0)) {
				 /* 1 : déplacement OK */
				 go_left();
				 return;
		 } else {
			 if (((g_move_in_map[row] & column ) != 0) &&
				((g_move_in_map[row+1] & column ) == 0)) {
					/* 3 : Décalage vers le bas */
					go_down();
					return;
			 } else {
				 if (((g_move_in_map[row] & column ) == 0) &&
					((g_move_in_map[row+1] & column ) != 0)) {
						/* 2 : Décalage vers le haut */
						go_up();
						return;
				}
			 }
		 }
	} else {
		/* Aligné, on vérifie juste la case à gauche */
		if ((g_move_in_map[row] & column ) == 0) {
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

  if (g_spriteX >= 255) {
    /* Si on est au bord à droite, on évite de sortir */
    return;
  }

  if (g_spriteX & 0xf) {
	/* En milieu de case, on passe */
	go_right();
  } else{
	 /* En bout de case
	  * On calcule la colonne actuelle (pour mask) */
	 /*colNumber = spriteX/16;*/
	 column = 1 << ((g_spriteX>>4)+1);
	 /*column = 1;
	 for (colNumber =0 ; colNumber < spriteX/16 +1; colNumber++) {
		 column = column *2;
	 }*/
	 /* On fait un décalage pour tester la colonne à droite. */
	 /*column = column *2;*/
	 /* on calcul la ligne courante, à partir de la position en Y divisé par 16 */
	 row = g_spriteY>>4;
	 /* On test si on est aligné verticalement */
      if (g_spriteY & 0xf) {
		/* Non aligné, il faut vérifier les cases au dessus/au dessous */
		 if (((g_move_in_map[row] & column ) == 0) &&
			 ((g_move_in_map[row+1] & column ) == 0)) {
				 /* 1 : déplacement OK */
				 go_right();
				 return;
		 } else {
			 if (((g_move_in_map[row] & column ) != 0) &&
				((g_move_in_map[row+1] & column ) == 0)) {
					/* 3 : Décalage vers le bas */
					go_down();
					return;
			 } else {
				 if (((g_move_in_map[row] & column ) == 0) &&
					((g_move_in_map[row+1] & column ) != 0)) {
						/* 2 : Décalage vers le haut */
						go_up();
						return;
				}
			 }
		 }
	} else {
		/* Aligné, on vérifie juste la case à gauche */
		if ((g_move_in_map[row] & column ) == 0) {
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

  if (g_spriteY <= 0) {
    /* Si on est au bord en haut, on évite de sortir */
    return;
  }

  if (g_spriteY & 0xf) {
	  /* En milieu de case, on passe */
	go_up();
  } else {
	  column = 1 << (g_spriteX>>4);
	  /* On calcul la ligne précédente */
	  row = (g_spriteY>>4) -1;
    if (g_spriteX & 0xf) {
	  /* Non aligné horizontalement, on calcule la colonne suivante */
	  columnNext = column << 1;
	  
	  if (((g_move_in_map[row] & column) == 0) &&
	       ((g_move_in_map[row] & columnNext) == 0)) {
		 /* Les 2 cases laissent passer */
		 /* 1 : déplacement OK */
		 go_up();
		 return;
	  } else {
		  if (((g_move_in_map[row] & column) != 0) &&
			  ((g_move_in_map[row] & columnNext) == 0)) {
		    /* La colonne de droite est libre */
			/* 3 : décalage à droite */
			go_right();
			return;
		  } else {
			  if (((g_move_in_map[row] & column) == 0) &&
			      ((g_move_in_map[row] & columnNext) != 0)) {
			    /* La colonne de gauche est libre */
				/* 2: décalage à gauche */
				go_left();
				return;
			  }
		  }
	  }
	} else {
	  /* On est aligné, on teste juste la case au dessus */
	  if ((g_move_in_map[row] & column) == 0) {
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

  if (g_spriteY >= 223) {
    /* Si on est au bord en bas, on évite de sortir */
    return;
  }

  if (g_spriteY & 0xf) {
	  /* En milieu de case, on passe */
	go_down();
  } else {
	  column = 1 << (g_spriteX>>4);
	  /* On calcul la ligne suivante */
	  row = (g_spriteY>>4) +1;
    if (g_spriteX & 0xf) {
	  /* Non aligné horizontalement, on calcule la colonne suivante */
	  columnNext = column << 1;
	  
	  if (((g_move_in_map[row] & column) == 0) &&
	       ((g_move_in_map[row] & columnNext) == 0)) {
		/* Les 2 cases laisses passer */
		/* 1 : déplacement OK */
		go_down();
		return;
	  } else {
		  if (((g_move_in_map[row] & column) != 0) &&
			  ((g_move_in_map[row] & columnNext) == 0)) {
		    /* La colonne de droite est libre */
			/* 3 : décalage à droite */
			go_right();
			return;
		  } else {
			  if (((g_move_in_map[row] & column) == 0) &&
			      ((g_move_in_map[row] & columnNext) != 0)) {
			    /* La colonne de gauche est libre */
				/* 2: décalage à gauche */
				go_left();
				return;
			  }
		  }
	  }
	} else {
	  /* On est aligné, on teste juste la case au dessus */
	  if ((g_move_in_map[row] & column) == 0) {
		/* 1 : déplacement OK */
		go_down();
	  }
	}
  }
  /* 4 : Déplacement refusé */
}


manage_move() {
	/* RAZ de la direction */
	g_direction = 0;
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
  
  if (g_direction != 0 && g_nb_monsters > 0) {
    if ((rand() % 400) < (g_monster / 20)) {
      
      do_battle_event(1, g_map_battle_bg);

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

go_left() {
  /* S'il n'y a pas encore eu de déplacement, on incrémente les compteurs */
  if (!g_direction) {
    g_meter++;
    g_monster++;
  }
  if (!(g_direction & (DIR_LEFT | DIR_RIGHT))) {
    g_direction = g_direction | DIR_LEFT;
    g_SPRPATTERN=LFT_Face+g_pattern;
    g_spriteX--;
    spr_x(g_spriteX);
    manage_events();
  }
}

go_right() {
  /* S'il n'y a pas encore eu de déplacement, on incrémente les compteurs */
  if (!g_direction) {
    g_meter++;
    g_monster++;
  }
  if (!(g_direction & (DIR_LEFT | DIR_RIGHT))) {
    g_direction = g_direction | DIR_RIGHT;
    g_SPRPATTERN=RGT_Face+g_pattern;
    g_spriteX++;
    spr_x(g_spriteX);
    manage_events();
  }
}

go_up() {
  /* S'il n'y a pas encore eu de déplacement, on incrémente les compteurs */
  if (!g_direction) {
    g_meter++;
    g_monster++;
  }
  if (!(g_direction & (DIR_UP | DIR_DOWN))) {
    g_direction = g_direction | DIR_UP;
    g_SPRPATTERN=BK_Face+g_pattern;
    g_spriteY--;
    spr_y(g_spriteY);
    manage_events();
  }
}

go_down() {
  /* S'il n'y a pas encore eu de déplacement, on incrémente les compteurs */
  if (!g_direction) {
    g_meter++;
    g_monster++;
  }
  
  if (!(g_direction & (DIR_UP | DIR_DOWN))) {
    g_direction = g_direction | DIR_DOWN;
    g_SPRPATTERN=FR_Face+g_pattern;
    g_spriteY++;
    spr_y(g_spriteY);
    manage_events();
  }
}

manage_events() {
  char pos_X, pos_Y;
  
  if ((g_direction & (DIR_LEFT | DIR_RIGHT)) && g_spriteX & 0x8 && !(g_spriteX & 0x7)) {
    /* Si on est en milieu de case en allant à gauche ou à droite */
    /* Vers la gauche, on teste la case du sprite */
    pos_X = g_spriteX >> 4;
    /*if (direction & DIR_LEFT) {
    
    } else*/
    if (g_direction & DIR_RIGHT) {
      /* Vers la droite, on teste la case suivante du sprite */
      pos_X ++;      
    }
    
    pos_Y = g_spriteY >> 4;
    if (g_spriteY & 0x8) {
      pos_Y++;
    }
    
    /* On vérifie et agit s'il y a un event sur la case */
    check_event(pos_Y + (256*pos_X));
    
  } else if ((g_direction & (DIR_UP | DIR_DOWN)) && g_spriteY & 0x8 && !(g_spriteY & 0x7)) {
    /* Si on est en milieu de case en allant en haut ou en bas */
    /* Pour un déplacement vers le haut ou le bas on calcul la case en fonction de là où on se trouve le plus */
    pos_X = g_spriteX >> 4;
    if (g_spriteX & 0x8) {
      pos_X++;
    }
    
    pos_Y = g_spriteY >> 4;
    if (g_direction & DIR_DOWN) {
      /* Vers le bas on prend la case suivante*/
      pos_Y++;
    }
    
    /* On vérifie et agit s'il y a un event sur la case */
    check_event(pos_Y + (256*pos_X));
  }
}

check_event(p_event_pos)
unsigned int p_event_pos;
{
  unsigned char i;
  
  for(i=0; i<g_nb_events; i++) {
    if (g_event_in_map[i*4] == p_event_pos) {
      do_event(g_event_in_map[(i*4)+1], g_event_in_map[(i*4)+2], g_event_in_map[(i*4)+3]);
      return;
    }
  }  
}

do_event(type, arg1, arg2) 
unsigned int type, arg1, arg2;
{
  switch(type) {
    case TELEPORT_EVT :
      /* arg1 : id de la prochaine map */
      /* arg2 : position */
      g_spriteX = (arg2 >> 8) << 4;
      g_spriteY = (arg2 & 0xff) << 4;
      spr_x(g_spriteX);
      spr_y(g_spriteY);
      teleport(arg1);
      break;
    case BATTLE_EVT :
      do_battle_event(arg1, arg2);
      break;
    case MAP_SPECIAL_EVT :
      do_special_event(arg1, arg2);
      break;
    default :
      break;
  }
  
}

/**
 * Teleport caracter to map mapID.
 * Basically a big switch as you can't use a method pointer.
 * mapId : int : id of the destination map
 */
teleport(p_mapId)
unsigned int p_mapId;
{
  g_oldpos = p_mapId;
  g_monster=0;
  g_meter=0;
  switch(p_mapId) {
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
      housemap1();
      break;
  }
}

do_special_event(arg1, arg2)
unsigned int arg1, arg2;
{
  switch(g_oldpos) {
    case 1:
      /* event_map1(); */
      break;
    case 2:
      /* event_map2(); */
      break;
    case 3:
      event_map3();
      break;
    case 4:
      event_map4();
      break;
    case 20000:
      /* event_housemap1(); */
      break;
  }
}

/**
 * monstreID : id of the monster to fight
 * map_bg_id : id of the battle background map
 */
do_battle_event(p_monstreID, p_map_bg_id)
unsigned int p_monstreID, p_map_bg_id;
{
  silence();
  spr_hide();
      
  g_monsterID=p_monstreID;
  g_battle_bg=p_map_bg_id;
  /*monster=0;*/
      
  /*battle();*/
  cd_execoverlay(OVL_BATTLE);
}


/**
 * Fonction de gestion du changement de pattern pour le sprite du personnage.
 * Calcul quand il faut animer le sprite en changeant de pattern.
 * Compatible avec un changement de pattern principal pour voir le personnage de face, de dos ou de coté.
 */
manage_pattern() {
  if (g_meter>30) {
    g_meter=0;
    if(!(g_pattern)) {
      g_pattern=0X40;
      g_positive_pattern=1;
      g_SPRPATTERN+=0x0040;
    } else {
      if (g_pattern==0x80) {
      g_positive_pattern=0;
      g_pattern=0x40;
      g_SPRPATTERN-=0x0040;
      } else {
      g_pattern=g_positive_pattern*0x80;
      g_SPRPATTERN=g_SPRPATTERN-0x40+g_positive_pattern*0x80;
      }
    }
  }
  spr_pattern(g_SPRPATTERN);
  g_meter++;
}

/**
  * fonction générique de déplacement
  */
move() {
  
  spr_show();
  g_SPRPATTERN=FR_Face;
  g_pattern=0;
  g_positive_pattern=1;
  spr_pattern(g_SPRPATTERN);
  
  while(!(JOY_STRT & joytrg(0))) {
    satb_update();
    rand();

    manage_move();
    
    manage_pattern();
    /*music_update();*/
    vsync();
  }
  return -1;
}


