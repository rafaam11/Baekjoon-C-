#pragma once

#ifdef DYNAMIC_EXPORTS
#	define DYNAMIC_DECLSPEC __declspec(dllexport)
#else
#	define DYNAMIC_DECLSPEC __declspec(dllimport)
#endif


DYNAMIC_DECLSPEC double Subtract(double a, double b);


