#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <ostream>

namespace vcfh{
    struct vcfh_info{

    };

    struct vcfh_format{

    };

    struct vcfh_filter{

    };

    struct vcfh_fields{
        const std::vector<std::string> set_fields;
        std::vector<std::string> opt_fields;
    };

    class Header{
        public:
            void set_reference(std::string ref_file);
            void set_date();
            std::string set_source();
            void set_contig(std::string contig);
            void add_info(vcfh_info info);
            void add_filter(vcfh_filter filter);
            void add_format(vcfh_format format);
            void add_field(std::string field);
            std::string to_string();
            friend std::ostream& operator<<(std::ostream& os, Header h);

        private:    
            std::string make_date();
            vcfh_fields header_fields;
            std::string reference;
            std::string date;
            std::string format;
            std::string contig;
            std::vector<vcfh_info> infos;
            std::vector<vcfh_format> formats;
            std::vector<vcfh_filter> filters;

    };
}
