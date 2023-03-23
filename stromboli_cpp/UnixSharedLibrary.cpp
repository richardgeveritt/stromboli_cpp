/**
 * libhmsbeagle plugin system
 * @author Aaron E. Darling
 * Based on code found in "Dynamic Plugins for C++" by Arthur J. Musgrove
 * and published in Dr. Dobbs Journal, July 1, 2004.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "platform.h"

#ifdef HAVE_LIBLTDL
#include "LibtoolSharedLibrary.h"
#else
#include "UnixSharedLibrary.h"
#endif

#include <string>

namespace beagle {
namespace plugin {

SharedLibrary* SharedLibrary::openSharedLibrary(const char* name)
{
    return new UnixSharedLibrary(name);
}

}
}
