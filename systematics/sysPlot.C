
#include <sstream>
#include <string>

vector<double> values;
vector<double> unct;
vector<double> avgCent;

double binning[] =  {0, 5 , 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75 , 80 };

void readData( string var ){

	ifstream inf( ("tables/table_"+var+"_vs_centrality_systematic_uncertainty.dat").c_str() );
	
	cout << "File open : " << inf.good() << endl;
	string line;
	int i = 0;
	
	while( getline( inf, line ) ){

		double bin, ccl, cch, value, uncVal;
		stringstream ss( line );
		
		if ( !(ss >> bin >> ccl >> cch >> value >> uncVal) ) break;
		
		if ( 0 != value && bin <= 16){
			values.push_back( value );
			unct.push_back( uncVal );
			avgCent.push_back( (ccl+cch)/2.0  );
			//cout << line << endl;
			cout << value << "+/-" << uncVal << endl;
		}

		
		i++;
		
	}	

	inf.close();

}



void sysPlot( string var = "b", string title="<b>" ){

	gStyle->SetOptStat( 0 );
	TCanvas * c = new TCanvas( "c", "c", 500, 350 );

	readData( var );
	

	TH1D * hu = new TH1D( "unct", "unct", 16, binning );
	for ( int i = 0; i < values.size(); i++ ){
		hu->SetBinContent( i+1 , values[ i ] );
		hu->SetBinError( i+1 , unct[ i ] );
	}

	hu->SetTitle( ("  ; % Most Central; " + title).c_str() );
	hu->SetFillStyle( 1001 );
	hu->SetFillColor( kYellow );
	hu->SetMarkerStyle( 8  );
	hu->SetMarkerColor( kBlack );
	hu->Draw( "e5" );
	hu->Draw( "same hist p" );

	c->Print( ("report/"+var+"_sysunc.png").c_str() ); 
	
}