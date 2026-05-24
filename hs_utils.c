#include "hs_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

char camp[LUNGIME][LATIME] = {0};
int scor = 0, piesa_x = 3, piesa_y = 0, tip_piesa = 0;
char piesa_activa[4][4];
char* culori_piese[] = {CIAN, GALBEN, VERDE, ROSU, MAGENTA, ALBASTRU, ALB};

char piese_baza[7][4][4] = {
    {{1,1,1,1}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}}, // I
    {{1,1,0,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0}}, // O
    {{0,1,1,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0}}, // S
    {{1,1,0,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0}}, // Z
    {{1,1,1,0}, {0,1,0,0}, {0,0,0,0}, {0,0,0,0}}, // T
    {{1,1,1,0}, {1,0,0,0}, {0,0,0,0}, {0,0,0,0}}, // L
    {{1,1,1,0}, {0,0,1,0}, {0,0,0,0}, {0,0,0,0}}  // J
};

// Structură pentru a păstra setările originale ale terminalului Linux
struct termios orig_termios;

void set_conio_terminal_mode() {
    struct termios new_termios;
    tcgetattr(0, &orig_termios);
    new_termios = orig_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &new_termios);
}

int kbhit() {
    struct timeval tv = {0L, 0L};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

int getch() {
    int r;
    unsigned char c;
    if ((r = read(0, &c, sizeof(c))) < 0) return r;
    return c;
}

void mutaCursor(int x, int y) {
   
    printf("\033[%d;%dH", y + 1, x + 1);
}

int coliziune(int nx, int ny, char piesa_test[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (piesa_test[i][j]) {
                int cx = nx + j, cy = ny + i;
                if (cx < 0 || cx >= LATIME || cy >= LUNGIME) return 1;
                if (cy >= 0 && camp[cy][cx]) return 1;
            }
        }
    }
    return 0;
}

void noua_piesa() {
    tip_piesa = rand() % 7;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            piesa_activa[i][j] = piese_baza[tip_piesa][i][j];
    piesa_x = 3; piesa_y = 0;
    if (coliziune(piesa_x, piesa_y, piesa_activa)) {
        system("clear");
        // Resetăm terminalul la modul normal înainte de a ieși
        tcsetattr(0, TCSANOW, &orig_termios);
        printf(ROSU "\n GAME OVER!\n Scor: %d\n" RESET, scor);
        exit(0);
    }
}

void deseneaza() {
    mutaCursor(0, 0);
    printf(ALB " [SCOR: " VERDE "%d" ALB "] ", scor);
    if (scor >= 500) printf(MAGENTA "!! X - DISPONIBIL !!" RESET "\n");
    else printf(ALB "Pana la X: %d   " RESET "\n", 500 - scor);

    printf(CIAN " +----------+" RESET "\n");
    for (int i = 0; i < LUNGIME; i++) {
        printf(CIAN " |" RESET);
        for (int j = 0; j < LATIME; j++) {
            int p_aici = (i >= piesa_y && i < piesa_y + 4 && j >= piesa_x && j < piesa_x + 4 && piesa_activa[i-piesa_y][j-piesa_x]);
            if (camp[i][j]) printf(ALB "#" RESET);
            else if (p_aici) printf("%s@%s", culori_piese[tip_piesa], RESET);
            else printf(" ");
        }
        printf(CIAN "|" RESET "\n");
    }
    printf(CIAN " +----------+" RESET "\n");
}

void porneste_muzica() {
    // Caută direct fișierul în folderul curent și ascunde textul mplayer-ului
   system("cvlc --loop ./tetris_muzica.mp3 &");
}