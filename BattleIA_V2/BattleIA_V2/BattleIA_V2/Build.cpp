#include "Build.hpp"
#include "Extractor.hpp"
#include "ExtractorU.hpp"


Build::Build() {
}


Build::~Build() {
}

Extractor<int>* buildIntExtractor(std::stringstream code) {
}

Extractor* buildFloatExtractor(std::stringstream code) {
    char c;
    code >> c;
    switch (c) {
    case 'U':
        return new ExtractorU();
    case 'L':
        code >> c;
        if (c >= '0' && c <= '6')
            return new ExtractorLCX(buildArmyExtractor(code), c - 0x30);
        else if (c == 'D') {
            Extractor<Army> * es = buildArmyExtractor(code);
            Extractor<Point> * ep = buildPointExtractor(code);

            return new ExtractorLD(es, ep);
        }
    case 'H':
        code >> c;
        if (c >= '0' && c <= '6')
            return new ExtractorHCX(buildArmyExtractor(code), c - 0x30);
        else if (c == 'D') {
            Extractor<Army> * es = buildArmyExtractor(code);
            Extractor<Point> * ep = buildPointExtractor(code);

            return new ExtractorHD(es, ep);
        }
    }
}

Extractor<Point>* buildPointExtractor(std::stringstream code) {
}

Extractor<Unit>* buildUnitExtractor(std::stringstream code) {
}

Extractor<Army>* buildArmyExtractor(std::stringstream code) {
}
