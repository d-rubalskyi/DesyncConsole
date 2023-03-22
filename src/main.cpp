#include <cstdio>
#include <filesystem>

#include "Cluster.h"
#include "ComparisonResult.h"

int main()
{
    std::filesystem::path CurrentWorkingDirectory = std::filesystem::current_path();
    std::string SearchFolder = CurrentWorkingDirectory.string();

    Cluster NodeCluster;
    ComparisonResult Results;

    NodeCluster.LoadNodeData(SearchFolder);
    NodeCluster.CompareNodeData(Results);

    Results.Print();

    std::vector<MsgEntry> OutDesyncMsgs;
    std::vector<MsgEntry> OutUniqueDesyncMsgs;
    
    //Results.FilterByEntryName("EntryName", FilteredMsgs);

    Results.FilterByMsgType(MsgType::Desync, OutDesyncMsgs);
    Results.FilterUniqueMsgs(OutDesyncMsgs, OutUniqueDesyncMsgs);

    if (!OutUniqueDesyncMsgs.empty()) 
    {
        std::cout << std::endl << "Unique " << RedColor << "[Desync]"
            << WhiteColor << " entries:" << std::endl;

        for (auto const& Msg : OutUniqueDesyncMsgs)
        {
            std::cout << RedColor << "  [Desync]"
                << YellowColor << "Frame[" << Msg.FrameIdx << "]"
                << WhiteColor << Msg.Entry << std::endl;
        }
    }

    std::cout << std::endl << "Press Enter..." << std::endl;
    std::cin.ignore();

    return 0;
}
