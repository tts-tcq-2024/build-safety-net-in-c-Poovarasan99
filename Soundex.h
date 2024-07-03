#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

int is_char_in_array(char array[], int array_size, char input_char) {
    int search_result = 0;
    // int i = 0;
    // while(i<array_size && search_result == 0){
    //     search_result = compare_buffer(input_char,array[i]);
    //     i++;
    // }
    for (int i = 0; i < array_size; i++) {
        if (input_char==array[i]){
        // search_result = compare_buffer(input_char,array[i]);
        search_result = 1;
        }
    }
    return search_result;
}

// char getSoundexCode(char c) {
//     c = toupper(c);
//     switch (c) {
//         case 'B': case 'F': case 'P': case 'V': return '1';
//         case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
//         case 'D': case 'T': return '3';
//         case 'L': return '4';
//         case 'M': case 'N': return '5';
//         case 'R': return '6';
//         default: return '0'; // For A, E, I, O, U, H, W, Y
//     }
// }

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;
    char SoundexCode[5][8] = { {'B','F','P','V'},{'C','G','J','K','Q','S','X','Z'},{'D','T'}, {'L'}, {'M','N'}, {'R'} };

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = is_char_in_array(SoundexCode[i],sizeof(SoundexCode[i]),name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
