#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
  char soundex[5];
  generateSoundex("AX", soundex);
  printf("%c%c%c%%c\n",soundex[0],soundex[1],soundex[2],soundex[3]);
  ASSERT_EQ(soundex,"A200");
}
