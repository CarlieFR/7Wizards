/**
 * Fichier contenant des fonctions utilitaires pour la gestion des chaines de caractères
 */

 /**
  * Convertit un chiffre en caractère correspondant.
  * TODO voir si on ne peux pas optimiser ça avec une addition.
  * La valeuir en entrée doit être comprises entre 0 et 9.
  */
digit_as_str(number)
int number;
{
  switch(number) {
    case 0:
      return '0';
    case 1:
      return '1';
    case 2:
      return '2';
    case 3:
      return '3';
    case 4:
      return '4';
    case 5:
      return '5';
    case 6:
      return '6';
    case 7:
      return '7';
    case 8:
      return '8';
    case 9:
      return '9';
    default :
      return NULL;
  }
}

/**
 * Convertit un entier en chaine de caractères.
 * Renvoi un pointeur vers la chaine de caractères, à copier après après avant de faire un nouvel appel.
 */
int_to_str(number)
int number;
{
  char result[6];
  char i,index;
  int limit;
  
  index = 0;
  for (i=5; i>0; i--) {
    limit = 10^i;
    if (number > limit) {
      /* On ajoute le chiffre du nombre le plus à gauche */
      result[index++] = digit_as_str((number/limit)%10);
    }
  }
  result[index] = NULL;
  
  return result;
}

print_text(text, x, y, nb_lines)
char* text;
char x,y,nb_lines;
{
  print_text1(text, x, y, nb_lines, NULL);
}

print_text1(text, x, y, nb_lines, joker0)
char* text, *joker0;
char x,y,nb_lines;
{
  print_text2(text, x, y, nb_lines, joker0, NULL);
}

print_text2(text, x, y, nb_lines, joker0, joker1)
char* text, *joker0, *joker1;
char x,y,nb_lines;
{
  print_text3(text, x, y, nb_lines, joker0, joker1, NULL);
}

print_text3(text, x, y, nb_lines, joker0, joker1, joker2)
char* text, *joker0, *joker1, *joker2;
char x,y,nb_lines;
{
  print_text4(text, x, y, nb_lines, joker0, joker1, joker2, NULL);
}

print_text4(text, x, y, nb_lines, joker0, joker1, joker2, joker3)
char* text, *joker0, *joker1, *joker2, *joker3;
char x,y,nb_lines;
{
  print_text5(text, x, y, nb_lines, joker0, joker1, joker2, joker3, NULL);
}

print_text5(text, x, y, nb_lines, joker0, joker1, joker2, joker3, joker4)
char* text, *joker0, *joker1, *joker2, *joker3, *joker4;
char x,y,nb_lines;
{
  print_text6(text, x, y, nb_lines, joker0, joker1, joker2, joker3, joker4, NULL);
}

print_text6(text, x, y, nb_lines, joker0, joker1, joker2, joker3, joker4, joker5)
char* text, *joker0, *joker1, *joker2, *joker3, *joker4, *joker5;
char x,y,nb_lines;
{
  print_text7(text, x, y, nb_lines, joker0, joker1, joker2, joker3, joker4, joker5, NULL);
}

print_text7(text, x, y, nb_lines, joker0, joker1, joker2, joker3, joker4, joker5, joker6)
char* text, *joker0, *joker1, *joker2, *joker3, *joker4, *joker5, *joker6;
char x,y,nb_lines;
{
  print_text8(text, x, y, nb_lines, joker0, joker1, joker2, joker3, joker4, joker5, joker6, NULL);
}

print_text8(text, x, y, nb_lines, joker0, joker1, joker2, joker3, joker4, joker5, joker6, joker7)
char* text, *joker0, *joker1, *joker2, *joker3, *joker4, *joker5, *joker6, *joker7;
char x,y,nb_lines;
{
  print_text9(text, x, y, nb_lines, joker0, joker1, joker2, joker3, joker4, joker5, joker6, joker7, NULL);
}

print_text9(text, x, y, nb_lines, joker0, joker1, joker2, joker3, joker4, joker5, joker6, joker7, joker8)
char* text, *joker0, *joker1, *joker2, *joker3, *joker4, *joker5, *joker6, *joker7, *joker8;
char x,y,nb_lines;
{
  print_text10(text, x, y, nb_lines, joker0, joker1, joker2, joker3, joker4, joker5, joker6, joker7, joker8, NULL);
}

