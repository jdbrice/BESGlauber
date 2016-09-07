

void profile( string fn = "nominal" ){
	

	TFile * f = new TFile( ("data/sys_"+fn+".root").c_str(), "READ" );

	TFile* fo = new TFile( "data/profiles.root", "UPDATE" );

	TH2D * hc = (TH2D*) f->Get( "avgNcoll" );
	TH2D * hp = (TH2D*) f->Get( "avgNpart" );
	TH2D * hb = (TH2D*) f->Get( "b" );
	TH2D * hspp = (TH2D*) f->Get( "spp" );
	TH2D * hsrp = (TH2D*) f->Get( "srp" );

	TProfile * hpc = hc->ProfileX( ("ncoll_"+fn).c_str() );
	hpc->SetTitle( "<Ncoll>;% Most Central; <Ncoll>" );
	TProfile * hpp = hp->ProfileX( ("npart_"+fn).c_str() );
	hpp->SetTitle( "<Npart>;% Most Central; <Npart>" );
	TProfile * hpb = hb->ProfileX( ("b_"+fn).c_str() );
	hpb->SetTitle( "<b>;% Most Central; <b>" );

	TProfile * hpspp = hspp->ProfileX( ("spp_"+fn).c_str() );
	hpspp->SetTitle( "<S_{PP}> (fm^{2}) ;% Most Central; <S_{PP}>" );

	TProfile * hpsrp = hsrp->ProfileX( ("srp_"+fn).c_str() );
	hpsrp->SetTitle( "<S_{RP}> (fm^{2}) ;% Most Central; <S_{RP}>" );


	fo->Write();
	fo->Close();

	f->Close();
}