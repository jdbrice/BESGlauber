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
5. Create 1D histograms of refmult in the center region of TPC ( -5 < vZ < 5 [cm] ) and outer region (maybe -70 < vZ < -60 [cm], depending on vS range for that dataset)
6. Run the nominal glauber version of the FastGlauberMcMaker to produce glauber trees
7. Make an hNCollNPart histogram for use in the NBD fitting
8. Fit the NBD using the nbdSweep.py and the doNbdFitMaker.c macros to find the best NBD fit parameters
