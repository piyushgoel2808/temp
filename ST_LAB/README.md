# ST_LAB JUnit 4 Programs (P1-P20)

## One-time project setup in NetBeans
1. Create a new Java Application project.
2. Right-click the project -> Properties -> Sources.
3. Add the source folder: New folder/ST_LAB/src
4. Add the test folder: New folder/ST_LAB/test
5. Ensure JUnit 4 is enabled: Right-click project -> Properties -> Libraries -> Add Library -> JUnit 4.
6. Clean and Build the project once.

## How to run each question (stepwise)

### P1 Traffic light logic
1. Open test class: stlab.p01.TrafficLightLogicTest
2. Right-click the test class -> Run Tests.
3. Verify all tests pass.
4. For radio-button application demo, run stlab.p01.TrafficLightUI as Java Application.

### P2 Method overloading
1. Open test class: stlab.p02.OverloadingTest
2. Right-click -> Run Tests.

### P3 Addition of two numbers (Arithmetic)
1. Open test class: stlab.p03.ArithmeticTest
2. Right-click -> Run Tests.
3. Note: There is an ignored failing test for lab documentation. Remove @Ignore to see a failing case.

### P4 Even or odd
1. Open test class: stlab.p04.EvenOddCheckerTest
2. Right-click -> Run Tests.

### P5 Palindrome
1. Open test class: stlab.p05.PalindromeCheckerTest
2. Right-click -> Run Tests.

### P6 Maximum of two numbers
1. Open test class: stlab.p06.MaxOfTwoTest
2. Right-click -> Run Tests.

### P7 Factorial
1. Open test class: stlab.p07.FactorialCalculatorTest
2. Right-click -> Run Tests.

### P8 Reverse string
1. Open test class: stlab.p08.ReverseUtilTest
2. Right-click -> Run Tests.

### P9 Simple interest
1. Open test class: stlab.p09.SimpleInterestCalculatorTest
2. Right-click -> Run Tests.

### P10 Login validation
1. Open test class: stlab.p10.LoginValidatorTest
2. Right-click -> Run Tests.

### P11 Registration form validation
1. Open test class: stlab.p11.RegistrationValidatorTest
2. Right-click -> Run Tests.

### P12 Additional sum() in Arithmetic with test
1. Open test class: stlab.p03.ArithmeticTest
2. Right-click -> Run Tests.
3. The sum(int,int,int) method is in stlab.p03.Arithmetic.
4. For failing and passing test demonstration, remove @Ignore in ArithmeticTest and run again.
5. Test case template is available at docs/P12_TestCaseTemplate.md

### P13 Product repository with test suite
1. Open suite: stlab.p13.ProductRepositoryTestSuite
2. Right-click -> Run Tests.

### P14 Parameterized addition tests
1. Open test class: stlab.p14.AdditionParameterizedTest
2. Right-click -> Run Tests.
3. Optional: run the main runner stlab.p14.AdditionTestRunner as Java Application.

### P15 Message utility
1. Open test class: stlab.p15.MessageUtilTest
2. Right-click -> Run Tests.
3. Optional: run the main runner stlab.p15.MessageUtilTestRunner as Java Application.

### P16 Assert class demonstration
1. Open test class: stlab.p16.AssertClassTest
2. Right-click -> Run Tests.
3. Optional: run the main runner stlab.p16.AssertClassTestRunner as Java Application.

### P17 Parameterized login tests
1. Open test class: stlab.p17.LoginServiceParameterizedTest
2. Right-click -> Run Tests.

### P18 Counter with TestRunner
1. Open test class: stlab.p18.CounterTest
2. Right-click -> Run Tests.
3. Optional: run the main runner stlab.p18.CounterTestRunner as Java Application.

### P19 Eligibility rules with suite
1. Open suite: stlab.p19.EligibilityTestSuite
2. Right-click -> Run Tests.

### P20 MyArray largest element
1. Open test class: stlab.p20.MyArrayTest
2. Right-click -> Run Tests.
3. For failing case demonstration, remove @Ignore in stlab.p20.MyArrayFailingTemplateTest and run tests.
4. Test case template is available at docs/P20_TestCaseTemplate.md
