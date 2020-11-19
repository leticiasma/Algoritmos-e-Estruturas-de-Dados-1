#include "funcaoex1.h"

int fatorial (int x){
	int  fat = x;
	int i = fat;
	if (x != 0){
		while (i > 1){
			i --;
			fat *= i;
		}
		return fat;
	}
	else return 1;
}