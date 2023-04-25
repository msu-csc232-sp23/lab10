# Analyzing Algorithms with Code

This project demonstrates two concepts

1. Function objects in C++
1. An example of the Template Method design pattern.

Using these concepts we'll explore the runtime execution of some different algorithms.

The basis for this lab comes from Programming Problems 1A, 1B and 2B found in Chapter 10 of our textbook. These problems are repeated here for convenience.

## Problems

Problem 1: Consider the following two loops:

```c++
// Loop A
for (i = 1; i <= n; i++)
    for (j = 1; j <= 10000; j++)
        sum = sum + j;

// Loop B
for (i = 1; i <=  n; i++)
    for (j = 1; j <= n; j++)
        sum = sum + j;
```

What is the Big O of each loop? Design and implement an experiment to find a value of n for which Loop B is faster than Loop A.

Problem 2: Repeat the previous project, but use the following for Loop B:

```c++
for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
        for (k = 1; k <= j; k++)
            sum = sum + k;
```

## The Experiment

Please take a few moments to study the code found in [main.cpp](main.cpp). This code was written to facilitate an experiement called for by these programming problems.

### Template methods and Function Objects

We're going to utilize two concepts for timing algorithms. The first is through the use of a Template method declared in an Abstract class (named `TimedProcessor`) which declares a template method named `DoSomething(int n)`. We create three concrete realizations of this abstract class whose responsibility is to provide a definition of `DoSomething(int n)`. These three subclasses are

1. ProgrammingProblem1A -- the code from Loop 1A is already provided here
2. ProgrammingProblem2A -- you'll add the code for Loop 1B here
3. ProgrammingProblem2B -- you'll add the code for Loop 2B here

Since instances of these classes all have a public method named `timeToProcess(int n)`, we can pass these objects to the template function `template <typename Timer> FindTime(Time timer, int n)` which will invoke this public method and return its computed value. This return value is the time it takes to process its defined algorithm (as defined in `DoSomething`).

The first part of the `main` function uses these and can be used to find the answer to the programming problems.

As food for thought, and to expand your knowledge of C++, another class is provided to you named `Timer`. The cool thing about this class is that it overloads the `operator()(int n)` which in essence, allows you to "use" your objects like functions of one parameter -- these are referred to as "function objects." In our case, the `Timer` class also makes use of a template method, so it is abstract as well. To demonstrate these function objects in action then, we provide a concrete realization of the `Timer` class in `AKindOfTimer`.

Take the time to study the last few lines of the `main` function that utilize these function objects. This is a real cool way to (a) use objects as functions, and (b) provide different algorithm implementations in your function objects for a quick comparison of performance and memory requirements.

Finally, take note that we've provided two different template functions to work with implementations of the `TimedProcessor` and `Timer` abstract classes. The template function `FindTime` uses instances of `TimedProcessor` and the template function `FindTimeToProcess` uses instances of `Timer`.

## Submission Details

As usual, prior to submitting your assignment to Blackboard, be sure that you have committed and pushed your final changes to GitHub. If you have not done so already, create a **pull request** that seeks to merge your `develop` branch into your `trunk` branch.  Submit the URL of your assignment _repository_ (i.e., _not_ the URL of the pull request) as a Text Submission in Blackboard. Please note: the timestamp of the submission on Blackboard is used to assess any late penalties if and when warranted.

Finally, be sure that you **do not merge your pull request until it has been approved by one of the assigned reviewers**.

### Due Date

Your Blackboard submission is due by the end of your lab period.

### Grading Rubric

This assignment is worth **3 points**.

Criteria          | Exceeds Expectations         | Meets Expectations                  | Below Expectations                  | Failure                                                 |
------------------|------------------------------|-------------------------------------|-------------------------------------|---------------------------------------------------------|
Pull Request (20%)| Submitted early, correct url | Submitted on-time; correct url      | Incorrect URL                       | No pull request was created or submitted                |
Code Style (20%)  | Exemplary code style         | Consistent, modern coding style     | Inconsistent coding style           | No style whatsoever or no code changes present          |
Correctness^ (60%)| All unit tests pass          | At least 80% of the unit tests pass | At least 60% of the unit tests pass | Less than 50% of the unit tests pass                    |

^ _The Catch2 Test unit runner, if appropriate, will calculate the correctness points based purely on the fraction of tests passed_.

### Late Penalty

* In the first 24 hour period following the due date, this lab will be penalized 1 point meaning the grading starts at 4 (out of 5 total possible) points.
* In the second 24 hour period following the due date, this lab will be penalized 2 points meaning the grading starts at 3 (out of 5 total possible) points.
* After 48 hours, the assignment will not be graded and thus earns no points, i.e., 0 out of 5 possible points.

## Disclaimer & Fair Use Statement

This repository may contain copyrighted material, the use of which may not have been specifically authorized by the copyright owner. This material is available in an effort to explain issues relevant to the course or to illustrate the use and benefits of an educational tool. The material contained in this repository is distributed without profit for research and educational purposes. Only small portions of the original work are being used and those could not be used to easily duplicate the original work.

This constitute a 'fair use' of any such copyrighted material (referenced and provided for in section 107 of the US Copyright Law).

If you wish to use any copyrighted material from this repository for purposes that go beyond 'fair use', you must obtain expressed permission from the copyright owner.
