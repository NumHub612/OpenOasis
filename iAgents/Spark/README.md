<img src="../../Rsrc/Logo/logo.png" alt=""> 

---------------------------------------------------------------------------------

# 绿洲星火深度学习框架

*Spark model*  

基于 [tinynn](https://github.com/borgwang/tinynn) 等项目实现的一套极简的深度强化学习框架，主要用于理解和测试深度学习算法。  

**组件抽象 - 深度学习部分**

首先考虑神经网络运算的流程，神经网络运算主要包含训练 training 和预测 predict （或 inference） 两个阶段，训练的基本流程是：  
```
输入数据 -> 网络层前向传播 -> 计算损失 -> 网络层反向传播梯度 -> 更新参数  
```
预测的基本流程是：
```
输入数据 -> 网络层前向传播 -> 输出结果
```

从运算的角度可以分为三种类型的计算：

1. 数据在网络层之间的流动：前向传播和反向传播可以看做是张量 Tensor（多维数组）在网络层之间的流动（前向传播流动的是输入输出，反向传播流动的是梯度），每个网络层会进行一定的运算，然后将结果输入给下一层；
2. 计算损失：衔接前向和反向传播的中间过程，定义了模型的输出与真实值之间的差异，用来后续提供反向传播所需的信息；
3. 参数更新：使用计算得到的梯度对网络参数进行更新的一类计算。

基于这个三种类型，我们可以对网络的基本组件做一个抽象：

- tensor 张量，这个是神经网络中数据的基本单位；
- layer 网络层，负责接收上一层的输入，进行该层的运算，将结果输出给下一层，由于 tensor 的流动有前向和反向两个方向，因此对于每种类型网络层我们都需要同时实现 forward 和 backward 两种运算；
- loss 损失，在给定模型预测值与真实值之后，该组件输出损失值以及关于最后一层的梯度（用于梯度回传）；
- optimizer 优化器，负责使用梯度更新模型的参数。

然后我们还需要一些组件把上面这个 4 种基本组件整合到一起，形成一个 pipeline：

- net 组件负责管理 tensor 在 layers 之间的前向和反向传播，同时能提供获取参数、设置参数、获取梯度的接口；
- model 组件负责整合所有组件，形成整个 pipeline。即：
```
net 组件进行前向传播 -> losses 组件计算损失和梯度 -> net 组件将梯度反向传播 -> optimizer 组件将梯度更新到参数
```

**组件抽象 - 强化学习部分**

在强化学习中，智能体通过与环境的交互来学习策略，从而最大化自己在环境中所获得的奖励。强化学习的组件抽象采用 `OpenAi Gym` 的接口规范，具体包括：

- 环境（Env）：环境是模拟代理与外界交互的场景。它定义了状态空间、动作空间、奖励函数以及转移概率等。环境可以通过调用`reset`函数来初始化，并使用`step`函数来执行代理的动作，并返回下一个状态、奖励和是否终止等信息。

- 动作状态空间（Space）：动作空间定义了代理可执行的动作集合，状态空间定义了环境中所有可能的状态集合。空间可以是连续空间或离散空间。

- 智能体（Agent）：智能体（代理）是强化学习的学习者和决策者。它通过与环境交互，并根据当前状态选择最优的动作，以最大化长期累积奖励。

- 处理器（Processor）：处理器（或耦合器），当智能体输出的动作和环境观测的状态等不能直接识别时，可以通过该组件进行处理和连接。

此外，强化学习中非常重要的一项：

- 奖励函数（Reward Function）：奖励函数定义了在环境中代理执行特定动作后所获得的奖励值。奖励函数可以根据代理的行为，提供正向奖励或负向奖励，从而引导代理学习更好的策略。


---------------------------------------------------------------------------------

