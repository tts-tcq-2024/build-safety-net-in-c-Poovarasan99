#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

int compare_buffer(char input_char, char char_to_compare){
    int result = 0;
    if(input_char == char_to_compare){
        result = 1;
    }
    return result;
}

int is_char_in_array(char array[], int array_size, char input_char) {
    int search_result = 0;
    int i = 0;
    while(i<array_size && search_result == 0){
        search_result = compare_buffer(input_char,array[i]);
        i++;
    }
    return search_result;
}

char getSoundexCode(char c) {
    char code = 0;
    char SoundexCode[6][8] = { {'B','F','P','V'},{'C','G','J','K','Q','S','X','Z'},{'D','T'}, {'L'}, {'M','N'}, {'R'} };
    if(is_char_in_array(SoundexCode[i],sizeof(SoundexCode[i]),name[i])){
        code = i+1;
    }
    return code;
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;
    

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
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
