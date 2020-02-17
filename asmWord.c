#include "asmWord.h"

/**
 * This function will reset a given asmWord to zero.
 * @param w given asmWord to be resets.
 */
void resetWord(asmWord* w){
    int i;
    for(i = 0; i < NUM_OF_CHARS; i++){
        w->bits[i] = 0;
    }
}

/**
 * Writes given decimal number to given asmWord in binary.
 * @param w given word
 * @param num the given number
 * @param index index to start the write
 * @return last index written
 */
int writeDecToWord(asmWord* w, int num, int index){
    if(num > 1){
        index = writeDecToWord(w, num / 2, index);
    }
    if(num % 2){
        setBitOn(w, index);
    }
    else{
        setBitOff(w, index);
    }
    return index-1;
}

/**
 * returns the content of given word in octal base
 * @param w given word
 * @return octal representation of w
 */
int wordToOctal(asmWord* w){
    int i, octal = 0;
    for(i = 0; i < 15; i += 3){
        octal += (getBit(w, i) + (getBit(w, i+1) * 2) + (getBit(w, i+2) * 2 * 2))
                * ((int) myPow(10, i / 3));
    }
    return octal;
}

/**
 * raise x by the power of y and returns the results
 * @param x x
 * @param y y
 * @return result of x by the power of y
 */
int myPow(int x, int y){
    int res = 1;
    for(y; y > 0; y--){
        res *= x;
    }
    return res;
}