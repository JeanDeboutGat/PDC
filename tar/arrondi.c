#define BUFFER 512

long arrondi512(long n) {

    long nmodulo = n % BUFFER;

    if (nmodulo == 0) {
        return n;
    } else {
        return n + (BUFFER - nmodulo);
    }
}