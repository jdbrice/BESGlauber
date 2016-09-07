## Run14 AuAu 14.5 GeV Centrality Definitions
##### September 7, 2016
===

## Period A
* Runs: < 15053000
* Bad BEMC calibration caused unusable vertex ranking
* Data should not be used for any analysis

### Period B
* Runs range: 15053001 -> 15057020
* Trigger: BBC\_MB || VPD\_MB ( 440015 || 440001 )

### Period C
* Runs range: 15057021 -> 15071021
* Trigger: BBC\_MB || VPD\_MB || ZDC\_MB ( 440015 || 440001 || 440004 )

##### Cuts
* |Vertex-Z| < 70 cm
* Vertex-R < 1 cm from ( 0, -0.89 )
* # of TOF Matched Tracks \>= 2  

Note : The centrality binning for the two periods (B, C) are the same, but the trigger bias corrections differ since the ZDC\_MB trigger is more efficient for peripheral events. The ZDC\_MB trigger was not elevated to physics ID until run 15057021 ( ie period C )


####Centrality Definitions:  
Please do not use the the following centrality cuts for your analysis. Use StRefMultCorr class, see instruction [How to use StRefMultCorr class ?](http://www.star.bnl.gov/protected/common/common2010/centrality/)

|Centrality | refMult cut   |
|-----------|:-------------:|
|	0-5%	|	238			|
|	5-10%	|	198			|
|	10-15%	|	165			|
|	15-20%	|	137			|
|	20-25%	|	112			|
|	25-30%	|	92			|
|	30-35%	|	74			|
|	35-40%	|	59			|
|	40-45%	|	46			|
|	45-50%	|	36			|
|	50-55%	|	27			|
|	55-60%	|	20			|
|	60-65%	|	15			|
|	65-70%	|	11			|
|	70-75%	|	7			|
|	75-80%	|	5			|
|			|				|

##### Centrality Def file
[Centrality_def_refmult.txt](http://www.star.bnl.gov/protected/lfspectra/jdb/run14/AuAu15/RefMultCorr/ALL_MB/www/Centrality_def_refmult.txt)

###Systematic Uncertainties

##### Participant Plane Area (fm^2)   
| [data table : Area(PP) (fm^2) ](http://www.star.bnl.gov/protected/lfspectra/jdb/run14/AuAu15/RefMultCorr/ALL_MB/www/tables/table_spp_vs_centrality_systematic_uncertainty.dat) | [Evaluation of syst. uncertainty](http://www.star.bnl.gov/protected/lfspectra/jdb/run14/AuAu15/RefMultCorr/ALL_MB/www/report/spp.pdf) |
|-------------------------------------------------|-------------------------------|  

| ![participant plane area systematics](report/spp_sysunc.png) |
|------------------------------------------|


##### Reaction Plane Area (fm^2)   
| [data table : Area(RP) (fm^2) ](http://www.star.bnl.gov/protected/lfspectra/jdb/run14/AuAu15/RefMultCorr/ALL_MB/www/tables/table_srp_vs_centrality_systematic_uncertainty.dat) | [Evaluation of syst. uncertainty](http://www.star.bnl.gov/protected/lfspectra/jdb/run14/AuAu15/RefMultCorr/ALL_MB/www/report/srp.pdf) |
|-------------------------------------------------|-------------------------------|  

| ![reaction plane systematics](report/srp_sysunc.png) |
|------------------------------------------|

##### Impact Parameter [fm]   
| [data table : Impact Parameter b \[fm\] ](http://www.star.bnl.gov/protected/lfspectra/jdb/run14/AuAu15/RefMultCorr/ALL_MB/www/tables/table_b_vs_centrality_systematic_uncertainty.dat) | [Evaluation of syst. uncertainty](http://www.star.bnl.gov/protected/lfspectra/jdb/run14/AuAu15/RefMultCorr/ALL_MB/www/report/b.pdf) |
|-------------------------------------------------|-------------------------------|  

| ![impact parameter systematics](report/b_sysunc.png) |
|------------------------------------------|

##### Number of Participants 
| [data table : Npart ](http://www.star.bnl.gov/protected/lfspectra/jdb/run14/AuAu15/RefMultCorr/ALL_MB/www/tables/table_avgNpart_vs_centrality_systematic_uncertainty.dat) | [Evaluation of syst. uncertainty](http://www.star.bnl.gov/protected/lfspectra/jdb/run14/AuAu15/RefMultCorr/ALL_MB/www/report/npart.pdf) |
|-------------------------------------------------|-------------------------------|  

| ![npart systematics](report/avgNpart_sysunc.png) |
|------------------------------------------|


##### Number of Collisions
| [data table : Ncoll ](http://www.star.bnl.gov/protected/lfspectra/jdb/run14/AuAu15/RefMultCorr/ALL_MB/www/tables/table_avgNcoll_vs_centrality_systematic_uncertainty.dat) | [Evaluation of syst. uncertainty](http://www.star.bnl.gov/protected/lfspectra/jdb/run14/AuAu15/RefMultCorr/ALL_MB/www/report/ncoll.pdf) |
|-------------------------------------------------|-------------------------------|  

| ![ncoll systematics](report/avgNcoll_sysunc.png) |
|------------------------------------------|




