#pragma once
#include <catch2/reporters/catch_reporter_cumulative_base.hpp>
#include <catch2/reporters/catch_reporter_registrars.hpp>


// a new version of the catch2 junit reporter, that _doesn't_ flatten everything into one big flat list of tests    
class ReproReporter final : public Catch::CumulativeReporterBase
{
public:
    ReproReporter(Catch::ReporterConfig&& config);

    static std::string getDescription() {
        return "examining skip issue";
    }

    void testRunEndedCumulative() override;
};

CATCH_REGISTER_REPORTER("repro", ReproReporter)    

