#define NUM_OF_CHARS 2
#define NUM_OF_BITS 15
#define getBit(w, index) ((w)->bits[index / 8] >> (index % 8)) & 1
#define setBitOn(w, index) (w->bits[index / 8]) |= 1 << (index % 8)
#define setBitOff(w, index) (w->bits[index / 8]) &= ~(1 << (index % 8))

typedef struct asmWord{
    char bits[NUM_OF_CHARS];

} asmWord;

/**
 * This function will reset a given asmWord to zero.
 * @param w given asmWord to be resets.
 */
void resetWord(asmWord* w);

/**
 * Writes given decimal number to given asmWord in binary.
 * @param w given word
 * @param num the given number
 * @param index index to start the write
 * @return last index written
 */
int writeDecToWord(asmWord* w, int num, int index);

/**
 * returns the content of given word in octal base
 * @param w given word
 * @return octal representation of w
 */
int wordToOctal(asmWord* w);

/**
 * raise x by the power of y and returns the results
 * @param x x
 * @param y y
 * @return result of x by the power of y
 */
int myPow(int x, int y);
