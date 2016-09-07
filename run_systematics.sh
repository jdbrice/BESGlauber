#!/bin/bash

root4star -b -q 'macros/systematics.C( 500000, "nosmear" )'
root4star -b -q 'macros/systematics.C( 500000, "deform" )'
root4star -b -q 'macros/systematics.C( 500000, "large" )'
root4star -b -q 'macros/systematics.C( 500000, "small" )'
root4star -b -q 'macros/systematics.C( 500000, "lxs" )'
root4star -b -q 'macros/systematics.C( 500000, "sxs" )'
root4star -b -q 'macros/systematics.C( 500000, "gauss" )'
root4star -b -q 'macros/systematics.C( 500000, "nominal" )'
root4star -b -q 'macros/systematics.C( 500000, "low", "low" )'
root4star -b -q 'macros/systematics.C( 500000, "high", "high" )'
root4star -b -q 'macros/systematics.C( 500000, "mult1", "default", 1 )'
root4star -b -q 'macros/systematics.C( 500000, "mult2", "default", 2 )'