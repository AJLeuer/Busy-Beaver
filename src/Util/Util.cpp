#include "Util.h"

using std::cerr;
using std::endl;

char32_t ConvertDigitToCircledSymbol(unsigned short digit)
{
	switch (digit)
	{
		case 0:
			return u'⓪';
		case 1:
			return u'①';
		case 2:
			return u'②';
		case 3:
			return u'③';
		case 4:
			return u'④';
		case 5:
			return u'⑤';
		case 6:
			return u'⑥';
		case 7:
			return u'⑦';
		case 8:
			return u'⑧';
		case 9:
			return u'⑨';
		default:
			cerr << "Argument to ConvertDigitToCircledSymbol() must be single digit between 0 and 9" << endl;
			throw std::exception();
	}
}

char32_t ConvertDigitToCircledSymbol(char digit)
{
	//unsigned short digitInt = UInt16.Parse(digit.ToString());
	//unsigned short digitInt = std::from_chars()

	//return ConvertDigitToCircledSymbol(digitInt);
	return '0';
}
