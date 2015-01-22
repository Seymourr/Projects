/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ErrorPrinter.h>

int main() {
 return CxxTest::ErrorPrinter().run();
}
#include "testfall.cpp"

static MatrixTestSuite suite_MatrixTestSuite;

static CxxTest::List Tests_MatrixTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MatrixTestSuite( "testfall.cpp", 9, "MatrixTestSuite", suite_MatrixTestSuite, Tests_MatrixTestSuite );

static class TestDescription_MatrixTestSuite_testCreation : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_testCreation() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 72, "testCreation" ) {}
 void runTest() { suite_MatrixTestSuite.testCreation(); }
} testDescription_MatrixTestSuite_testCreation;

static class TestDescription_MatrixTestSuite_testAccess : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_testAccess() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 133, "testAccess" ) {}
 void runTest() { suite_MatrixTestSuite.testAccess(); }
} testDescription_MatrixTestSuite_testAccess;

static class TestDescription_MatrixTestSuite_testFailAccess : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_testFailAccess() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 154, "testFailAccess" ) {}
 void runTest() { suite_MatrixTestSuite.testFailAccess(); }
} testDescription_MatrixTestSuite_testFailAccess;

static class TestDescription_MatrixTestSuite_testAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_testAssignment() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 178, "testAssignment" ) {}
 void runTest() { suite_MatrixTestSuite.testAssignment(); }
} testDescription_MatrixTestSuite_testAssignment;

static class TestDescription_MatrixTestSuite_testMatrixAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_testMatrixAddition() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 214, "testMatrixAddition" ) {}
 void runTest() { suite_MatrixTestSuite.testMatrixAddition(); }
} testDescription_MatrixTestSuite_testMatrixAddition;

static class TestDescription_MatrixTestSuite_testMatrixSubstraction : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_testMatrixSubstraction() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 249, "testMatrixSubstraction" ) {}
 void runTest() { suite_MatrixTestSuite.testMatrixSubstraction(); }
} testDescription_MatrixTestSuite_testMatrixSubstraction;

static class TestDescription_MatrixTestSuite_testMatrixMult : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_testMatrixMult() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 292, "testMatrixMult" ) {}
 void runTest() { suite_MatrixTestSuite.testMatrixMult(); }
} testDescription_MatrixTestSuite_testMatrixMult;

static class TestDescription_MatrixTestSuite_testScalarMult : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_testScalarMult() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 348, "testScalarMult" ) {}
 void runTest() { suite_MatrixTestSuite.testScalarMult(); }
} testDescription_MatrixTestSuite_testScalarMult;

static class TestDescription_MatrixTestSuite_testNegation : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_testNegation() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 385, "testNegation" ) {}
 void runTest() { suite_MatrixTestSuite.testNegation(); }
} testDescription_MatrixTestSuite_testNegation;

static class TestDescription_MatrixTestSuite_testTransposition : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_testTransposition() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 402, "testTransposition" ) {}
 void runTest() { suite_MatrixTestSuite.testTransposition(); }
} testDescription_MatrixTestSuite_testTransposition;

static class TestDescription_MatrixTestSuite_testIdentity : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_testIdentity() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 452, "testIdentity" ) {}
 void runTest() { suite_MatrixTestSuite.testIdentity(); }
} testDescription_MatrixTestSuite_testIdentity;

static class TestDescription_MatrixTestSuite_testStreams : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_testStreams() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 483, "testStreams" ) {}
 void runTest() { suite_MatrixTestSuite.testStreams(); }
} testDescription_MatrixTestSuite_testStreams;

static class TestDescription_MatrixTestSuite_testFails : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_testFails() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 549, "testFails" ) {}
 void runTest() { suite_MatrixTestSuite.testFails(); }
} testDescription_MatrixTestSuite_testFails;

#include <cxxtest/Root.cpp>
