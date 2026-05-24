#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // Pentru usleep
#include "hs_utils.h"

int main() {
    // Inițializăm terminalul Linux pentru input asincron (fără enter)
    set_conio_terminal_mode();
    
    srand((unsigned int)time(NULL));
    system("clear"); 

    porneste_muzica();
    noua_piesa();

    int frame = 0;
    while (1) {
        // Folosim kbhit() și getch() făcute de noi, fără caracterul '_' în față
        if (kbhit()) {
            char c = getch();
            if (c == 'a' && !coliziune(piesa_x - 1, piesa_y, piesa_activa)) piesa_x--;
            if (c == 'd' && !coliziune(piesa_x + 1, piesa_y, piesa_activa)) piesa_x++;
            if (c == 's' && !coliziune(piesa_x, piesa_y + 1, piesa_activa)) piesa_y++;
            if (c == 'w') {
                char temp[4][4] = {0};
                for(int i=0; i<4; i++) for(int j=0; j<4; j++) temp[j][3-i] = piesa_activa[i][j];
                if(!coliziune(piesa_x, piesa_y, temp)) 
                    for(int i=0; i<4; i++) for(int j=0; j<4; j++) piesa_activa[i][j] = temp[i][j];
            }
            if ((c == 'x' || c == 'X') && scor >= 500) noua_piesa();
            if (c == 'q') break;
        }

        if (++frame > 10) {
            if (!coliziune(piesa_x, piesa_y + 1, piesa_activa)) piesa_y++;
            else {
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                        if (piesa_activa[i][j]) camp[piesa_y + i][piesa_x + j] = 1;
                
                for (int i = LUNGIME - 1; i >= 0; i--) {
                    int plina = 1;
                    for (int j = 0; j < LATIME; j++) if (!camp[i][j]) plina = 0;
                    if (plina) {
                        scor += 100;
                        for (int k = i; k > 0; k--)
                            for (int l = 0; l < LATIME; l++) camp[k][l] = camp[k-1][l];
                        i++;
                    }
                }
                noua_piesa();
            }
            frame = 0;
        }
        deseneaza();
        
        // 40 de milisecunde = 40000 de microsecunde
        usleep(40000); 
    }
    return 0;
}