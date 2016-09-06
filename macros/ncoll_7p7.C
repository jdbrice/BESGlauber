

void ncoll_7p7( int nEvts = 1000, string ncp = "hNcollNpart.root" ){

	gSystem->Load("St_base");
	gSystem->Load("StUtilities");
	gSystem->Load("StGlauberUtilities");
	gSystem->Load("StCentralityMaker");

	StNegativeBinomial * nbd = new StNegativeBinomial( 0.89, 2.0, 0.12, 0.14, 1.0, 0 );
	StCentrality * cen = new StCentrality( "auau_7gev", "high");

	TFile * fcp = new TFile( ncp.c_str(), "READ" );

	TH2 * hNcNp = (TH2*)fcp->Get( "hNcoll_Npart" );

	TFile * fOut = new TFile( "sys.root", "RECREATE" );

	TH1D * hMult = new TH1D( "mult", "mult", 500, 0, 500 );
  	TH2D * hAvgNpart = new TH2D( "avgNpart", "<Npart>", 100, 0.5, 100.5, 500, 0, 500 );
  	TH2D * hAvgNcoll = new TH2D( "avgNcoll", "<Ncoll>", 100, 0.5, 100.5, 1500, -0.5, 1499.5 );


	Int_t iEvt = 0;
	while( iEvt < nEvts ){

    // get an Npart, Ncoll randomly
	Double_t npart, ncoll;
  	hNcNp->GetRandom2(npart, ncoll);
    const Bool_t isNpartNcollOk = (npart>=2 && ncoll>=1) ;
  	if ( !isNpartNcollOk ) continue;


  	int mult       = nbd->GetMultiplicity( npart, ncoll );
  	double avgCen  = cen->GetCentrality( mult, 1 );

  	hMult->Fill( mult );
		hAvgNpart->Fill( avgCen, npart );
		hAvgNcoll->Fill( avgCen, ncoll );


  	iEvt++;
	}


	fOut->Write();
  fOut->Close();

  delete nbd;
  delete cen;


}