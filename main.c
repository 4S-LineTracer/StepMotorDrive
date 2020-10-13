/*
 *
*/
#include "func.h"
#include "motorDrive.h"

int main(int argc, char const *argv[]) {
    printf("Hello, World\n");

    for (int i = 0; i < 10; i++) {
        motorDrive();
    }
    
    return 0;
}
