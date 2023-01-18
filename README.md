# 设计模式学习代码（C++）



## 1. 工程目录结构

```bash
Project:.
├─bin               // 可执行文件及相关依赖
├─CMakeLists.txt
├─include           // 头文件，.h / .hpp
  ├─Behavior          // 行为型模式
  ├─Creational        // 创建型模式
  ├─Structural        // 结构型模式
├─main.cpp
└─src               // 源文件，.c / .cpp

// 本人环境：CLion + MinGW
```



## 2. 设计模式介绍

1. 创建型模式    include/Creational/
   1. 单例模式	singleton.hpp
   2. 工厂模式	factory.hpp
   3. 抽象工厂模式	factory.hpp
   4. 建造者模式	builder.hpp
   5. 原型模式	prototype.hpp
2. 结构型模式    include/Structural/
   1. 代理模式	proxy.hpp
   2. 桥接模式	bridge.hpp
   3. 装饰器模式	decorator.hpp
   4. 适配器模式	adapter.hpp
   5. 门面模式	facade.hpp
   6. 组合模式	composite.hpp
   7. 享元模式	flyweight.hpp
3. 行为型模式    include/Behavior/
   1. 观察者模式	observer.hpp
   2. 模板模式	template.hpp
   3. 策略模式	strategy.hpp
   4. 职责链模式	responsibility.hpp
   5. 状态模式	state.hpp
   6. 迭代器模式	iterator.hpp
   7. 访问者模式	visitor.hpp
   8. 备忘录模式	memento.hpp
   9. 命令模式	command.hpp
   10. 解释器模式	interpreter.hpp
   11. 中介模式	mediator.hpp

