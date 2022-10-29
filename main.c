#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int pos1, pos2, pos3, value, oldvalue, reboots=0;
    int box[101];
    srand(time(NULL));
    for(pos3=0;pos3<=2;pos3++) {
        reboot:
        //Asignar números a las cajas
        box[0] = 0;
        for (pos1 = 1; pos1 <= 100; pos1++) {
            value = rand() % 100 + 1;
            //Evitar números repetidos
            for (pos2 = 1; pos2 <= pos1; pos2++) {
                if (value == box[pos2]) {
                    value = rand() % 100 + 1;
                    pos2 = 0;
                }
            }
            box[pos1] = value;
            printf("Box - %i: %i\n", pos1, value);
        }

        //Comenzamos el sorting
        for (pos1 = 1, pos2 = 0; pos1 < 100; pos1++, pos2 = 0) {
            // pos1: Indica la posición en el array (personas); pos2: El número de cajas abiertas*/
            value = pos1;
            printf("\n----\nPersona: %i\n----\n", value);
            do {
                oldvalue = value;
                value = box[value];
                pos2++;
                printf("Box: %i - Number: %i\n", oldvalue, value);
            } while (value != pos1 && pos2 <= 50);
            printf("Opened Boxes: %i\n", pos2);
            if (pos2 >= 51) {
                printf("OOPS...");
                reboots++;
                goto reboot;
            }
        }
        printf("Done!\n-----\nReboots: %i\n", reboots);
    }
}