print_text10(text, x, y, nb_lines, joker0, joker1, joker2, joker3, joker4, joker5, joker6, joker7, joker8, joker9)
char* text, *joker0, *joker1, *joker2, *joker3, *joker4, *joker5, *joker6, *joker7, *joker8, *joker9;
char x,y,nb_lines;
{
  char line_buffer[31], word_buffer[31];
  char line_size, index, current_line, i, wait_counter, joker_index;
  char* joker_word;
  int text_index;
  line_size=0;
  index=0;
  current_line=0;
  text_index=0;
  vsync(1);
  /* buffer sert à construire la chaine temporaire avant de l'afficher */
  /* index indique la position dans le buffer */
  /* text_index est la position dans le texte d'origine */
  
  /* On boucle tant qu'on arrive pas en fin de chaine */
  while (text[text_index] != NULL ) {
    /* TODO vérifier si on un remplacement à faire */
    /* On stocke dans le buffer le caractère courant et on avance les index */
    /* TODO vérifier la autres cassure des mots en plus */
    if (text[text_index] == ' ' || text[text_index] == '\n') {
      /* On vérifie si le mot rentre dans la ligne courante */
      if (line_size + index < 30 - (x -1) ) {
        /*word_buffer[index] = NULL;*/
        if (line_size != 0) {
          /* Si on n'est pas au début de la ligne on rajoute l'espace */
          line_buffer[line_size++]=' ';
        }
        /* On ajoute une terminaison de chaine pour faire la concaténation */
        /*line_buffer[line_size]=NULL;*/
        /* Puis on concatène le mot à la ligne */
        for (i=0; i<index; i++) {
          line_buffer[line_size++] = word_buffer[i];
        }
        /*line_buffer[line_size]=NULL;*/
        /* On recalcul la longueur de la ligne */
        /*line_size = line_size+index;*/
        index = 0;
        
      } else {
        /* Le mot doit être décalé à la ligne suivante */
        /*line_buffer[line_size+1] = NULL;*/
        line_buffer[line_size]=NULL;
        put_string(line_buffer, x, y+(2*current_line));
        /*word_buffer[index] = NULL;*/
        
        /* On réinitialise la ligne avec le nouveau mot */
        /*strcpy(line_buffer, word_buffer);*/
        line_size = 0;
        for (i=0; i<index; i++) {
          line_buffer[line_size++] = word_buffer[i];
        }
        /*line_buffer[line_size]=NULL;*/
        
        /*line_size = index;*/
        index = 0;
        current_line++;
        /* On vérifie si on arrive sur la dernière ligne du texte */
        if (current_line == nb_lines) {
          /* TODO mieux gérer la  pause */
          current_line = 0;
          vsync(1);
          wait_counter = 11;
          while(!(joy(0) & TEXT_BUTTON_MASK)) {
            wait_counter++;
            if (wait_counter == 6) {
              put_string(empty_indicator, 27, y-1+(2*nb_lines));
            } else if (wait_counter == 12) {
              put_string(continue_indicator, 27, y-1+(2*nb_lines));
              wait_counter = 0;
            }
            vsync(10);
          }
          /*put_string(empty_indicator, 27, y+1+(2*nb_lines));*/
          blank(x,y,31-x,y-1+(2*nb_lines));
          vsync(20);
        }
        
      }
      /* Si on tombe sur une fin de ligne exprès*/
      if (text[text_index] == '\n') {
        /* Si on est pas en tout début de texte, on ajoute un retour à la ligne */
        if (current_line != 0 || line_size != 0) {
          /* Si la ligne n'est pas vide, on l'imprime */
          if (line_size != 0) {
            line_buffer[line_size]=NULL;
            put_string(line_buffer, x, y+(2*current_line));
            line_size = 0;
          }
          
          current_line++;
          
          if (current_line == nb_lines) {
            /* TODO mieux gérer la  pause */
            current_line = 0;
            vsync(1);
            wait_counter = 11;
            while(!(joy(0) & TEXT_BUTTON_MASK)) {
              wait_counter++;
              if (wait_counter == 6) {
                put_string(empty_indicator, 27, y-1+(2*nb_lines));
              } else if (wait_counter == 12) {
                put_string(continue_indicator, 27, y-1+(2*nb_lines));
                wait_counter = 0;
              }
              vsync(10);
            }
            /*put_string(empty_indicator, 27, y-1+(2*nb_lines));*/
            blank(x,y,31-x,y-1+(2*nb_lines));
            vsync(20);
          }
        }
      }
      /* On incrémente le compteur pour passer au mot suivant */
      text_index++;
    } else if (text[text_index] == '{') {
      /* On tombe sur un joker, donc on remplace le joker par le mot correspondant */
      joker_index = 0;
      switch(text[text_index+1]) {
        case '0' :
          joker_word = joker0;
          break;
        case '1' :
          joker_word = joker1;
          break;
        case '2' :
          joker_word = joker2;
          break;
        case '3' :
          joker_word = joker3;
          break;
        case '4' :
          joker_word = joker4;
          break;
        case '5' :
          joker_word = joker5;
          break;
        case '6' :
          joker_word = joker6;
          break;
        case '7' :
          joker_word = joker7;
          break;
        case '8' :
          joker_word = joker8;
          break;
        case '9' :
          joker_word = joker9;
          break;
        default :
          joker_word = joker0;
      }
      /*joker_word = options[joker_number];*/
      /*joker_number = text[text_index+1] - '0'; /* astuce pour récupérer la valeur du nombre */
      /* On remplit le mot courant avec l'option correspondant au joker */
      while (joker_word[joker_index] != NULL) {
        word_buffer[index++] = joker_word[joker_index++];
      }
      /* On se décale de 3 caractères, la taille du joker */
      text_index = text_index +3;
    } else {
      /* On constitue le prochain mot */
      word_buffer[index++] = text[text_index++];
    }
  }
  /* On est en fin de text d'origine, on affiche le buffer restant */
  if (index != 0) {
    /*word_buffer[index] = NULL;*/
    if (line_size + index > 30 - (x -1) ) {
      /* On dépasse la taille max de la ligne, il faut afficher la ligne actuelle et passer à la suivante */
      line_buffer[line_size]=NULL;
      put_string(line_buffer, x, y+(2*current_line));
        
      /* On réinitialise la ligne avec le nouveau mot */
      line_size = 0;
      /*for (i=0; i<index; i++) {
        line_buffer[line_size++] = word_buffer[i];
      }*/
      /* On se décale à la ligne suivante */
      current_line++;
      /* On vérifie si on arrive sur la dernière ligne du texte */
        if (current_line == nb_lines) {
          /* TODO mieux gérer la  pause */
          current_line = 0;
          vsync(1);
          wait_counter = 11;
          while(!(joy(0) & TEXT_BUTTON_MASK)) {
            wait_counter++;
            if (wait_counter == 6) {
              put_string(empty_indicator, 27, y-1+(2*nb_lines));
            } else if (wait_counter == 12) {
              put_string(continue_indicator, 27, y-1+(2*nb_lines));
              wait_counter = 0;
            }
            vsync(10);
          }
          blank(x,y,31-x,y-1+(2*nb_lines));
          vsync(20);
        }
    }
    if (line_size != 0) {
      /* On rajoute l'espace si on est pas en début de ligne */
      line_buffer[line_size++]=' ';
    }
    /* Puis on concatène le mot à la ligne */
    for (i=0; i<index; i++) {
      line_buffer[line_size++] = word_buffer[i];
    }
    line_buffer[line_size]=NULL;
    
    put_string(line_buffer, x, y+(2*current_line));
  }
  vsync(5);
  wait_counter = 11;
  while(!(joy(0) & TEXT_BUTTON_MASK)) {
    wait_counter++;
    if (wait_counter == 6) {
      put_string(empty_indicator, 27, y-1+(2*nb_lines));
    } else if (wait_counter == 12) {
      put_string(end_indicator, 27, y-1+(2*nb_lines));
      wait_counter = 0;
    }
    vsync(10);
  }
  put_string(empty_indicator, 27, y-1+(2*nb_lines));
  /* TODO mieux gérer la pause */
}