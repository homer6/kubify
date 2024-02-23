#include "KubifyApp.h"
#include <gtest/gtest.h>

TEST(KubifyAppTest, RunMethod) {
    kubify::KubifyApp app;
    EXPECT_EQ(app.run(), "KubifyApp is running!");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
