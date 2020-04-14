#include <stdio.h>
#include <stdlib.h>
#include "Book.h"
#include "SellBook.h"

int main(void) {
	Book book("C���Դ����ŵ���ͨ(��3��)", 59.80, "978-7-302-45778-7");
	SellBook sbook("C++�����ŵ���ͨ(��3��)", 64.8, "978-7-302-45778-8");
	
	sbook.setDiscount(8.4);

	printf_s("����: %s\n���: %s\n�۸�: %.2f\n\n", book.getTitle().c_str(), book.getISBN().c_str(), book.getPrice());
	printf_s("����: %s\n���: %s\n�۸�(%.1f��): %.2f\n\n", sbook.getTitle().c_str(), sbook.getISBN().c_str(), sbook.getDiscount(), sbook.getPrice());

	system("pause");
	return 0;
}