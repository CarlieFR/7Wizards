/**
 * Fichier contenant des fonctions utilitaires pour la gestion des chaines de caractères
 */

/*char * digit_as_str(number)
int number;
{
  switch(number) {
    case 0:
      return "0";
    case 1:
      return "1";
    case 2:
      return "2";
    case 3:
      return "3";
    case 4:
      return "4";
    case 5:
      return "5";
    case 6:
      return "6";
    case 7:
      return "7";
    case 8:
      return "8";
    case 9:
      return "9";
    default :
      return "";
  }
}*/

/*char * int_to_str(number)
int number
{
  char* result="";
  char i;
  
  for (i=5; i>0; i--) {
    int limit = 10^i;
    if (number > limit) {
      /* On ajoute le chiffre du nombre le plus à gauche */
      /*strcat(result, digit_as_str((number/limit)%10));
    }
  }
  
  return result;
}*/

print_text(text, x, y, nb_lines, options)
char* text;
char x,y,nb_lines;
char* options[];
{
  char line_buffer[31], word_buffer[31];
  char line_size, index, current_line, i, wait_counter;
  int text_index;
  line_size=0;
  index=0;
  current_line=0;
  text_index=0;
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
          while(!(joy(0))) {
            wait_counter++;
            if (wait_counter == 6) {
              put_string(empty_indicator, 27, y-1+(2*nb_lines));
            } else if (wait_counter == 12) {
              put_string(continue_indicator, 27, y-1+(2*nb_lines));
              wait_counter = 0;
            }
            vsync(10);
          }
          put_string(empty_indicator, 27, y+1+(2*nb_lines));
        }
        
      }
      /* Si on tombe sur une fin de ligne exprès*/
      if (text[text_index] == '\n') {
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
          while(!(joy(0))) {
            wait_counter++;
            if (wait_counter == 6) {
              put_string(empty_indicator, 27, y-1+(2*nb_lines));
            } else if (wait_counter == 12) {
              put_string(continue_indicator, 27, y-1+(2*nb_lines));
              wait_counter = 0;
            }
            vsync(10);
          }
          put_string(empty_indicator, 27, y-1+(2*nb_lines));
        }
      }
      /* On incrémente le compteur pour passer au mot suivant */
      text_index++;
    } else {
      /* On constitue le prochain mot */
      word_buffer[index++] = text[text_index++];
    }
  }
  /* On est en fin de text d'origine, on affiche le buffer restant */
  if (index != 0) {
    /*word_buffer[index] = NULL;*/
    /* On rajoute l'espace */
    line_buffer[line_size++]=' ';
    /* On ajoute une terminaison de chaine pour faire la concaténation */
    /*line_buffer[line_size]=NULL;*/
    /* Puis on concatène le mot à la ligne */
    /*strcat(line_buffer, word_buffer);*/
    for (i=0; i<index; i++) {
      line_buffer[line_size++] = word_buffer[i];
    }
    line_buffer[line_size]=NULL;
    
    put_string(line_buffer, x, y+(2*current_line));
  }
  vsync(5);
  wait_counter = 11;
  while(!(joy(0))) {
    wait_counter++;
    if (wait_counter == 6) {
      put_string(empty_indicator, 27, y-1+(2*nb_lines));
    } else if (wait_counter == 12) {
      put_string(end_indicator, 27, y-1+(2*nb_lines));
      wait_counter = 0;
    }
    vsync(10);
  }
  put_string(empty_indicator, 27, y+1+(2*nb_lines));
  /* TODO mieux gérer la pause */
}