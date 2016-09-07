#include "extract.C"

const int nSources = 9;
string sources[] = { "nosmear", "large", "small", "lxs", "sxs", "low", "high", "mult1", "mult2", "deform", "gaus" };

int spacing = 15;


void gen( string var = "avgNcoll" ){
	
	ofstream outf( ("tables/table_"+var+"_vs_centrality_systematic_uncertainty.dat").c_str() );

	vector<double> nominal = extractValue( var );
	vector<double> unc[nSources];
	for ( int i = 0; i < nSources; i++ ){

		unc[ i ] = extractValue( var, ("data/sys_"+sources[ i ]+".root").c_str() );
	}

	vector<double> totUnc;

	for ( int i = 0; i < nBins; i++ ){
		double sum = 0;
		double dx = 0;
		for ( int j = 0; j < nSources; j++ ){
			dx = 0;
			dx = unc[ j ][ i ] - nominal[ i ];
			sum += dx*dx;
		}
		totUnc.push_back( TMath::Sqrt( sum ) );
	}

	// output the magic
	for ( int i = 0; i < nBins; i++ ){
		int ccl = cl[ i ];
		int cch = ch[ i ];
		
		outf << setw(spacing) << i << setw(spacing) << ccl << setw(spacing) << cch << setw(spacing) << nominal[ i ] << setw(spacing) << totUnc[ i] << endl;
	}

	outf << setw(spacing) << "bin" << setw(spacing) << "cen low" << setw(spacing) << "cen high" << setw(spacing) << "value" << setw(spacing) << "syst. unc" << endl;


	outf.close();

}