#include <stdio.h>
#include <stdlib.h>
#include "Book.h"
#include "SellBook.h"

int main(void) {
	Book book("C语言从入门到精通(第3版)", 59.80, "978-7-302-45778-7");
	SellBook sbook("C++从入门到精通(第3版)", 64.8, "978-7-302-45778-8");
	
	sbook.setDiscount(8.4);

	printf_s("书名: %s\n书号: %s\n价格: %.2f\n\n", book.getTitle().c_str(), book.getISBN().c_str(), book.getPrice());
	printf_s("书名: %s\n书号: %s\n价格(%.1f折): %.2f\n\n", sbook.getTitle().c_str(), sbook.getISBN().c_str(), sbook.getDiscount(), sbook.getPrice());

	system("pause");
	return 0;
}