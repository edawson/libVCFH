#include "vcfheader.hpp"

using namespace std;
using namespace vcfh;

void Header::set_reference(string ref_file){
    reference = ref_file;
}

void Header::set_date(){
    string d = make_date();
}

void Header::make_date(){
    time_t now = me(0);
}
