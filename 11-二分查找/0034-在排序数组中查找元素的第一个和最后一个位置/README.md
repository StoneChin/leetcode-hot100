# 34. 在排序数组中查找元素的第一个和最后一个位置

[力扣原题](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/) · 中等 · [本类目录](../README.md) · [总目录](../../README.md)

## 要解决什么

在非递减数组中返回 target 的第一个与最后一个下标。

## 怎么想到这个方法

**二分左右边界**

先找第一个 >=target 的位置 first，再找第一个 >target 的位置 after。若 first 越界或不是 target，说明目标不存在；否则区间为 [first,after-1]。两个二分只在相等时的处理不同，一个把相等归右边界，一个把相等归左边界。

## 跟着例子走一遍

[5,7,7,8,8,10] 查 8，第一个 >=8 的下标为 3，第一个 >8 的下标为 5，答案为 [3,4]。

## 写代码时注意什么

不要通过查 target+1 来寻找右边界，target 为 INT_MAX 时会溢出。直接比较 >target 可以避免这个问题。不存在时返回 [-1,-1]。

## 复杂度

- 时间：O(log n)。
- 空间：O(1)。

## C++17 解法

查看 [solution.cpp](solution.cpp)。关键步骤的注释写在对应代码旁，方法中的变量名也与实现保持一致。节点类型由力扣提供；本地验证方式见项目首页。
