#ifndef EVERYTHING_BUT_MAIN_INCLUDED
#define EVERYTHING_BUT_MAIN_INCLUDED

void show_instructions();
void show_map(int map[10][15]);
void show_menu(int map[10][15], int digger_i, int digger_j, int *timer);
bool endstep(int map[10][15], int digger_i, int digger_j, int *timer);

#endif // EVERYTHING_BUT_MAIN_INCLUDED
