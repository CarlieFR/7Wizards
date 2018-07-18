/**
 * Select next player available.
 * If there is no next available, return the current player.
 */
unsigned char util_selectNextPlayer(p_currentPlayer)
unsigned char p_currentPlayer;
{
  unsigned char l_tempSelection;
  
  if (p_currentPlayer > 2) {
    return p_currentPlayer;
  }
  
  for (l_tempSelection = p_currentPlayer+1; l_tempSelection < 4; l_tempSelection++) {
    if (g_activePlayer[l_tempSelection]) {
      return l_tempSelection;
    }
  }
  
  return p_currentPlayer;
}

/**
 * Select previous player available.
 * If there is no previous available, return the current player.
 */
unsigned char util_selectPrevPlayer(p_currentPlayer)
unsigned char p_currentPlayer;
{
  unsigned char l_tempSelection;
  
  if (p_currentPlayer < 1) {
    return p_currentPlayer;
  }
  
  for (l_tempSelection = p_currentPlayer-1; l_tempSelection > -1; l_tempSelection--) {
    if (g_activePlayer[l_tempSelection]) {
      return l_tempSelection;
    }
  }
  
  return p_currentPlayer;
}