


param_template = """{year}  {energy}    {runmin}    {runmax}    {zmin}    {zmax}    {rm0}    {rm1}    {rm2}    {rm3}    {rm4}    {rm5}    {rm6}    {rm7}    {rm8}    {rm9}    {rm10}    {rm11}    {rm12}    {rm13}    {rm14}    {rm15}    {normstop}    {zpar0}    {zpar1}    {zpar2}    {zpar3}    {zpar4}    {zpar5}    {zpar6}    {zpar7}    {wpar0}    {wpar1}    {wpar2}    {wpar3}    {wpar4}    {wpar5}    {wpar6}    {wpar7}    {lpar0}    {lpar1}"""

with open( "Centrality_def_refmult_C.txt", "w" ) as f :
	
	data ={}
	data[ "year" ]   = "2014"
	data[ "energy" ] = "14.5"
	data[ "runmin" ] = "15057021"
	data[ "runmax" ] = "15072000"
	data[ "zmin" ]   = "-70"
	data[ "zmax" ]   = "70"
	data[ "rm0" ]   = "5"
	data[ "rm1" ]   = "7"
	data[ "rm2" ]   = "11"
	data[ "rm3" ]   = "15"
	data[ "rm4" ]   = "20"
	data[ "rm5" ]   = "27"
	data[ "rm6" ]   = "36"
	data[ "rm7" ]   = "46"
	data[ "rm8" ]   = "59"
	data[ "rm9" ]   = "74"
	data[ "rm10" ]  = "92"
	data[ "rm11" ]  = "112"
	data[ "rm12" ]  = "137"
	data[ "rm13" ]  = "165"
	data[ "rm14" ]  = "198"
	data[ "rm15" ]  = "238"

	data[ "normstop" ] = "30"
	data[ "zpar0" ] = "285.092"
	data[ "zpar1" ] = "0.02979"
	data[ "zpar2" ] = "0.0007589"
	data[ "zpar3" ] = "6.18761e-05"
	data[ "zpar4" ] = "-3.62925e-06"
	data[ "zpar5" ] = "-1.057426e-08"
	data[ "zpar6" ] = "7.33482e-10"
	data[ "zpar7" ] = "0"

	data[ "wpar0" ] = "5.94886e-01"
	data[ "wpar1" ] = "6.68545e+00"
	data[ "wpar2" ] = "1.30654e+00"
	data[ "wpar3" ] = "-7.85087e-01"
	data[ "wpar4" ] = "6.19815e-03"
	data[ "wpar5" ] = "5.73998e-05"
	data[ "wpar6" ] = "0"
	data[ "wpar7" ] = "0"

	data[ "lpar0" ] = "0"
	data[ "lpar1" ] = "0"
	f.write( param_template.format( year = data[ "year" ], energy = data[ "energy" ], runmin = data[ "runmin" ], runmax = data[ "runmax" ], zmin = data[ "zmin" ], zmax = data[ "zmax" ], rm0 = data[ "rm0" ], rm1 = data[ "rm1" ], rm2 = data[ "rm2" ], rm3 = data[ "rm3" ], rm4 = data[ "rm4" ], rm5 = data[ "rm5" ], rm6 = data[ "rm6" ], rm7 = data[ "rm7" ], rm8 = data[ "rm8" ], rm9 = data[ "rm9" ], rm10 = data[ "rm10" ], rm11 = data[ "rm11" ], rm12 = data[ "rm12" ], rm13 = data[ "rm13" ], rm14 = data[ "rm14" ], rm15 = data[ "rm15" ], normstop = data[ "normstop" ], zpar0 = data[ "zpar0" ], zpar1 = data[ "zpar1" ], zpar2 = data[ "zpar2" ], zpar3 = data[ "zpar3" ], zpar4 = data[ "zpar4" ], zpar5 = data[ "zpar5" ], zpar6 = data[ "zpar6" ], zpar7 = data[ "zpar7" ], wpar0 = data[ "wpar0" ], wpar1 = data[ "wpar1" ], wpar2 = data[ "wpar2" ], wpar3 = data[ "wpar3" ], wpar4 = data[ "wpar4" ], wpar5 = data[ "wpar5" ], wpar6 = data[ "wpar6" ], wpar7 = data[ "wpar7" ], lpar0 = data[ "lpar0" ], lpar1 = data[ "lpar1" ] ) )