#include "MRQM/MRQM.hpp"
#include "gtest/gtest.h"
#include "json/json.h"

using namespace MRQM;

class TestConfiguration : public ::testing::Test
{
protected:
	void SetUp() override
	{
	}

	void TearDown() override
	{
	}

	// Public variable goes here
};

namespace MRQM
{
	TEST_F(TestConfiguration, Configuration1)
	{
	}

	TEST_F(TestConfiguration, Configuration2)
	{
	}
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
