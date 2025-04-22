int move_count = 0; // declare movecount outside so player_switch can see it
char player_get_current()
{ // determines if it's W or B's turn
  static int move_count = 0;
  if (move_count % 2 == 0)
  {
    return 'W';
  } // white always goes first
  else
  {
    return 'B';
  }
}
