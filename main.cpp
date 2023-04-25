#include <iomanip>
#include <iostream>
#include <ctime>

/**
 * @brief
 * @tparam Timer Any class that exposes the timeToProcess(int n) method
 * @param timer an instance of this class that shall have its timeToProcess method timed
 * @param n an upper bound for timing considerations
 * @return the time to process said function
 */
template <typename T>
double FindTime(T timer, int n)
{
    return timer.timeToProcess(n);
}

class TimedProcessor
{
public:
    double timeToProcess(int n)
    {
        clock_t start = clock();
        DoSomething(n);
        clock_t finish = clock();
        return static_cast<double>(finish - start) / CLOCKS_PER_SEC;
    }
protected:
    virtual void DoSomething(int n) = 0;
};

/**
 * @brief A concrete implementation of the TimedProcessor wherein DoSomething is defined
 *        by the code presented in Programming Problem 1A of Chapter 10 of our textbook 
 *        by Carrano & Henry.
 */
class ProgrammingProblem1A : public TimedProcessor
{
protected:
    void DoSomething(int n) override
    {
        int sum{0};
        for (int i{1}; i < n; ++i)
        {
            for (int j{1}; j < 10000; ++j)
            {
                sum += j;
            }
        }
    }
};

/**
 * @brief A concrete implementation of the TimedProcessor wherein DoSomething is defined
 *        by the code presented in Programming Problem 1B of Chapter 10 of our textbook 
 *        by Carrano & Henry.
 */
class ProgrammingProblem1B : public TimedProcessor
{
protected:
    void DoSomething(int n) override
    {
        // TODO: Implement me
    }
};

/**
 * @brief A concrete implementation of the TimedProcessor wherein DoSomething is defined 
 *        by the code presented in Programming Problem 2B of Chapter 10 of our textbook 
 *        by Carrano & Henry.
 */
class ProgrammingProblem2B : public TimedProcessor
{
protected:
    void DoSomething(int n) override
    {
        // Implement me
    }
};

/****************************************************************************************/

/**
 * @brief Demonstrate C++-style function objects
 */
class Timer
{
public:
        /**
         * @brief Provide ability for Timer objects to "act" like one-arg functions.
         * @param n an upper bound on things to do while function is timed
         * @return the time, in seconds, it takes to do something (defined by subclasses).
         */
        double operator()(int n) const
        {
            clock_t start = clock();
            DoSomething(n);
            clock_t finish = clock();
            return static_cast<double>(finish - start) / CLOCKS_PER_SEC;
        }
protected:
    virtual void DoSomething(int n) const = 0;
};
class AKindOfTimer : public Timer
{
protected:
    void DoSomething(int n) const override
    {
        int sum{0};
        for (int i{1}; i < n; ++i)
        {
            for (int j{1}; j < 10000; ++j)
            {
                sum += j;
            }
        }
    }
};

/**
 * @brief Template function used to find the time to process some action of a given function object.
 * @tparam Processor Any kind of function object that takes a single int argument
 * @param time_to_process a function object that takes a single int argument
 * @param n an upper bound for the function object to do its thing
 * @return the time (in seconds) it took the function object to do its thing
 */
template <typename Processor>
double FindTimeToProcess(Processor time_to_process, int n)
{
    return time_to_process(n);
}

int main()
{
    int n{100};
    std::cout << "Enter a value of n: ";
    std::cin >> n;

    ProgrammingProblem1A pp1a{};
    pp1a.timeToProcess(9);

    double time1A{ FindTime(pp1a, n)};
    double time1B{ FindTime(ProgrammingProblem1B{}, n)};
    double time2B{ FindTime(ProgrammingProblem2B{}, n)};

    std::cout << "Programming Problem 1A time (n = " << n << "): " << std::fixed << std::setprecision(9) << time1A << std::endl;
    std::cout << "Programming Problem 1B time (n = " << n << "): " << std::fixed << std::setprecision(9) << time1B << std::endl;
    std::cout << "Programming Problem 2B time (n = " << n << "): " << std::fixed << std::setprecision(9) << time2B << std::endl;

    AKindOfTimer timer{};
    double time_to_kill = timer(500); // notice how the object "acts" like a function... it's a "function object"
    double another_time{FindTimeToProcess(timer, n)};
    std::cout << "another_time                (n = " << n << "): " << another_time << std::endl;
    return 0;
}
