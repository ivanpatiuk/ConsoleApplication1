#include "TextLoader.h"
#include <string>
#include <iostream>

using namespace std;

ifstream TextLoader::openText(int text_number) {
	switch (text_number) {
	case 1:
		return ifstream("batkivshchyna.txt");
	case 2:
		return ifstream("blakyt.txt");
	case 3:
		return ifstream("contra_spem_spero.txt");
	case 4:
		return ifstream("malenka_vkrayinochka.txt");
	case 5:
		return ifstream("reve_ta_stohne.txt");
	case 6:
		return ifstream("zapovit.txt");
	case 7:
		return ifstream("zhyttya");
	case 8:
		return ifstream("zhyttya_ne_boyusya");
	}
}
