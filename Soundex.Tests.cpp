#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigitsCase1) {
 char soundex[5];
 generateSoundex("AX", soundex);
 ASSERT_EQ(soundex,"A200");
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigitsCase2) {
 char soundex[5];
 generateSoundex("AEIOU", soundex);
 ASSERT_EQ(soundex,"A000");
}
