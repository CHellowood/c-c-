//#pragma once
#ifndef _SEARCH_H_
#define _SEARCH_H_

/*�����Ƚ�*/
int int_compare(const void* elem1, const void* elem2);

/*�ַ��Ƚ�*/
int char_compare(const void* elem1, const void* elem2);

/*�������Ƚ�*/
int float_compare(const void* elem1, const void* elem2);

/*���ֲ���*/
int BinarySearch(void* array, int len, int elemSize, void* search, int (*compare)(const void* elem1, const void* elem2));

/*��������*/
int ParallelSearch(void* array, int len, int elemSize, void* search, int (*compare)(const void* elem1, const void* elem2));

#endif 