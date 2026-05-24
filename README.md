# Tetris Game 

## 🎮 Regulile Oficiale ale Jocului Tetris pe Linux

Scopul jocului este să aranjezi piesele care cad în așa fel încât să creezi linii orizontale complete. Când o linie este completă, ea dispare și primești puncte și mai mult spațiu pentru a continua jocul. Jocul se termină atunci când piesele ajung în partea de sus a ecranului și nu mai ai unde să pui o piesă nouă.

### 1. Obiectivul și Zona de Joc

* Jocul se desfășoară într-o zonă verticală standard de **10 coloane și 20 de linii**.

* Trebuie să așezi piesele astfel încât să nu lași spații goale în liniile orizontale.

### 2. Controlul Pieselor cu Tastatura

Pentru a controla piesele în timp ce cad, folosește următoarele taste (asigură-te că tasta *Caps Lock* este oprită):

* **`a` (Stânga):** Mută piesa activă o căsuță spre stânga.

* **`d` (Dreapta):** Mută piesa activă o căsuță spre dreapta.

* **`s` (Jos / Soft Drop):** Fă piesa să cadă mai repede pentru a o pune unde ai nevoie.

* **`w` (Rotire):** Rotește piesa cu $90^\circ$ în sensul acelor de ceasornic pentru a o potrivi în spații strâmte.

* **`q` (Ieșire / Quit):** Închide imediat jocul și reviens la terminal.

### 3. Abilitatea Specială „X”

* La începutul jocului, această opțiune nu este disponibilă.

* Când atingi un scor de **500 de puncte**, pe ecran apare mesajul `!! X - DISPONIBIL !!`.

* Apasă **`x` (sau `X`)** pentru a folosi abilitatea specială: piesa curentă dispare și este înlocuită cu o piesă nouă, generată aleatoriu. Poți folosi această abilitate de câte ori vrei, atâta timp cât scorul tău este peste 500.

### 4. Sistemul de Punctaj

* **Eliminarea unei linii:** Când completezi o linie orizontală fără spații goale, acea linie dispare și primești **100 de puncte**.

* Liniile de deasupra celei eliminate coboară pentru a umple spațiul gol.

### 5. Sfârșitul Jocului

* Jocul se termină când piesele fixate anterior ajung atât de sus încât o piesă nouă nu mai are loc în partea de sus a ecranului.

* Atunci, ecranul se curăță și apare mesajul:

`GAME OVER! Scor final: [Scorul Tău]`
