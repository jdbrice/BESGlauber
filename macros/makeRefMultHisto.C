

void makeRefMultHisto( string fn = "/star/u/jdb/work/BESGlauber/data/Run14_AuAu_14p5/Run14_AuAu14p5_MultiRefMultCorr.root", string hName="C_refMultZ", string out_fn = "C_refmult_center.root", double vz_min = -5.0, double vz_max = 5.0 ) {
	
	TFile * fin = new TFile( fn.c_str() );
	TFile * fout = new TFile( out_fn.c_str(), "RECREATE" );

	TH2D * h2d = (TH2D*)fin->Get( hName.c_str() );
	if ( !h2d ){
		cout << "Can't find that histogram, bailing" << endl;
		return;
	}
	int b1 = h2d->GetXaxis()->FindBin( vz_min );
	int b2 = h2d->GetXaxis()->FindBin( vz_max );

	TH1D * h = h2d->ProjectionY( "hRefMult", b1, b2 );
	h->Write();
}