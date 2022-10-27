#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int pos1, pos2, value, reboots=0;
    char percent='%';
    int box[99];
    int people[99];
    srand(time(NULL));
    reboot:
    //Asignar números a las cajas
    for (pos1 = 0; pos1 < 100; pos1++) {
        value = rand() % 99 + 1;
        //Evitar números repetidos
        for (pos2 = 0; pos2 < pos1; pos2++) {
            if (value == box[pos2]) {
                value = rand() % 99 + 1;
                pos2 = 0;
            }
        }
        box[pos1] = value;
        printf("Box - %i: %i\n", pos1, value);
    }

        for (pos1 = 0, pos2=0; pos1 <= 99; pos1++, pos2=0) {
            value = box[pos1];
            printf("Value: %i", value);
            do {
                value = box[value];
                pos2++;
                printf("Box: %i, Value: %i!\n", box, value);
            } while (value != box[pos1]&&pos2<=50);
            if(pos2>50){
                printf("OOPS...");
                reboots++;
                goto reboot;
            }
            printf("POS: %i, Box: %i, Value: %i!\n", pos1, box, value);
        }
    printf("Done!\n-----\nReboots: %i", reboots);
}