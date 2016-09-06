

void makeNCollNPartHistogram( string fname = "glauber.root", string suffix = "" ){

	string title = "AuAu 15 GeV";

	TFile * f = new TFile( fname.c_str(), "READ" );
	TTree * t = (TTree*)f->Get( "tree" );

	TFile * fo = new TFile( ("hNCollNPart" + suffix + ".root").c_str(), "RECREATE" );

	TH2D * h2 = new TH2D ( "hNcoll_Npart", "nColl vs. nPart; nPart; nColl", 500, 0, 500, 1800, 0, 1800 );
	t->Draw( "ncoll:npart>>hNcoll_Npart" );

	fo->Write();
	fo->Close();


}