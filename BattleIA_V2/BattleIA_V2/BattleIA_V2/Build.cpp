#include "Build.hpp"

#include "Extractor.hpp"

#include "ExtractorU.hpp"
#include "ExtractorD.hpp"
#include "ExtractorB.hpp"

#include "ExtractorCX.hpp"

#include "ExtractorLCX.hpp"
#include "ExtractorLD.hpp"

#include "ExtractorHCX.hpp"
#include "ExtractorHD.hpp"


Build::Build() {
}


Build::~Build() {
}

Extractor<int>* buildIntExtractor(std::stringstream code) {
}

Extractor<float>* buildFloatExtractor(std::stringstream code) {
    char c;
    code >> c;
    switch (c) {
    case 'C':
        code >> c;
        if (c >= '0' && c <= '6')
            return new ExtractorCX(buildUnitExtractor(code), c - 0x30);
    case 'D':
        return new ExtractorD(buildPointExtractor(code));
    case 'M':
        code >> c;
        if (c >= '0' && c <= '6')
            return new ExtractorMaxCX(buildArmyExtractor(code), c - 0x30);
        else if (c == 'D') {
            Extractor<Army> * ea = buildArmyExtractor(code);
            Extractor<Point> * ep = buildPointExtractor(code);

            return new ExtractorMaxD(ea, ep);
        }
    case 'm':
        code >> c;
        if (c >= '0' && c <= '6')
            return new ExtractorMinCX(buildArmyExtractor(code), c - 0x30);
        else if (c == 'D') {
            Extractor<Army> * es = buildArmyExtractor(code);
            Extractor<Point> * ep = buildPointExtractor(code);

            return new ExtractorMinD(es, ep);
        }
    case 'a':
        code >> c;
        if (c >= '0' && c <= '6')
            return new ExtractorACX(buildArmyExtractor(code), c - 0x30);
        else if (c == 'D') {
            Extractor<Army> * es = buildArmyExtractor(code);
            Extractor<Point> * ep = buildPointExtractor(code);

            return new ExtractorAD(es, ep);
        }
    }
}

Extractor<Point>* buildPointExtractor(std::stringstream code) {
    char c;
    code >> c;
    switch (c) {
    case 'B':
        return new ExtractorB(buildArmyExtractor(code));
    case 'P':
        return new ExtractorP(buildUnitExtractor(code));
    }
}

Extractor<Unit>* buildUnitExtractor(std::stringstream code) {
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

Extractor<Army>* buildArmyExtractor(std::stringstream code) {
}
