# BESGlauber
===
Glauber codes used for the STAR BES energies (and maybe others)
Original author : Hiroshi Masui
---

#### Macros
- All located in macros/
- **glauber_nominal.C** : Runs the FastGlauberMcMaker with the options that were nominal for BES
- **makeNCollNPartHistogram.C** : Takes the tree output by the FastGlauberMcMaker and makes a 2D histo of N\_coll vs. N\_part (used in other macros)



#### StRefMultCorr start to finish
1. Do study to find bad runs
2. Create Histograms of RefMult vs. vZ for your dataset. From now on all steps assume that bad runs are rejected)
3. Fit the max refmlut vs vZ to find corrections for vZ (out of scope of this code, also not implemented well for BES, simply used N degree polinomial)
4. Re-histogram the refmult for your dataset with the vZ corrections applied
5. Create 1D histograms of refmult in the center region of TPC ( -5 < vZ < 5 [cm] ) and outer region (maybe -35 < vZ < -25 [cm], depending on vS range for that dataset)
6. Run the nominal glauber version of the FastGlauberMcMaker to produce glauber trees
7. Make an hNCollNPart histogram for use in the NBD fitting
8. Fit the NBD using the nbdSweep.py and the doNbdFitMaker.c macros to find the best NBD fit parameters
9. Repeate the fit for the outer region 
10. Use analysis/mcGlauberFit.C to fit the centeral and outer glauber fits and extract the trigger correction parameters
11. Run systematics:
	1. Create a Glauber tree for each variation that you are checking on
	2. run `run_systematic.sh` (modified for the variations you chose)
12. Process the output sys\_${variation\_name}.root with the scripts in analysis/systematics/
	1. Run rgen.sh to generate tables for all of the systematics
