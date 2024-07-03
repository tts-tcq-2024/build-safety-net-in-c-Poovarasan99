#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

// Function to compare two characters
int compare_characters(char input_char, char char_to_compare) {
    return (toupper(input_char) == toupper(char_to_compare)) ? 1 : 0;
}

// Function to check if a character is in an array
int is_char_in_array(char *array, char input_char) {
    int search_result = 0;
    int i = 0;
    while (array[i] != '\0' & search_result == 0) {
        search_result = compare_characters(input_char, array[i]);
        i++;
    }
    return search_result;
}

char getSoundexCode(char c) {
    char code = '0';
    char SoundexCode[6][9] = { {'B','F','P','V'}, {'C','G','J','K','Q','S','X','Z'}, {'D','T'}, {'L'}, {'M','N'}, {'R'} };
    char SoundexDigits[6] = {'1','2','3','4','5','6'};
    int index = 0;
    while(index < 6){
        if(is_char_in_array(SoundexCode[index],c)){
            code = SoundexDigits[index];
            break;
        }
        index++;
    }
    return code;
}

void attach_string(char* array_to_be_modified, char char_to_attach, int *index) {
    if ((char_to_attach != '0') && (char_to_attach != array_to_be_modified[*index - 1])) {
        array_to_be_modified[(*index)++] = char_to_attach;
    }
}

void add_padding(char soundex_array[], int index) {
    while (index < 4) {
        soundex_array[index++] = '0';
    }
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;
    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        attach_string(soundex, code, &sIndex);
    }
    add_padding(soundex, sIndex);
    soundex[4] = '\0';
}
#endif // SOUNDEX_H
