#include <gtest/gtest.h>
#include "Soundex.h"

// Define a test fixture for easier setup/teardown if needed
class SoundexTestsuite : public ::testing::Test {
};

// Test data for parameterized testing
using SoundexTestData = std::tuple<char*, char*>;

// Test case with value-parameterized arguments
TEST_P(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
  // Get the parameters from the test data
  char* input_string = std::get(GetParam());
  char* expected_soundex = std::get(GetParam());
  char generatedSoundex[5]; // Array to hold generated Soundex code

  // Call the function to test
  generateSoundex(input_string, generatedSoundex);

  // Verify the expected result (character by character comparison)
    EXPECT_STREQ(generatedSoundex[i], expected_soundex[i]);
}

// Instantiate the test case with various data sets
INSTANTIATE_TEST_SUITE_P(TestParameters, SoundexTestsuite,
  testing::Values(
    std::make_tuple("AX", "A200"),
    std::make_tuple("", "0000"),
    std::make_tuple("A", "A000")
  )
);
