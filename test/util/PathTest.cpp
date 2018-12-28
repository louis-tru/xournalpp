/*
 * Xournal++
 *
 * This file is part of the Xournal UnitTests
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#include <config-test.h>
#include <Path.h>

#include <cppunit/extensions/HelperMacros.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

class PathTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(PathTest);

	CPPUNIT_TEST(testUnsupportedUri);
	CPPUNIT_TEST(testPathFromUri);

	CPPUNIT_TEST_SUITE_END();

public:
	void setUp()
	{
	}

	void tearDown()
	{
	}

	void testUnsupportedUri()
	{
		Path b = Path::fromUri("http://localhost/test.txt");
		CPPUNIT_ASSERT_EQUAL(true, b.isEmpty());
	}

	void testPathFromUri()
	{
		Path b = Path::fromUri("file:///tmp/test.txt");
		CPPUNIT_ASSERT_EQUAL(false, b.isEmpty());
		CPPUNIT_ASSERT_EQUAL(string("/tmp/test.txt"), b.str());
	}
};

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(PathTest);