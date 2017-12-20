#!/bin/bash

cd $(dirname $(readlink -f $0))

if [ "$1" = "-out=xml" ]; then
  mkdir -p ../../build/report/cppcheck
  cd ../../build/report/cppcheck
  cppcheck --enable=warning --xml-version=2 ../../../src ../../../examples 2> cppcheck.xml
  cppcheck-htmlreport --file=cppcheck.xml --report-dir=./ --source-dir=../../../src ../../../examples
fi

if [ "$1" = "-out=gcc" ]; then
  cppcheck --enable=warning --template=gcc ../../src ../../examples
fi

