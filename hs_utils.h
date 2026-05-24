#ifndef HS_UTILS_H
#define HS_UTILS_H

#define LUNGIME 20
#define LATIME 10

// Culori ANSI (rămân la fel)
#define RESET     "\033[0m"
#define ROSU      "\033[31m"
#define VERDE     "\033[32m"
#define GALBEN    "\033[33m"
#define ALBASTRU  "\033[34m"
#define MAGENTA   "\033[35m"
#define CIAN      "\033[36m"
#define ALB       "\033[37m"

extern char camp[LUNGIME][LATIME];
extern char piesa_activa[4][4];
extern char piese_baza[7][4][4];
extern int scor, piesa_x, piesa_y, tip_piesa;
extern char* culori_piese[];

// Funcții adaptate pentru Linux
void mutaCursor(int x, int y);
int coliziune(int nx, int ny, char piesa_test[4][4]);
void noua_piesa();
void deseneaza();
void porneste_muzica();

// Funcții noi necesare pentru a înlocui conio.h pe Linux
void set_conio_terminal_mode();
int kbhit();
int getch();

#endif