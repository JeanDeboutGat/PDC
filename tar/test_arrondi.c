 #include <stdio.h>
 #include "arrondi.h"

 int main() {
    printf("arrondi(512) = %ld \n", arrondi512(512));
    printf("arrondi(513) = %ld \n", arrondi512(513));
    printf("arrondi(513) = %ld \n", arrondi512(1024));
    printf("arrondi(513) = %ld \n", arrondi512(1750));

    return 0;
 }