- [Robotic Manipulation - Perception, Planning, and Control](#robotic-manipulation---perception-planning-and-control)
  - [Chapter 1: Introduction](#chapter-1-introduction)
    - [Manipulation is more than pick-and-place](#manipulation-is-more-than-pick-and-place)
    - [Open-world manipulation](#open-world-manipulation)
    - [Simulation](#simulation)
    - [Model-based design and analysis](#model-based-design-and-analysis)
    - [Exercises](#exercises)


# Robotic Manipulation - Perception, Planning, and Control

## Chapter 1: Introduction

### Manipulation is more than pick-and-place

以前的manipulation基本是抓取（grasp）或者pick-and-place的同义词，但如今的manipulation研究范围要广得多，涵盖了人手能够进行的各种操作。在具体的技术上也不局限于运动学动力学，而是融合了感知、规划、控制以及深度学习等各种技术。本课程讨论的是广义的manipulation。

### Open-world manipulation

真实世界有着无限的变化，我们不可能通过穷举的方式模拟出每一种可能性，这称为open-world或者open-domain问题。但好消息是我们正处在机器人大数据时代的黎明，这将会对机器人领域的研究带来不可估量的影响，比如避开奇异解、避免陷入局部最优解以及使控制优化变得更简单等。

### Simulation

曾几何时仿真在manipulation研究中是不太靠谱的，因为对感知系统和物体接触时的力学特征的模拟都是非常困难的。但随着技术的发展，如今的游戏引擎渲染器已经能够很好地模拟相机，以至于不仅能够在仿真环境中测试感知系统，甚至可以在其中训练感知系统，并且训练结果可以用于真实环境。接触模拟的质量和效率方面也已经有了长足的发展，尽管还有一些提升空间，但很多求解器已经非常好用，在研究中扮演着重要的作用

### Model-based design and analysis

### Exercises