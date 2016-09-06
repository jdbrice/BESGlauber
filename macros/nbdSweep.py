#!/bin/env python

import subprocess as sp
import os
from multiprocessing import Pool, Queue


def nbd( npp, k ) :
	cmd_template = """root4star -b -q 'macros/doNbdFitMaker.C("all_mb_fit_center_{npp}_{k}.root", 1000000, "all_mb.root", "hNCollNPart/hNCollNPart_nominal.root", "B_hRefMult_center", 50, {npp}, {k}, 0.12, 0.05, 1.0, 0 )'"""
	print cmd_template.format( npp=npp, k=k )
	os.system( cmd_template.format( npp=npp, k=k ) )
def rnbd( args ) :
	return nbd( *args )


if __name__ == '__main__':
	args = []

	i = 0
	for iNpp in xrange( 80, 120, 2 ) :
		npp = iNpp / 100.0
		for iK in xrange( 50, 350, 50 ) :
			k = iK / 100.0
			# nbd( npp, k )
			args.append( (npp, k) )

	p = Pool(4)
	p.map( rnbd, args )


