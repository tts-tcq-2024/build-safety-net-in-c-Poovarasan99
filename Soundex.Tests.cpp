#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 char soundex[5];
 EXPECT_CALL(SoudexTestsuite, getSoundexCode('X').Times(1));
 generateSoundex("AX", soundex);
 ASSERT_EQ(soundex,"A200");
}
