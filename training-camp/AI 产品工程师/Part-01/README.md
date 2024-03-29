# 第 1 部分｜提示词工程 - Prompt Engineering

## 本节作业

- 搭建自己的作品集
- 搭建 Python 开发环境 & 准备/申请 AI 大模型 API（eg: OpenAI API）
- 结合自己的工作内容，写一份 Prompt

## 本节总结

### 单一提示词

AIGC 工具有其局限性（模型知识量很庞大 / 模型训练数据的侧重点 / 根据输入内容发散检索等），在使用 Prompt（提示词）的情况下，能更好的引导 AI 输出相对更符合期望（范围/方向/格式等）的内容。

<!-- 示例 -->

### 提示词工程

满足特定任务，像是代码编写、研究型等追求 AI 输出内容缜密且准确的场景时，提示词可能需要演变为提示词工程，从背景、角色扮演、输入格式、输出格式等角度，以类似有限状态机的方式，编写适合任务的提示词。

提示词不是编写后就不需要修改，也不是越复杂越好，要做到工程化（AI 模型选型、提示词设计、性能评估等），需要根据实际任务、用户需求、AI 模型特点或局限，不断优化和改进。

<!-- 示例 -->

### 提示词的挑战

- 数据安全
- 数据隐私
- 内容准确
- 文化风俗
- 政治敏感
- ...

### 提示词的编写

- 重要文本的重新定义，使用分隔符（`{content}` / """{content}""" / <{content}>
- 提供详细的背景信息（类似前情提要）
- 制定输出内容的格式（必备的内容、可选的内容、内容长度、排版等）
- 引用外部示例，让 AI 仿写
- 提示词模板化，将提示词中的可变内容提取为变量，后续只填写变量部分即可，可以用表单、JSON 等形式输入，封装为小的 AIGC 产品。
- 晓之以理动之以情，为提升内容输出质量，可以给予 AI 情绪上的正反馈、或者小费以“犒劳”

<!-- TODO -->