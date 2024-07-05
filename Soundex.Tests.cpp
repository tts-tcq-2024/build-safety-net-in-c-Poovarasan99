#include <gtest/gtest.h>
#include "Soundex.h"

// Define a test fixture for easier setup/teardown if needed
class SoundexTestsuite : public ::testing::TestWithParam<std::tuple<const char*, const char*>> {
};

// Test case with value-parameterized arguments
TEST_P(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
    // Get the parameters from the test data
    const char* input_string = std::get<0>(GetParam());
    const char* expected_soundex = std::get<1>(GetParam());
    char generatedSoundex[5]; // Array to hold generated Soundex code

    // Call the function to test
    generateSoundex(input_string, generatedSoundex);

    // Verify the expected result (character by character comparison)
    EXPECT_STREQ(generatedSoundex, expected_soundex);
}

// Instantiate the test case with various data sets
INSTANTIATE_TEST_SUITE_P(TestParameters, SoundexTestsuite,
    testing::Values(
        std::make_tuple("AX", "A200"),
        std::make_tuple("A", "A000"),
        std::make_tuple("Robert", "R163"),
        std::make_tuple("Ropert", "R163"),
        std::make_tuple("Rubin", "R150"),
        std::make_tuple("Ashcraft", "A261"),
        // std::make_tuple("", "000")
        // std::make_tuple("tymczak", "T522")
        // std::make_tuple("Pfister", "P236")
        // std::make_tuple("honeyman", "H555")
    )
);
