#include "ReproReporter.h"
#include <catch2/reporters/catch_reporter_helpers.hpp>
#include <catch2/catch_test_case_info.hpp>
#include <catch2/internal/catch_move_and_forward.hpp>

#include <iostream>

ReproReporter::ReproReporter(Catch::ReporterConfig&& config) : CumulativeReporterBase(CATCH_MOVE(config))
{
}

void LogSectionNode(const Catch::CumulativeReporterBase::SectionNode& node, const std::string& prefix)
{
    std::cout << prefix << "Section: " << node.stats.sectionInfo.name <<
        " (child count: " << node.childSections.size() << " passed:" << node.stats.assertions.passed << " skipped:" << node.stats.assertions.skipped << ")\n";
    for(const auto& childSection : node.childSections)
    {
        LogSectionNode(*childSection, prefix + " ");
    }
}

void ReproReporter::testRunEndedCumulative()
{
    for (const auto& childNode : m_testRun->children)
    {
        std::cout << "test node: " << childNode->value.testInfo->name << '\n';
        for (const auto& childSection : childNode->children)
        {
            LogSectionNode(*childSection, " ");
        }
    }
}
