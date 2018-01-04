#include <gtest/gtest.h>
#include "utScanner.h"
#include "utParser.h"
#include "utExp.h"
#include "exception.h"
#include "expression.h"

int main( int argc , char **argv )
{
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS( ) ;
}
