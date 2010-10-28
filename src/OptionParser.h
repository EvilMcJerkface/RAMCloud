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

#ifndef RAMCLOUD_OPTIONPARSER_H
#define RAMCLOUD_OPTIONPARSER_H

#include <boost/program_options.hpp>

#include "Common.h"
#include "Transport.h"

namespace RAMCloud {

/// See boost::program_options, just a synonym for that namespace.
namespace ProgramOptions {
    using namespace boost::program_options; // NOLINT
}
/// See boost::program_options::options_description, just a type synonym.
typedef ProgramOptions::options_description OptionsDescription;

/**
 * Parses command line options for RAMCloud applications.  It also allows
 * one to specify additional options that are program specific.
 *
 * Example use:
 * \code
 *  OptionsDescription telnetOptions("Telnet");
 *  telnetOptions.add_options()
 *      ("generate,g",
 *       ProgramOptions::bool_switch(&generate),
 *       "Continuously send random data")
 *      ("server,s",
 *       ProgramOptions::value<vector<string> >(&serverLocators),
 *       "Server locator of server, can be repeated to send to all");
 *
 *  OptionParser optionParser(telnetOptions, argc, argv);
 *
 *  if (!serverLocators.size()) {
 *      optionParser.usage();
 *      DIE("Error: No servers specified to telnet to.");
 *  }
 *  \endcode
 */
class OptionParser {
  public:
    OptionParser(int argc, char* argv[]);
    OptionParser(const OptionsDescription& appOptions,
                 int argc, char* argv[]);
    void usage() const;
    void usageAndExit() const;

    /// Holds values for generic RAMCloud options.  See #options.
    class Options {
      public:
        Options()
            : coordinatorLocator()
            , localLocator()
        {
        }

        /// Returns the local locator the application should listen on, if any.
        const string& getLocalLocator() const
        {
            return localLocator;
        }

        /**
         * Returns the locator the application should contact the coordinator
         * at, if any.
         */
        const string& getCoordinatorLocator() const
        {
            return coordinatorLocator;
        }

      private:
        string coordinatorLocator;      ///< See getLocalLocator().
        string localLocator;            ///< See getCoordinatorLocator().

        friend class OptionParser;
    };

    /// Values for options common to all RAMCloud applications.
    Options options;

  private:
    void setup(int argc, char* argv[]);

    /// The composition of appOptions and the RAMCloud common options.
    OptionsDescription allOptions;

    /// Additional application-specific options that should be parsed.
    const OptionsDescription appOptions;
};

} // end RAMCloud

#endif  // RAMCLOUD_OPTIONPARSER_H