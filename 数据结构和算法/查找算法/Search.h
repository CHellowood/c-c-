//#pragma once
#ifndef _SEARCH_H_
#define _SEARCH_H_

/*整数比较*/
int int_compare(const void* elem1, const void* elem2);

/*字符比较*/
int char_compare(const void* elem1, const void* elem2);

/*浮点数比较*/
int float_compare(const void* elem1, const void* elem2);

/*二分查找*/
int BinarySearch(void* array, int len, int elemSize, void* search, int (*compare)(const void* elem1, const void* elem2));

/*并行搜索*/
int ParallelSearch(void* array, int len, int elemSize, void* search, int (*compare)(const void* elem1, const void* elem2));

#endif 