#include <iostream>
#include <vector>

struct Process
{
    int pid;
    int size;
    int allocatedBlock;
};

void worstFitAllocation(std::vector<int> &blocks, std::vector<Process> &processes)
{
    for (int i = 0; i < processes.size(); i++)
    {
        int worstFitIndex = -1;
        for (int j = 0; j < blocks.size(); j++)
        {
            if (blocks[j] >= processes[i].size)
            {
                if (worstFitIndex == -1 || blocks[j] > blocks[worstFitIndex])
                {
                    worstFitIndex = j;
                }
            }
        }
        if (worstFitIndex != -1)
        {
            processes[i].allocatedBlock = worstFitIndex;
            blocks[worstFitIndex] -= processes[i].size;
        }
    }
}

int main()
{
    int numBlocks, numProcesses;
    std::cout << "Enter the number of memory blocks: ";
    std::cin >> numBlocks;
    std::cout << "Enter the number of processes: ";
    std::cin >> numProcesses;

    std::vector<int> blocks(numBlocks);
    std::vector<Process> processes(numProcesses);

    std::cout << "Enter the size of each memory block:\n";
    for (int i = 0; i < numBlocks; i++)
    {
        std::cin >> blocks[i];
    }

    std::cout << "Enter the size of each process:\n";
    for (int i = 0; i < numProcesses; i++)
    {
        processes[i].pid = i + 1;
        std::cin >> processes[i].size;
    }

    worstFitAllocation(blocks, processes);

    std::cout << "Process\tAllocated Block\n";
    for (const auto &process : processes)
    {
        std::cout << process.pid << "\t";
        if (process.allocatedBlock != -1)
        {
            std::cout << process.allocatedBlock + 1;
        }
        else
        {
            std::cout << "Not allocated";
        }
        std::cout << "\n";
    }

    return 0;
}