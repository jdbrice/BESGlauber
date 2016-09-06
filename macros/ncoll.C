

void ncoll( int nEvts = 100000, string suffix = "_nominal", string ncp = "hNCollNPart" ){

	gSystem->Load("St_base");
	gSystem->Load("StUtilities");
	gSystem->Load("StGlauberUtilities");
	gSystem->Load("StCentralityMaker");

	StNegativeBinomial * nbd 	= new StNegativeBinomial( 1.172, 2.0, 0.12, 0.14, 1.0, 0 );
	StCentrality * cen 			= new StCentrality( "auau_14gev");

	// open the file containing the ncol vs. npart distribution
	TFile * fcp 		= new TFile( (ncp + suffix + ".root").c_str(), "READ" );

	// get the ncoll vs. npart histogram
	TH2 * hNcNp 		= (TH2*)fcp->Get( "hNcoll_Npart" );
	// open the output file
	TFile * fOut 		= new TFile( ("sys" + suffix +".root").c_str(), "RECREATE" );

	// Make histograms for storing the values of interest
	TH1D * hMult 		= new TH1D( "mult", "mult", 500, 0, 500 );
  	TH2D * hAvgNpart 	= new TH2D( "avgNpart", "<Npart>", 100, 0.5, 100.5, 500, 0, 500 );
  	TH2D * hAvgNcoll 	= new TH2D( "avgNcoll", "<Ncoll>", 100, 0.5, 100.5, 1500, -0.5, 1499.5 );

  	// generate events
	Int_t iEvt = 0;
	while( iEvt < nEvts ){

		

	    // get an Npart, Ncoll randomly
		Double_t npart, ncoll;
	  	hNcNp->GetRandom2(npart, ncoll);
	    const Bool_t isNpartNcollOk = (npart>=2 && ncoll>=1) ;
	  	if ( !isNpartNcollOk ) continue;


	  	int mult       = nbd->GetMultiplicity( npart, ncoll );
	  	double avgCen  = cen->GetCentrality( mult );

	  	hMult->Fill( mult );
		hAvgNpart->Fill( avgCen, npart );
		hAvgNcoll->Fill( avgCen, ncoll );

		if ( iEvt % 10000  ==0 ){
		cout << "." << flush;
		
		}
		//cout << iEvt << endl;

	  	iEvt++;
	}


	fOut->Write();
  	fOut->Close();

  	delete nbd;
  	delete cen;


}