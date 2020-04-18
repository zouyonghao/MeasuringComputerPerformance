#include <iostream>
#include <fstream>
#include "pin.H"
#include "BranchPredictor.cpp"
using std::cerr;
using std::endl;
using std::ios;
using std::ofstream;
using std::string;
ofstream OutFile;

static UINT64 directionMispredictedCount = 0;
static UINT64 targetMispredictedCount = 0;
static UINT64 allBranchCount = 0;

BranchPredictor myBPU;

VOID ProcessBranch(ADDRINT PC, ADDRINT targetPC, bool BrTaken)
{
    BP_Info pred = myBPU.GetPrediction(PC);

    // std::cout << pred.Taken << ", " << pred.takenCount << std::endl;

    if (pred.Taken != BrTaken)
    {
        // Direction Mispredicted
        directionMispredictedCount++;
    }
    if (pred.predTarget != targetPC)
    {
        // Target Mispredicted
        targetMispredictedCount++;
    }

    allBranchCount++;

    myBPU.Update(PC, BrTaken, targetPC);
}

// Pin calls this function every time a new instruction is encountered
VOID Instruction(INS ins, VOID *v)
{
    if (INS_IsBranch(ins) && INS_HasFallThrough(ins))
    {
        INS_InsertCall(ins,
                       IPOINT_BEFORE,
                       (AFUNPTR)ProcessBranch,
                       IARG_ADDRINT,
                       INS_Address(ins),
                       IARG_ADDRINT,
                       INS_DirectControlFlowTargetAddress(ins),
                       IARG_BRANCH_TAKEN,
                       IARG_END);
    }
}

KNOB<string> KnobOutputFile(KNOB_MODE_WRITEONCE, "pintool",
                            "o", "inscount.out", "specify output file name");
// This function is called when the application exits
VOID Fini(INT32 code, VOID *v)
{
    // Write to a file since cout and cerr maybe closed by the application
    OutFile.setf(ios::showbase);
    OutFile << "Direction Mispredicted " << directionMispredictedCount << endl;
    OutFile << "Target Mispredicted " << targetMispredictedCount << endl;
    OutFile << "All Branch Count " << allBranchCount << endl;
    OutFile.close();
}

/* ===================================================================== */
/* Print Help Message                                                    */
/* ===================================================================== */
INT32 Usage()
{
    cerr << "This tool counts the number of dynamic instructions executed" << endl;
    cerr << endl
         << KNOB_BASE::StringKnobSummary() << endl;
    return -1;
}
/* ===================================================================== */
/* Main                                                                  */
/* ===================================================================== */
/*   argc, argv are the entire command line: pin -t <toolname> -- ...    */
/* ===================================================================== */
int main(int argc, char *argv[])
{
    // Initialize pin
    if (PIN_Init(argc, argv))
        return Usage();
    OutFile.open(KnobOutputFile.Value().c_str());
    // Register Instruction to be called to instrument instructions
    INS_AddInstrumentFunction(Instruction, 0);
    // Register Fini to be called when the application exits
    PIN_AddFiniFunction(Fini, 0);

    // Start the program, never returns
    PIN_StartProgram();

    return 0;
}