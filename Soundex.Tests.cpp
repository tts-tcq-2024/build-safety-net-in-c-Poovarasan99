#include <gtest/gtest.h>
#include "Soundex.h"

// Define a test fixture for easier setup/teardown if needed
class SoundexTestsuite : public ::testing::Test {
};

//test data for parameterized testing
using SoundexTestData = std::tuple<char*, char*>;

// test case with value-parameterized arguments
TEST_P(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
  // Get the parameters from the test data
  std::string input_string = std::get(GetParam());
  std::string expected_modified_string = std::get(GetParam());
  char* generatedSoundex[5];
  // Call the function to test
  generateSoundex(original_string, generatedSoundex);

  // Verify the expected result
  EXPECT_STREQ(generatedSoundex, expected_modified_string);
}

// Instantiate the test case with various data sets
INSTANTIATE_TEST_SUITE_P(TestParameters, SoundexTestsuite,
  testing::Values(
      std::make_tuple("AX","A200"),
      std::make_tuple("","000"),
      std::make_tuple("A","A000")
  )
);
