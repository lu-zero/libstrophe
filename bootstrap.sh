#!/bin/sh

set -e

echo "libstrophe autogen.sh..."
mkdir -p m4
UNAME=`uname -s`
if [ $UNAME = "Darwin" ]; then
glibtoolize --automake
else
libtoolize --automake
fi
ACLOCAL=`which aclocal-1.11 || which aclocal-1.10 || which aclocal-1.9 || which aclocal19 || which aclocal-1.7 || which aclocal17 || which aclocal-1.5 || which aclocal15`
${ACLOCAL:-aclocal} $ACLOCALFLAGS || exit 1
automake --add-missing --foreign --copy
autoconf
