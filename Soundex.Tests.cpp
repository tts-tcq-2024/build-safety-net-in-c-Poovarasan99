#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
  char* soundex;
  generateSoundex("AX", soundex);
  printf("%c%c%c%c%c\n",soundex[0],soundex[1],soundex[2],soundex[3],soundex[4]);
  ASSERT_EQ(soundex,"A200");
}
