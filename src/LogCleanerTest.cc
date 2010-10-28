/* Copyright (c) 2010 Stanford University
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR(S) DISCLAIM ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL AUTHORS BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

// RAMCloud pragma [GCCWARN=5]

#include "TestUtil.h"

#include "Segment.h"
#include "Log.h"
#include "LogTypes.h"

namespace RAMCloud {

/**
 * Unit tests for Log.
 */
class LogCleanerTest : public CppUnit::TestFixture {

    DISALLOW_COPY_AND_ASSIGN(LogCleanerTest); // NOLINT

    CPPUNIT_TEST_SUITE(LogCleanerTest);
    CPPUNIT_TEST(test_constructor);
    CPPUNIT_TEST_SUITE_END();

  public:
    LogCleanerTest() {}

    void
    test_constructor()
    {
    }
};
CPPUNIT_TEST_SUITE_REGISTRATION(LogCleanerTest);

} // namespace RAMCloud