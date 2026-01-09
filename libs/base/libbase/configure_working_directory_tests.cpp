#include "configure_working_directory.h"

#include <gtest/gtest.h>

#include <filesystem>

TEST(configureWorkingDirectory, ensureCanFindImage) {
    configureWorkingDirectory();
    EXPECT_TRUE(std::filesystem::is_regular_file("data/00_photo_six_parts.jpg"));
}
