#!/bin/sh

mkdir -p m4
UNAME=`uname -s`
if [ $UNAME = "Darwin" ]; then
glibtoolize --automake
else
libtoolize --automake
fi
aclocal
automake --add-missing --foreign --copy
autoconf
