# SPEC CPU 2006调研

## 邹永浩

## 2019211168

### 性能指标

SPEC 主要测试 CPU 的整数和浮点数运算，即 SPECint 和 SPECfp。其中 SPECint2006 包含12个不同的基准测试和 SPECfp2006 包含19个不同的基准测试，如下图所示：

![image-20200310203053795](C:\Users\Administrator\Desktop\1.png)

### Case

| #    | Hardware Vendor | System                                                | Result | Baseline | Cores | Chips | Cores Per Chip | Published |
| ---- | --------------- | ----------------------------------------------------- | ------ | -------- | ----- | ----- | -------------- | --------- |
| 1    | ACTION S.A.     | ACTINA SOLAR 110 S6 (Intel Xeon E3-1220 v3, 3.10 GHz) | 58.7   | 56.9     | 4     | 1     | 4              | Dec-2015  |
| 2    | ACTION S.A.     | ACTINA SOLAR 202 S6 (Intel Xeon E5-2697 v3, 2.60 GHz) | 67.5   | 64.4     | 28    | 2     | 14             | Dec-2015  |



可以看到，该测试中，1号频率为3.10G，2号频率为2.60G，但2号得分较高。可能原因为CPU的架构和核数等原因，频率并不是唯一指标。

但是比较详细指标，如下图所示，

1号机器：

![image-20200310225007238](C:\Users\Administrator\Desktop\2.png)



2号机器：

![image-20200310225037239](C:\Users\Administrator\Desktop\3.png)



可以看到，虽然整体分数2号更高，但有些指标如bzip2，gcc，mcf，sjeng等程序，1号更胜一筹。