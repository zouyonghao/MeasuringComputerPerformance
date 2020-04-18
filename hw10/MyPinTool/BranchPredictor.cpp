#include "pin.H"
#include <map>
#include <iostream>

struct BP_Info
{
    bool Taken = false;
    ADDRINT predTarget = 0;
    int takenCount = 0;
};

class BranchPredictor
{
private:
    std::map<ADDRINT, struct BP_Info> predictMap;

public:
    BP_Info GetPrediction(ADDRINT PC)
    {
        BP_Info result;
        result.Taken = false;
        result.predTarget = -1;
        result.predTarget = predictMap[PC].predTarget;
        if (predictMap[PC].takenCount > 1)
        {
            result.Taken = true;
        }
        return result;
    }

    void Update(ADDRINT PC, bool BrTaken, ADDRINT targetPC)
    {
        if (predictMap[PC].predTarget != 0)
        {
            // std::cout << "predict exist" << std::endl;
            BP_Info pred = predictMap[PC];
            // std::cout << "update " << pred.Taken << ", " << pred.takenCount << std::endl;
            // std::cout << "target " << pred.predTarget << ", " << targetPC << std::endl;
            // taken
            if (pred.predTarget == targetPC && BrTaken)
            {
                if (pred.takenCount < 4)
                {
                    pred.takenCount++;
                }
            }
            else
            {
                if (pred.takenCount > 0)
                {
                    pred.takenCount--;
                }
                else
                {
                    // 这里加了一点逻辑，如果takenCount为0，且预测地址跟实际地址不匹配
                    // 则更新跳转地址，实际测试可以提高一点点准确率
                    pred.predTarget = targetPC;
                }
            }
        }
        else
        {
            // std::cout << "predict not exist" << std::endl;
            BP_Info newInfo;
            newInfo.predTarget = targetPC;
            if (BrTaken)
            {
                newInfo.takenCount = 3;
            }
            else
            {
                newInfo.takenCount = 0;
            }
            predictMap[PC] = newInfo;
            // std::cout << "add new: " << targetPC << ", " << predictMap[PC].takenCount << std::endl;
        }
    }
};