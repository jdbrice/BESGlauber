#!/bin/env python

import subprocess as sp
import os
from multiprocessing import Pool, Queue
import numpy as np


def nbd( npp, k ) :
	cmd_template = """root4star -b -q 'macros/doNbdFitMaker.C("all_mb_fit_center_{npp}_{k}.root", 1000000, "/star/u/jdb/work/BESGlauber/data/Run14_AuAu_14p5/period_C_refmult_center.root", "/star/u/jdb/work/BESGlauber/data/Run14_AuAu_14p5/hNCollNPart_nominal.root", "hRefMult", 30, {npp}, {k}, 0.12, 0.14, 1.0, 0 )'"""
	print cmd_template.format( npp=npp, k=k )
	os.system( cmd_template.format( npp=npp, k=k ) )
def rnbd( args ) :
	return nbd( *args )


if __name__ == '__main__':
	args = []

	i = 0
	for npp in np.arange( 1.14, 1.8, 0.015 ) :
		for k in np.arange( 1.75, 2.5, .25 ) :
			args.append( (npp, k) )

	p = Pool(4)
	p.map( rnbd, args )


