#include "vcfheader.hpp"

using namespace std;
using namespace vcfh;

void Header::set_reference(string ref_file){
    reference = ref_file;
}

void Header::set_date(){
    string d = make_date();
    my_date = d;
}

string Header::make_date(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer [20];
    strftime(buffer, 20, "%G%e%d", ltm);
}

void Header::set_source(string s){
    my_source = s;
}

void Header::set_contig(string c){
    my_contig = c;
}

void Header::set_version(string v){
    ny_version = v;
}

void::Header::add_format(vcfh_format f){
    my_formats.push_back(f);
}

void Header::add_info(vcfh_info i){
    my_infos.push_back(i);
}

void Header::add_field(vcfh_field f){
    my_fields.push_back(f);
}

void Header::add_filter(vcfh_filter f){
    my_filters.push_back(f);
}

string to_string(){
    // print format (version), date, source and reference.
    string ret;
    ret = "##fileformat=" + my_version + "\n";
    ret += "##fileDate=" + my_date + "\n";
    ret += "##source=" + my_source + "\n";
    ret += "##reference=" + my_reference + "\n";
    ret += "##contig=" + my_contig + "\n";

    //print info fields
    

    // print filter fields
    
    //print format fields
}

ostream& operator<<(ostream& os, const Header& h){
    os << h.to_string(); 
    return os;
}
