#include "api/BamReader.h"
#include "api/BamWriter.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace BamTools;
using namespace std;
int main(int argc, char *argv[])
{
	const string splash="rgged        Alter or Add Read Group (RG) Information\n"
		       "\n---------------------------------------------------\n" 
			 " WARNING!     Existing Read Groups will be erased! "
		       "\n---------------------------------------------------\n" 
			  "\nVersion: 1.0	Author: Danny Antaki <dantaki@ucsd.edu>\n\n"
			    "Usage: rgged -i <in.bam> -id <ID> -lb <LIBRARY> -pl <PLATFORM> -sm <SAMPLE> >output.bam\n\nOptions:\n"
				"    -i        Input: BAM filename\n"
				"    -id       ID\n"
				"    -lb       Library\n"
				"    -pl       Platform\n"
				"    -sm       Sample\n\n";
	string ifh;
	string ID; string LB; string PL; string SM; 
	string ofh; string args=string(argv[0]);
	if ( (argc==1) ||
	     (argc==2 && string(argv[1]) == "-h") ||
	     (argc==2 && string(argv[1]) == "-help") ||
	     (argc==2 && string(argv[1]) == "--help")) {
		cout << "" << endl; cout << splash << endl;
		return 1;
	}
	for(int i=1; i<argc; ++i){
		if(string(argv[i]) == "-i" || string(argv[i]) == "--in" || string(argv[i]) == "-in"){ ifh = string(argv[i+1]); i++; continue; }
		if(string(argv[i]) == "-id" || string(argv[i]) == "--id" || string(argv[i])=="--ID" || string(argv[i])=="-ID"){ ID = string(argv[i+1]); i++; continue; }
		if(string(argv[i]) == "-lb" || string(argv[i]) == "--lb" || string(argv[i])=="--LB" || string(argv[i])=="-LB"){ LB = string(argv[i+1]); i++; continue; }
		if(string(argv[i]) == "-pl" || string(argv[i]) == "--pl" || string(argv[i])=="--PL" || string(argv[i])=="-PL"){ PL = string(argv[i+1]); i++; continue; }
		if(string(argv[i]) == "-sm" || string(argv[i]) == "--sm" || string(argv[i])=="--SM" || string(argv[i])=="-SM"){ SM = string(argv[i+1]); i++; continue; }
		cerr << "ERROR: Unknown option "<<string(argv[i])<< "\n\n"<< splash << endl;
		return 1;
	} for(int i=1; i<argc; ++i){ args=args+" "+argv[i]; }
	if(ifh == "") { cerr << "ERROR: No BAM file given\n\n"<< splash << endl; return 1; }
	if(ID == "" ) { cerr << "ERROR: No ID <-id [ID]>\n\n"<< splash << endl; return 1; } 
	BamReader reader; BamWriter out;
	if (!reader.Open(ifh)){ cerr << "ERROR: " << ifh << " could not be opened!\n\n"<< splash << endl; return 1; }
	BamAlignment al;
	const RefVector refs = reader.GetReferenceData();
	SamHeader head = reader.GetHeader();
	SamProgram rgged; rgged.CommandLine = args; rgged.ID="rgged";
	head.Programs.Add(rgged); 
	SamReadGroup myRG; myRG.ID=ID; if(SM=="") { SM=ID; myRG.Sample=SM;} 
	if(SM!="") { myRG.Sample=SM;}
	if(LB!="") { myRG.Library=LB;} 
	if(PL!="") { myRG.SequencingTechnology=PL;}
	SamReadGroupDictionary rg; rg.Add(myRG);
	head.ReadGroups=rg;
	out.SetCompressionMode(BamWriter::Uncompressed);
	if(!out.Open("stdout",head,refs)){ cerr << "ERROR: " << ofh << " could not be opened for writing\n\n"<< splash << endl; return 1; } 
	while (reader.GetNextAlignmentCore(al)){
		al.BuildCharData();
		if(al.HasTag("RG")) { al.RemoveTag("RG"); } 
		al.AddTag("RG","Z",ID);
		out.SaveAlignment(al);
	}
	reader.Close(); out.Close();
	return 0;
}
