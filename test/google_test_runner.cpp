/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2020
 *
 * @file      google_test_runner.cpp
 * @authors   Jim Daehn <jdaehn@missouristate.edu>
 * @brief     Google Test implementation template.
 */

#include "csc232.h"
#include "gtest/gtest.h"

/**
 * @brief Namespace to encapsulate course specific macros, declarations and definitions.
 */
namespace csc232
{
    static int possiblePoints{ 0 };
    static int earnedPoints{ 0 };
    static const int MAX_CORRECTNESS_PTS{ 3 };

    /**
     * @brief Base test fixture that sets up grading for this assignment.
     */
    class CSC232BaseTestFixture : public ::testing::Test
    {
    protected:
        void SetUp() override
        {
            ::testing::FLAGS_gtest_death_test_style = "threadsafe";
            AdditionalSetup();
            possiblePoints += 1;
        }

        void TearDown() override
        {
            if (!HasFailure())
            {
                earnedPoints += 1;
            }
        }

        virtual void AdditionalSetup()
        {
            /* template method for any customized additional setup */
        }

        // Reusable objects for each unit test in this test fixture and any of its children
    };

    // Run me to test your PrintTable function
    class PrintTestFixture : public CSC232BaseTestFixture
    {
    private:
        void AdditionalSetup() override
        {
            ::testing::internal::CaptureStdout();
        }
    protected:
        // Reusable objects for each unit test in this test fixture
        std::string test{ "This is a test" };
    };

    TEST_F( PrintTestFixture, DISABLED_PrintTest )
    {
        // Given some function that prints to stdout
        std::cout << test;
        // Expect the following to be captured
        std::string expected{ test };
        std::string actual{ testing::internal::GetCapturedStdout() };
        EXPECT_EQ( expected, actual );
    }

    // Extend the base test fixture as needed for various components under test...
    class CSC232ChildClassTestFixture : public CSC232BaseTestFixture
    {
    protected:
        // Reusable objects for each unit test in this test fixture
    };

    TEST_F( CSC232ChildClassTestFixture, DISABLED_ValidateFailedAssertionTest )
    {
        EXPECT_DEATH( {
            assert( false ); // some line(s) of code that will cause a failed assertion
        }, ".*failed.*" );
    }
} // end namespace

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest( &argc, argv );
    int result{ RUN_ALL_TESTS() };
    std::cout << std::fixed << std::setprecision( 2 );
    std::cout << "\n\n";
    std::cout << std::left << std::setw( 21 ) << "Earned Points:"
              << std::right << std::setw( 5 ) << static_cast<double>(csc232::earnedPoints) << std::endl;
    std::cout << std::left << std::setw( 21 ) << "Possible Points:"
              << std::right << std::setw( 5 ) << static_cast<double>(csc232::possiblePoints) << std::endl;
    double percentCorrect{ static_cast<double>(csc232::earnedPoints) / csc232::possiblePoints };
    double correctnessPoints{ csc232::possiblePoints != 0 ? percentCorrect * csc232::MAX_CORRECTNESS_PTS
                                                          : 0 };
    std::cout << std::left << std::setw( 21 ) << "Correctness Points:"
              << std::right << std::setw( 5 ) << correctnessPoints << std::endl;
    return result;
}
